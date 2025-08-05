#include <iostream>
#include <opencv2/opencv.hpp>

#include <thread>   // std::this_thread::sleep_for のために必要
#include <chrono>   // std::chrono::milliseconds などの時間単位のために必要

int main(int argc, char** argv) {
    // 1. カメラを開く
    // 複数のカメラが接続されている場合は、1, 2, ... と数字を変えて試します。
    cv::VideoCapture cap;
    if (argc == 1) {
        // 指定がなければデフォルトカメラを使用
        cap.open(0);
    } else if (argc != 1) {
        // 指定があればそれを使用
        try {
            cap.open(std::stoi(argv[1]));
        } catch (const std::exception& e) {
            std::cerr << "エラーが発生：" << e.what() << std::endl;
            return -1;
        }
    }

    // カメラが正常に開けたかを確認
    if (!cap.isOpened()) {
        std::cerr << "エラー: カメラを開けませんでした。" << std::endl;
        return -1;
    }

    // 2. フレームを格納するためのMatオブジェクトを準備
    cv::Mat frame;
    int empty_fream_count = 0; // カメラの起動まで見逃す回数

    // 3. 無限ループでカメラ映像を取得し続ける
    while (true) {
        // カメラから新しいフレームを1枚キャプチャする
        cap >> frame; // cap.read(frame) と同じ意味


        if (frame.empty()) { // フレームが空の場合の処理
            std::cerr << "エラー: 空のフレームを受信しました。" << std::endl;

            if (empty_fream_count > 100) {
                std::cerr << "エラー：フレームを連続で取得できませんでした" << std::endl;
                break; // ループから脱出
            }
            empty_fream_count++;
            std::this_thread::sleep_for(std::chrono::milliseconds(10)); // 10ミリ秒待機
            continue; // 先頭へ戻る
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