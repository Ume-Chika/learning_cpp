// ImageProcessor.h

#pragma once // ヘッダーが複数回インクルードされるのを防ぐおまじない

#include <string>
#include <opencv2/opencv.hpp>

class ImageProcessor {
public:
    // コンストラクタ：ウィンドウ名を指定して初期化
    ImageProcessor(const std::string& window_name);

    // 画像を読み込む関数
    bool loadImage(const std::string& file_path);

    // 画像を表示してキー入力を待つ関数
    void showImage();

private:
    std::string win_name; // ウィンドウ名
    cv::Mat image_data;   // 画像データ
};