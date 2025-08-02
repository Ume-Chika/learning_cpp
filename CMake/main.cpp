// main.cpp
#include <iostream>
#include "sub.h" // 自作したヘッダーファイルを読み込む

int main() {
    std::cout << "Main file says hello!" << std::endl;
    print_message(); // sub.cppで定義した関数を呼び出す
    return 0;
}