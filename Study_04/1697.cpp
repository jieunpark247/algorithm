#include <iostream>
#include <queue>
using namespace std;

const int MAX = 200000;
int visited[MAX + 1];  //방문했나?
int cnt[MAX + 1]; // 몇번만에 찾는지 알기 위해

int main() {

	int N, K;
	cin >> N >> K;

	queue <int> q;
	q.push(N);
	visited[N] = 1;
	cnt[N] = 0; // 초기값 설정

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == K) { break; }

		if (now - 1 >= 0 && !visited[now - 1]) {
			q.push(now - 1);
			visited[now - 1] = 1;
			cnt[now - 1] = cnt[now] + 1;

		}
		if (now + 1 > 0 && !visited[now + 1] && now + 1 <MAX) {
			q.push(now + 1);
			visited[now + 1] = 1;
			cnt[now + 1] = cnt[now] + 1;

		}
		if (now * 2 > 0 && !visited[now * 2] && now * 2<MAX) {
			q.push(now * 2);
			visited[now * 2] = 1;
			cnt[now * 2] = cnt[now] + 1;

		}
	}

	cout << cnt[K] << endl;
	return 0;
}
