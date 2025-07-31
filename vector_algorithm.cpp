#include <iostream>
#include <vector>
#include <algorithm> // sortを使うために必要
#include <functional> // greaterを使うために必要

void print_vector(const std::vector<int>& v) {
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    // 1. ソートしたいvectorを用意する
    std::vector<int> numbers = {5, 2, 8, 1, 9, 4};
    std::cout << "ソート前: ";
    print_vector(numbers);

    // 2. std::sortを呼び出す（昇順）
    // numbers.begin() : ソートの開始位置 (先頭)
    // numbers.end()   : ソートの終了位置 (末尾の次)
    std::sort(numbers.begin(), numbers.end());
    std::cout << "昇順ソート後: ";
    print_vector(numbers);

    // 3. 降順でソート
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());
    std::cout << "降順ソート後: ";
    print_vector(numbers);

    // 4. ラムダ式でソート（偶数が先、昇順）
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        if (a % 2 == 0 && b % 2 != 0) {
            return true;
        }
        else if (a % 2 != 0 && b % 2 == 0) {
            return false;
        }
        else {
            return a < b;
        }
    });
    /*「ラムダ式」とは
    1回きりしか使わない名もなき関数を定義する方法
    まず、sortの引数について再確認
        std::sort(ソートの開始位置, ソートの終了位置, ソートに使用する関数)
        この「ソートに使用する関数＝評価式」をラムダ式で定義している。
    ラムダ式の書き方
        [](引数群){結果をreturnするところ}
        ソートの場合は[](引数2つ){true or false}の形で作ればOK
    */
    std::cout << "偶数が先、昇順ソート後: ";
    print_vector(numbers);

    return 0;
}