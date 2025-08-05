# CMakeの最低要求バージョン
cmake_minimum_required(VERSION 3.10)

# プロジェクト名を設定
project(CameraTest)

# C++の標準を設定 (C++11以上を推奨)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# OpenCVパッケージを探す (必須コンポーネントとしてcoreとhighgui)
# highguiはimshow, waitKeyなどGUI関連の機能を含みます
find_package(OpenCV REQUIRED COMPONENTS core highgui videoio)

# OpenCVのインクルードディレクトリを追加
include_directories(${OpenCV_INCLUDE_DIRS})

# 実行ファイルを作成
add_executable(camera_app main.cpp)

# 実行ファイルにOpenCVライブラリをリンク
target_link_libraries(camera_app ${OpenCV_LIBS})