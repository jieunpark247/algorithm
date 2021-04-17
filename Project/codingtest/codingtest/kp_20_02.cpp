#include<string>
#include<vector>
#include <map>

using namespace std;

map<long long, pair<int, vector<int> > > res;
int chk[500001];

int  solution(int k, vector<int>score) {
	int answer = -1;
	int size = answer= score.size();
	vector<int> remove;
	for (int i = 1; i < size; i++) {
		int diff = score[i - 1] - score[i];
		res[diff].first++;
		res[diff].second.push_back(i);
		res[diff].second.push_back(i-1);
		if (res[diff].first == k) remove.push_back(diff);
	}

	size = remove.size();
	for (int i = 0; i < size; i++) {
		int rsize = res[remove[i]].second.size();
		for (int j = 0; j < rsize; j++) {
			if (!chk[res[remove[i]].second[j]]) {
				answer--;
				chk[res[remove[i]].second[j]] = 1;
			}
		}
	}
	if (answer == score.size()) answer = 0;
	return answer;

}

int main() {
	vector<int> a;
	a.push_back(24);
	a.push_back(22);
	a.push_back(20);
	a.push_back(10);
	a.push_back(5);
	a.push_back(3);
	a.push_back(2);
	a.push_back(1);
	solution(3, a);
}