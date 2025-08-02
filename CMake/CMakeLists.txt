# --- 1. CMakeの最低バージョン指定 ---
# この設定ファイルを書くために必要なCMakeのバージョンを指定します。
# これより古いCMakeではエラーになります。3.10あたりが一般的です。
cmake_minimum_required(VERSION 3.10)

# --- 2. プロジェクト名の定義 ---
# プロジェクトの名前を決めます。何でもOKです。
project(MyMultiFileProject CXX)

# --- 3. 実行ファイルの生成 ---
# どのソースファイルから、何という名前の実行ファイルを作るかを指定します。
# add_executable( [実行ファイル名] [ソースファイル1] [ソースファイル2] ... )
# ヘッダーファイル(.h)は含めなくてOKです。
add_executable(my_app main.cpp sub.cpp)