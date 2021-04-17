//모의고사
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int supo1[5] = { 1,2,3,4,5 };
    int supo2[8] = { 2,1,2,3,2,4,2,5 };
    int supo3[10] = { 3,3,1,1,2,2,4,4,5,5 };
    int arr[10001];
    int correct1 = 0, correct2 = 0, correct3 = 0;
    vector<int> corr;
    for (int i = 0; i < answers.size(); i++) {
        if (supo1[i % 5] == answers[i]) {
            correct1++;
        }
        if (supo2[i % 8] == answers[i]) {
            correct2++;
        }
        if (supo3[i % 10] == answers[i]) {
            correct3++;
        }
    }
    corr.push_back(correct1);
    corr.push_back(correct2);
    corr.push_back(correct3);
    sort(corr.begin(), corr.end());
    if (correct1 == corr[2]) {
        answer.push_back(1);
    }
    if (correct2 == corr[2]) {
        answer.push_back(2);
    }
    if (correct3 == corr[2]) {
        answer.push_back(3);
    }
    return answer;
}