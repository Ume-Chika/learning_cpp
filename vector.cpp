#include <iostream>
#include <vector>
#include <string>

void showVector(const std::vector<std::string>& svector) {
    if (svector.empty()) { // vectorが空の場合の処理
        return;
    }
    for (int i = 0; i < svector.size(); ++i) {
        std::cout << svector[i];
        if (i < svector.size() - 1) { // 最後の要素でなければカンマを出力
            std::cout << ", ";
        }
    }
    std::cout << std::endl; // 最後に改行
}

int main() {
    std::vector<std::string> fruits = {"Apple", "Banana", "Cherry"};

    // vectorの各要素が、ループごとに変数fruitにコピーされて使われる
    // 「範囲ベース」のfor文の書き方。pythonのfor item in list:のような挙動
    for (const auto& fruit : fruits) {
        std::cout << fruit << std::endl;
    }
    std::cout << std::endl;

    // 従来のスタイルも可能
    for (int i = 0; i < fruits.size(); i++) {
        std::cout << fruits[i] << "の文字数は" << fruits[i].size() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "末尾のフルーツの削除" << std::endl;
    fruits.pop_back();
    showVector(fruits);

    std::string add_fruits;
    std::cout << "新しいフルーツを追加: ";
    std::cin >> add_fruits;
    fruits.push_back(add_fruits);
    showVector(fruits);

    std::cout << "先頭から2番めのフルーツの削除" << std::endl;
    fruits.erase(fruits.begin() + 1);
    showVector(fruits);
    std::cout << std::endl;

    // vectorの各要素へのアクセス
    // 従来のスタイル。範囲外にアクセスしてもエラーが出ない。想定外の挙動をする。
    // 高速。だが危険。絶対的な自信があるときかどうしてもパフォーマンスが必要ならこっちを使う。
    std::cout << "👇fruits[5]にアクセスした結果" << std::endl;
    std::cout << fruits[5] << std::endl;
    // vectorで推奨のスタイル。範囲外にアクセスするとエラーが出て止まる。
    std::cout << "👇fruits.at(5)にアクセスした結果" << std::endl;
    std::cout << fruits.at(5) << std::endl;

    std::cout << "エラーで止まるため、これは出力されない" << std::endl;
    /*
    next -> vector応用編
        メモリのキャパシティ・再確保について
        <algorithm>でのサーチやソートについて
    */

    return 0;
}