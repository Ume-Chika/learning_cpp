#include <iostream>
#include <string>

int main() {
    bool flg = true;
    while (flg) {
        // 入力された年齢をしまうための「変数」を用意
        int age;

        // ユーザーに入力を促すメッセージを表示
        std::cout << "あなたの年齢を入力してください: ";
        // pythonと違い文字列は必ずダブルクオーテーション！！

        // キーボードからの入力を変数ageに格納する
        std::cin >> age;

        // 受け取った情報を使ってメッセージを表示
        std::cout << ((age != -1) ? "なるほど、" + std::to_string(age) + "歳なのですね。\n" : "");
        // Cでの３項演算子
        // (条件文) ? A : B
        // 条件分がtrueならA、falseならBを返す。

        // std::endl と \n の違い
        // std::endl は改行＋出力バッファの強制フラッシュ
        // 強制フラッシュはたくさんすると重い

        if (age >= 75){
            std::cout << "あなたは後期高齢者" << std::endl;
        }

        switch (age){
            case 22:
                std::cout << "同い年ですね" << std::endl;
                break;
            case 58:
                std::cout << "木津川先生と同い年ですね" << std::endl;
                break;
            case -1:
                flg = false;
                break;
        }

    }
    return 0;
}