// main.cpp

#include "ImageProcessor.h" // 作成したクラスのヘッダーをインクルード
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        // argv[0]には「./実行ファイルパス」が入るはず
        // argc == 2 の時が正常で「./実行ファイルパス 画像ファイルパス」となるはず
        std::cerr << "使い方: " << argv[0] << " <画像ファイルのパス>" << std::endl;
        return -1;
    }

    // 1. ImageProcessorオブジェクトを作成
    ImageProcessor processor("Display Image");

    // 2. 画像を読み込む
    if (processor.loadImage(argv[1])) {
        // 3. 成功したら画像を表示
        processor.showImage();
    } else {
        std::cerr << "処理を中断します。" << std::endl;
        return -1;
    }

    std::cout << "プログラムを終了します。" << std::endl;
    return 0;
}