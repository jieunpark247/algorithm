#include <string>
#include <algorithm>
#include <vector>

using namespace std;
char ans[201];
int solution(string answer_sheet, vector<string> sheets) {
    int answer = -1;
    int size = sheets.size();
    int a_size = answer_sheet.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            string curr = sheets.at(i);
            string cmp = sheets.at(j);
            int num = 0, save = 0, num2 = 0;
            for (int k = 0; k < a_size; k++) {
                if (curr[k] == cmp[k] && answer_sheet[k] != curr[k]) {
                    num2++;
                    num++;
                }
                else {
                    save = max(num2, save);
                    num2 = 0;
                }
            }
            save = max(num2, save);
            answer = max(answer, num + (save * save));
        }
    }
    return answer;
}