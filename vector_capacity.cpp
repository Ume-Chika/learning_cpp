#include <iostream>
#include <vector>

void print_status(const std::vector<int>& v) {
    /*
    要素数sizeと容量capacityの関係
        size：現在使ってる領域長さ
        capacity：確保済みの領域の長さ

        size > capacityになると領域の再確保（引っ越し）が発生！状況によって恐ろしいコストを支払うことに！
        特にstringやオリジナルの型はなお領域の再確保を警戒すべし
            intやdoubleなどの型：要素の「ムーブ（ポインタの引き渡し）」によって引っ越しコストを減らす処理が対応
            stringなど：コピーが発生
    */
    std::cout << "要素数 (size): " << v.size() << ", ";
    std::cout << "容量 (capacity): " << v.capacity() << std::endl;
}

int main() {
    std::cout << "--- reserveなし ---" << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
        std::cout << "push_back(" << i << "): ";
        print_status(vec);
    }
    std::cout << std::endl;

    std::cout << "--- reserveあり ---" << std::endl;
    std::vector<int> vec_reserve;
    vec_reserve.reserve(10);
    // reserveで10個分のメモリを確保しておくと、領域の再確保が発生しない
    for (int i = 0; i < 10; ++i) {
        vec_reserve.push_back(i);
        std::cout << "push_back(" << i << "): ";
        print_status(vec_reserve);
    }
    /*「ゼロコスト抽象化」の思想
    このvectorのcapacityはC++のゼロコスト抽象化を体現してる。
    あらゆるところで「手動での最適化」が可能になっている
    */
    return 0;
}