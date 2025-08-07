#include <iostream>
#include <opencv2/opencv.hpp>

#include <thread>   // std::this_thread::sleep_for のために必要
#include <chrono>   // std::chrono::milliseconds などの時間単位のために必要

bool try_cap (cv::VideoCapture& cap, cv::Mat& frame) {
    // カメラの起動を1秒間待って、空でないフレームを取得できたかを返す。
    int empty_fream_count = 0;
    const int max_empty_fream = 100; // 10 ms * max_empty_fream 待機
    while (frame.empty() && empty_fream_count < 100){
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout << "空のフレームを取得（" << empty_fream_count << "回目）" << std::endl;
        cap >> frame;
        empty_fream_count++;
    }
    return !frame.empty();
}

// GStreamerのパイプライン文字列を生成する関数
std::string gstreamer_pipeline_for_libcamera(int camera_index, int width, int height, int framerate) {
    return "libcamerasrc camera-name=imx708 ! video/x-raw,width=" + std::to_string(width) +
           ",height=" + std::to_string(height) +
           ",format=NV12,framerate=" + std::to_string(framerate) + "/1 ! videoconvert ! video/x-raw,format=BGR ! appsink drop=1";
}

int main(int argc, char** argv) {
    // 1. カメラを開く
    // 複数のカメラが接続されている場合は、1, 2, ... と数字を変えて試します。
    cv::VideoCapture cap;
    int target_camera = 0;
    if (argc > 1) {
        try {
            target_camera = std::stoi(argv[1]);
        } catch (const std::exception& e) {
            std::cerr << "エラー: カメラインデックスが不正です。" << std::endl;
            return -1;
        }
    }
    cap.open(target_camera);

    // カメラが正常に開けたかを確認
    if (!cap.isOpened()) {
        std::cerr << "エラー: カメラを開けませんでした。" << std::endl;
        return -1;
    }

    // 2. フレームを格納するためのMatオブジェクトを準備
    cv::Mat frame;

    // 2.5 カメラの起動テスト & libcamera用のパイプラインを試す
    if (!try_cap(cap, frame)) {
        std::cerr << "エラー: カメラからフレームを取得できませんでした。" << std::endl;

        std::cerr << "libcamera用のパイプラインを試します" << std::endl;
        cap.release(); // カメラデバイスを解放
        std::string pipeline = gstreamer_pipeline_for_libcamera(target_camera, 1280, 720, 30);
        std::cout << "使用するパイプライン" << pipeline << std::endl;
        setenv("GST_DEBUG", "3", 1);
        cap.open(pipeline, cv::CAP_GSTREAMER);
        if (!cap.isOpened()) {
            std::cerr << "エラー: libcamera用のパイプラインでカメラを開けませんでした。" << std::endl;
            return -1;
        } else {
            std::cout << "libcamera用のパイプラインでカメラを開きました。" << std::endl;
            if (!try_cap(cap, frame)) {
                std::cerr << "エラー: カメラからフレームを取得できませんでした。" << std::endl;
                return -1;
            }
        }
    }

    // 3. 無限ループでカメラ映像を取得し続ける
    while (true) {
        // カメラから新しいフレームを1枚キャプチャする
        cap >> frame; // cap.read(frame) と同じ意味

        if (frame.empty()) { // フレームが空の場合の処理
            std::cerr << "エラー: 空のフレームを受信しました。" << std::endl;
            break; // ループから脱出
        }

        // 4. "Live Camera" という名前のウィンドウにフレームを表示
        cv::imshow("Live Camera", frame);

        // 5. キー入力を1ミリ秒待つ
        // 'q'キーが押されたらループを抜ける
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }

    // 6. 後片付け
    cap.release(); // カメラデバイスを解放
    cv::destroyAllWindows(); // 全てのOpenCVウィンドウを閉じる

    return 0;
}