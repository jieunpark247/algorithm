//문자열 압축 
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(string s) {
    int answer = 0;
    int minSize = 987654321;
    for (int i = 1; i <= s.size(); i++) {
        string savedStr;
        string newStr;
        int cnt = 0;
        int start = 0;
        int flag = 0;
        for (int a = 0; a < i; a++) {
            savedStr += s[a];
        }
        for (int j = 0; j < s.size(); j += i) {
            string selectedStr;
            for (int a = j; a < j + i; a++) {
                if (a >= s.size()) {
                    savedStr = savedStr + selectedStr;
                    flag = 1;
                    break;
                }
                selectedStr += s[a];
            }
            if (savedStr == selectedStr) {
                cnt++;
            }
            else if (!flag) {
                newStr += cnt == 1 ? savedStr : to_string(cnt) + savedStr;
                savedStr = selectedStr;
                cnt = 1;
            }
        }

        newStr += cnt == 1 ? savedStr : to_string(cnt) + savedStr;
        int sz = newStr.size();
        minSize = min(sz, minSize);

    }

    answer = minSize;
    return answer;
}