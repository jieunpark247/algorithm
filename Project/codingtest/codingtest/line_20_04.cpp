#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string save = "SAVE";
vector<vector<string>> solution(vector<vector<string>> snapshots, vector<vector<string>> transactions) {
    int s_size = snapshots.size();
    int t_size = transactions.size();
    vector<string> id;
    for (int i = 0; i < t_size; i++) {
        int id_size = id.size();
        bool flag = false;
        for (int j = 0; j < id_size; j++) {
            if (!id[j].compare(transactions.at(i).at(0))) {
                flag = true;
                break;
            }
        }
        if (flag) continue;
        id.push_back(transactions.at(i).at(0));

        for (int j = 0; j < s_size; j++) {
            if (!snapshots.at(j).at(0).compare(transactions.at(i).at(2))) {
                flag = true;
                int snap = atoi(snapshots.at(j).at(1).c_str());
                int tran = atoi(transactions.at(i).at(3).c_str());
                if (!transactions.at(i).at(1).compare(save)) {
                    snapshots.at(j).at(1) = to_string(snap + tran);
                }
                else {
                    snapshots.at(j).at(1) = to_string(snap - tran);
                }
                break;
            }
        }
        if (!flag) {
            s_size++;
            vector<string> tmp;
            tmp.push_back(transactions.at(i).at(2));
            tmp.push_back(transactions.at(i).at(3));
            snapshots.push_back(tmp);
        }
    }
    sort(snapshots.begin(), snapshots.end());
    return snapshots;
}