//완주하지못한 선수
#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    multimap<string, int> m;
    for (int i = 0; i < participant.size(); i++) {
        m.insert(make_pair(participant[i], 1));
    }
    for (int i = 0; i < completion.size(); i++) {
        m.erase(m.find(completion[i]));
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        answer = it->first;
    }

    return answer;
}