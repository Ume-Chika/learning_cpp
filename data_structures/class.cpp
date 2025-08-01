#include <iostream>
#include <string>

// 団体の情報表す構造体の定義
struct GroupInfo {
    int member_count = 4;
    std::string leader_first_name = "Not Set";
    std::string learder_last_name = "Not Set";
    std::string group_name = "Not Set";
};

class GroupManager {
    private:
        // 隠したいメンバ変数
        int group_id;
        int group_income;
        std::string leader_email;
        // 隠したいメンバ関数
        void send_message(std::string message) {
            // メッセージを送る関数は超危険なため隠す！！
            std::cout << "Message: " << message << std::endl;
        }
    public:
        // 書き換えてもらってもいいメンバ変数
        GroupInfo group_info;
        // コンストラクタ
        GroupManager(GroupInfo info, int group_id, int group_income, std::string learder_email) {
            group_info = info;
            this->group_id = group_id;
            this->group_income = group_income;
            this->leader_email = learder_email;
        }
        // メンバ関数
        std::string get_leader_full_name() {
            return group_info.leader_first_name + " " + group_info.learder_last_name;
        }
        void display_group_info() {
            std::cout << "Group Name: " << group_info.group_name << std::endl;
            std::cout << "Leader: " << get_leader_full_name() << std::endl;
            std::cout << "Member Count: " << group_info.member_count << std::endl;
        }
        bool try_send_message (std::string message) {
            // 安全にメールを送るための処置をする
            // 例：NGワード設定, トライや呼び出し制限などなど
            try {
                send_message(message);
                if (message.find("NG") != std::string::npos) {
                    throw std::runtime_error("massege can't contain NG word.");
                }
                return true; // 例外が起きなければ成功
            }
            catch (const std::runtime_error& e) {
                // 「std::runtime_error」型の例外をキャッチする
                std::cerr << "Failed to send message: " << e.what() << std::endl;
                return false; // 例外が起きたら失敗
        }
    }
};

int main() {
    GroupInfo group1 = {
        .leader_first_name = "Chikara", 
        .learder_last_name = "Umeda", 
        .group_name = "Group UmeChi"
    };
    GroupManager manager(group1, 1, 100000, "hogeta@gmail.com");
    manager.display_group_info();

    std::string send_massage;
    std::cin >> send_massage;
    bool success = manager.try_send_message(send_massage);
    if (success) {
        std::cout << "Message sent successfully!" << std::endl;
    }
    else {
        std::cout << "Message failed to send." << std::endl;
    }

    return 0;
}