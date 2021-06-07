#include <string>
#include <vector>
#include<algorithm>
#include <stdlib.h>
using namespace std;

bool compare(const pair<int, string>& a, const pair<int, string>& b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}
vector<string> solution(vector<vector<string>> dataSource, vector<string> tags) {
    vector<string> answer;
    vector<string> v;
    vector< pair<int, string>> pairV;

    for (int i = 0; i < dataSource.size(); i++) {
        for (int j = 0; j < dataSource[i].size(); j++) {
            for (int z = 0; z < tags.size(); z++) {
                if (dataSource[i][j] == tags[z]) {
                    v.push_back(dataSource[i][0]);
                }
            }
        }
    }

    sort(v.begin(), v.end());
    vector<int> word_count;
    vector<string> unique_word;

    unique_copy(v.begin(), v.end(), back_inserter(unique_word));

    vector<string>::size_type index, equal_word;
    for (index = 0; index != unique_word.size(); ++index) {
        equal_word = count(v.begin(), v.end(), unique_word[index]);
        if (equal_word)
            word_count.push_back(equal_word);

    }

    for (int i = 0; i < unique_word.size(); i++) {
        pairV.push_back(make_pair(word_count[i], unique_word[i]));
    }
    sort(pairV.begin(), pairV.end(), compare);

    for (int i = 0; i < pairV.size(); i++) {
        answer.push_back(pairV[i].second);
    }

    return answer;
}