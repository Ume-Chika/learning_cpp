#include <iostream>
#include <string>

// 団体の情報表す構造体の定義
struct GroupInfo {
    int index;
    int member_count;
    std::string leader_name;
    std::string sub_learder_name;
    std::string group_name;
};

int main() {
    // 構造体の変数（インスタンス）を作成
    GroupInfo group1;

    // メンバに値を代入 (ドット . を使ってアクセス)
    group1.index = 1;
    group1.member_count = 5;
    group1.leader_name = "Chikara";
    group1.sub_learder_name = "Umeda";
    group1.group_name = "Group UmeChi";

    // メンバの値を表示
    std::cout << "group1 index: " << group1.index << std::endl;
    std::cout << "group1 leader_name: " << group1.leader_name << std::endl;
    std::cout << std::endl;

    // 初期化子リストを使って、作成と同時に初期化も可能
    GroupInfo group2 = {2, 10, "Ishida", "Kondou", "Group IshiKon"};
    std::cout << "group2 index: " << group2.index << std::endl;
    std::cout << "group2 leader_name: " << group2.leader_name << std::endl;

    return 0;
}