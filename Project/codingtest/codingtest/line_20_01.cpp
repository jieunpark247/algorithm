#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int solution(string inputString) {
    int answer = -1;
    int size = inputString.size();
    int res = 0;
    stack<char> s;
    for (int i = 0; i < size; i++) {
        char tmp = inputString.at(i);
        switch (tmp) {
        case ')':
            if (s.empty() || s.top() != '(') return answer;
            s.pop();
            res++;
            break;
        case '}':
            if (s.empty() || s.top() != '{') return answer;
            s.pop();
            res++;
            break;
        case ']':
            if (s.empty() || s.top() != '[') return answer;
            s.pop();
            res++;
            break;
        case '>':
            if (s.empty() || s.top() != '>') return answer;
            s.pop();
            res++;
            break;
        case '(':
            s.push(tmp);
            break;
        case '{':
            s.push(tmp);
            break;
        case '[':
            s.push(tmp);
            break;
        case '<':
            s.push(tmp);
            break;
        }
    }
    answer = res;
    return answer;
}