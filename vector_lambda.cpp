#include <iostream>
#include <vector>
#include <random>   // 乱数生成に必要
#include <limits>   // 数値の最大値を取得するために使用

std::vector<int> create_random_vector(int count, int max_value) {
    // 1. 乱数生成の準備
    static std::random_device seed_gen;  // ①
    static std::mt19937 engine(seed_gen());  // ②
    std::uniform_int_distribution<int> dist(1, max_value);  // ③
    /*「C++での乱数生成について」
    Pythonのnp.randint()はユーザーの利便性重視で色々隠されてる
        ↔️C++は全て自分で設定・カスタマイズする必要がある。
    乱数生成までの道のり
        ① ハードウェアから真のランダムシードを得る
            時間から得る方法は旧時代的C++11以前の方法
            ハードウェアから取る方法は割とどんな環境でも動作、C++11以降の方法
        ② 使用する乱数生成エンジンを設定
            mt19937：メルセンヌ・ツイスターと呼ばれる標準的なやつ
            他のやつは超特殊なケースでなければ使わない
        ③ 一様分布を設定
            乱数生成エンジンの生成する文字を範囲内に変換する変換装置
            偏りがなく公平に変換される
    */

    /*「関数内でのstaticについて」
    static：関数が呼び出される1回目でのみ初期化、以降は使いまわされる
        ちょっとでも負荷軽減
    */

    // 2. 結果を格納するベクトルを準備
    std::vector<int> vec;
    vec.reserve(count); // 事前にメモリを確保して効率化

    // 3. 指定された数だけ乱数を生成してベクトルに追加
    for (int i = 0; i < count; ++i) {
        vec.push_back(dist(engine)); // 乱数を生成
    }

    return vec;
}

void print_vector(const std::vector<int>& v) {
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    // 10個の、1から100までの乱数を生成
    int num_elements = 10;
    int max_val = 100;
    std::vector<int> random_numbers = create_random_vector(num_elements, max_val);

    std::cout << "original vector: ";
    print_vector(random_numbers);
    std::cout << std::endl;

    std::cout << "2x vector";
    std::vector<int> double_numbers;
    double_numbers.reserve(random_numbers.size());
    std::transform(random_numbers.begin(), random_numbers.end(), double_numbers.begin(), [](int x) {
        return x * 2;
    });

    return 0;
}