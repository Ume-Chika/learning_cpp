#include <iostream>
#include <string>

// 団体の情報表す構造体の定義
struct GroupInfo {
    // C++11以降：デフォルト値の設定が可能（今回はコンストラクタで上書きされてしまう）
    int member_count = 4;
    std::string leader_first_name = "Not Set";
    std::string learder_last_name = "Not Set";
    std::string group_name = "Not Set";

    // C++11以降：コンストラクタの設定が可能（引数の設定も可）
    // コンストラクタ＝初期化専用関数
    GroupInfo(int n = 4, std::string fn = "Not Set", std::string ln = "Not Set", std::string gn = "Not Set") {
        member_count = n;
        leader_first_name = fn;
        learder_last_name = ln;
        group_name = gn;
    };

    // 何と関数（メンバ関数）も持てる
    std::string leader_full_name() {
        return leader_first_name + " " + learder_last_name;
    }
};

int main() {
    /* C++20以降：部分的に初期値を設定可能（コンストラクタがない場合）
    // ①集成体初期化 (指定された初期化子)
    GroupInfo group1 = {
        .leader_first_name = "Chikara", 
        .learder_last_name = "Umeda", 
        .group_name = "Group UmeChi"
    };
    */

    // コンストラクタが存在数場合はこう
    // ②コンストラクタ呼び出し
    GroupInfo group1(5, "Chikara", "Umeda", "Group UmeChi");

    /* コンストラクタ呼び出しの注意点
    // pythonや①の集成体初期化のように好きな引数だけは不可。
    // コンストラクタは基本的に前から詰めて代入される。それ以外は不可。
    GroupInfo group2(
        fn = "Chikara", 
        ln = "Umeda", 
        gn ="Group UmeChi"
    );
    */
    GroupInfo group2; // OK
    GroupInfo group3(3); // これもOK

    // 関数も使えちゃう
    std::cout << group1.leader_full_name() << std::endl;

    /* 構造体はほぼクラス
    異なる点は1点のみ
        デフォルトのアクセス指定しがpublicかprivateかという点
        構造体：public
        クラス：private

    使い分けがとっても大事
        構造体が使用されるケース
            ・データをまとめるだけで、特別な処理（関数）が不要なとき。
            ・メンバ変数が全てpublicで、外部から自由に読み書きされても問題ないとき。
            ・超シンプル！
        クラスが使用されるケース
            ・データと、それに関連する処理を一緒に管理したいとき。
            ・データを保護したい（カプセル化したい）とき。
                ・メンバ変数をprivateにして、publicなメンバ関数経由で安全に操作させたい。
            ・複雑！重要データ！
    */

    return 0;
}