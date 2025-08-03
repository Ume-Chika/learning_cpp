# CMakeの最小バージョンを指定
cmake_minimum_required(VERSION 3.10)

# プロジェクト名を指定
project(ImageDisplay)

# OpenCVパッケージを探す
find_package(OpenCV REQUIRED)

# OpenCVのインクルードディレクトリを追加
include_directories(${OpenCV_INCLUDE_DIRS})

# 実行可能ファイルを作成
# ここに ImageProcessor.cpp を追加する！
add_executable(image_display main.cpp ImageProcessor.cpp)

# 実行可能ファイルにOpenCVライブラリをリンクする
target_link_libraries(image_display ${OpenCV_LIBS})