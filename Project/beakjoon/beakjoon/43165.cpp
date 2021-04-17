// 프로그래머스 43165 타겟넘버 


#include <string>
#include <vector>
using namespace std;

int dfs(int ans, int loc , vector<int> numbers, int target) {
    int cnt = 0;
    int temp = ans;
    if (numbers.size() == loc) {
        if (ans == target)
            return cnt + 1;
        return cnt;
    }
    for (int i = 0; i < 2; i++) {
        if (i == 0) ans = ans + numbers[loc];
        else ans = ans - numbers[loc];
        cnt = dfs(ans, loc + 1, numbers, target) + cnt;
        ans = temp;
    }
    return cnt;
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    answer = dfs(answer, 0, numbers, target);
    return answer;
}

int main() {

    vector<int> numbers;
    int target = 3;
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    solution(numbers, target);
    return 0;
}