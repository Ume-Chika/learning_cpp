#include "ImageProcessor.h" // 対応するヘッダーをインクルード
#include <iostream>

/* 宣言と定義の分離②
cppファイルでは定義を！
    「スコープ解決演算子」を使用する
        この関数がどのくらずに所属しているかを明示する
    いつも通り、引数、処理内容、returnを書けばいい
*/

// コンストラクタの実装
/* メンバ初期化リストを使用
目的：コンストラクタの本体{}が実行される前に、メンバ変数を効率的に初期化する方法
    通常、window_nameという変数にコピーされ、それをwin_nameにコピーするという運び
    メンバ初期化リストを使うと引数を直にwin_nameにぶちこめる → 早い！変な型であればなお早い！
*/
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