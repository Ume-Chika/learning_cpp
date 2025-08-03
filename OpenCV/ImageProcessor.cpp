#include "ImageProcessor.h" // 対応するヘッダーをインクルード
#include <iostream>

// コンストラクタの実装
ImageProcessor::ImageProcessor(const std::string& window_name) : win_name(window_name) {
    // 初期化リストを使ってメンバ変数を初期化
}

// loadImage関数の実装
bool ImageProcessor::loadImage(const std::string& file_path) {
    image_data = cv::imread(file_path, cv::IMREAD_COLOR);
    if (image_data.empty()) {
        std::cerr << "エラー: 画像を読み込めませんでした: " << file_path << std::endl;
        return false;
    }
    return true;
}

// showImage関数の実装
void ImageProcessor::showImage() {
    if (image_data.empty()) {
        std::cerr << "エラー: 表示する画像データがありません。" << std::endl;
        return;
    }
    cv::imshow(win_name, image_data);
    std::cout << "画像が表示されました。何かキーを押すと終了します..." << std::endl;
    cv::waitKey(0);
    cv::destroyAllWindows();
}