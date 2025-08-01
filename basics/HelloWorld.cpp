#include <iostream>
#include <stdio.h>

int main() {
    // コンソールに "Hello, World!" と出力します
    std::cout << "Hello, World!" << std::endl; // 競プロで使う書き方, iostream版
    // endl = 改行 みたいな感じ。endlがなくても動く
    printf("Hello, World!!\n"); // C言語っぽい書き方

    for(int i = 0; i < 100; i++){
        int a = 1 << i;
        std::cout << i << "のとき" << a << std::endl;
    }
    

    return 0;
}