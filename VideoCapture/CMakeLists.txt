# CMakeの最低要求バージョン
cmake_minimum_required(VERSION 3.10)

# プロジェクト名を設定
project(CameraTest)

# C++の標準を設定
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# OpenCVパッケージを探す
find_package(OpenCV REQUIRED COMPONENTS core highgui videoio)

# GStreamerパッケージを探す
find_package(PkgConfig REQUIRED)
pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0 gstreamer-video-1.0)

# インクルードディレクトリを追加
include_directories(${OpenCV_INCLUDE_DIRS} ${GSTREAMER_INCLUDE_DIRS})

# 実行ファイルを作成
add_executable(camera_app main.cpp)

# 実行ファイルにOpenCVとGStreamerライブラリをリンク
target_link_libraries(camera_app ${OpenCV_LIBS} ${GSTREAMER_LIBRARIES})