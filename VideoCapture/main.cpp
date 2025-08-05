#include <iostream>
#include <opencv2/opencv.hpp>

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

    // 3. 無限ループでカメラ映像を取得し続ける
    while (true) {
        // カメラから新しいフレームを1枚キャプチャする
        cap >> frame; // cap.read(frame) と同じ意味

        // フレームが空の場合はループを抜ける (映像の終端など)
        if (frame.empty()) {
            std::cerr << "エラー: 空のフレームを受信しました。" << std::endl;
            break;
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