#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int haveClothes = n - lost.size();
    vector<int> rs;
    int arr[30] = { 0,  };
    int cnt = 0;
    int reCnt = 0;
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (lost[i] - 1 == reserve[j] && arr[reserve[j]] == 0) {
                arr[reserve[j]] = 1;
                cnt++;
                break;
            }
            else if (lost[i] + 1 == reserve[j] && arr[reserve[j]] == 0) {
                arr[reserve[j]] = 1;
                cnt++;
                break;
            }

        }
    }
    for (int i = 0; i < 30; i++) arr[i] = 0;
    for (int i = lost.size()-1; i >= 0; i--) {
        for (int j = reserve.size()-1; j >= 0; j--) {
            if (lost[i] - 1 == reserve[j] && arr[reserve[j]] == 0) {
                arr[reserve[j]] = 1;
                reCnt++;
                break;
            }
            else if (lost[i] + 1 == reserve[j] && arr[reserve[j]] == 0) {
                arr[reserve[j]] = 1;
                reCnt++;
                break;
            }

        }
    }

    answer = max(cnt,reCnt) + haveClothes;
    return answer;
}

int main() {
    vector<int> lost;
    vector<int> reserve;
    lost.push_back(3);    
    //reserve.push_back(2);    reserve.push_back(4);

    solution(5, lost, reserve);

}