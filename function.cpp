#include <string>
#include <iostream>

// 2つの整数を足し算する関数
int add(int a, int b) {
    int sum = a + b;
    return sum; // 計算結果を返す
}

std::string getListText(int a_list[], int size) {
    std::string text = "[";
    for (int i = 0; i < size; i++) {
        // まずstd::to_string()で数値を文字列に変換する
        text += std::to_string(a_list[i]);

        // 最後の要素でなければ、カンマとスペースを追加する
        if (i < size - 1) {
            text += ", ";
        }
    }
    text += "]";
    return text;
}

#include <sstream> // stringstreamを使うために必要
std::string getListText2(int a_list[], int size) {
    // stringstreamオブジェクトを作成
    std::stringstream ss;

    ss << "[";
    for (int i = 0; i < size; i++) {
        // 数値を直接ストリームに入れる
        ss << a_list[i];

        // 最後の要素でなければ、カンマとスペースを追加
        if (i < size - 1) {
            ss << ", ";
        }
    }
    ss << "]";

    // .str() で完成した文字列を取り出して返す
    return ss.str();
}

int sum(int a_list[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += a_list[i];
    }
    return sum;
}

int main() {
    int result = add(5, 3); // add関数を呼び出し、結果をresultに格納
    std::cout << "5 + 3 = " << result << std::endl;

    int result2 = add(100, 200);
    std::cout << "100 + 200 = " << result2 << std::endl;

    int inputA;
    int inputB;

    std::cout << "inputA: ";
    std::cin >> inputA;
    std::cout << "inputB: ";
    std::cin >> inputB;

    int result3 = add(inputA, inputB);

    std::cout << inputA << " + " << inputB << " = " << result3 << std::endl;

    int listA[5] = {21, 134, 43, 2, 43};
    std::cout << "sum of " << getListText(listA, 5) << " is " << sum(listA, 5) << std::endl;

    int listB[3] = {0, 0 ,0};
    for (int i = 0; i < 3; i++) {
        std::cout << "input" << i << ": ";
        std::cin >> listB[i];
    }
    std::cout << "sum of " << getListText2(listB, 3) << " is " << sum(listB, 3) << std::endl;

    return 0;
}