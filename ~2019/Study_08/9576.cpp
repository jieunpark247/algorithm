#include <iostream>
#include <vector>

#define MAX 1001

using namespace std;
int a, b;
int M, N;
int matchWork[MAX];

vector < int > adj[MAX];

int visited[MAX];


bool dfs(int aa)
{
	if (visited[aa] == 1) return false;

	visited[aa] = 1;

	for (int b = 0; b < adj[aa].size(); b++) {
		int w = adj[aa][b];
		if (matchWork[w] == 0 || dfs(matchWork[w])) {
			matchWork[w] = aa;
			return true;
		}
	}
	return false;

}


int main()
{
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		cin >> N >> M;

		for (int i = 0; i <= MAX; i++) {
			visited[i] = 0;
			matchWork[i] = 0;
		}
		for (int t = 0; t <= M; t++) { adj[t].clear(); }

		for (int n = 1; n <= M; n++) {
			cin >> a>>b;
			for (int t = a; t <= b; t++) {
				adj[n].push_back(t);
			}
		}

		int size = 0;
		for (int start = 1; start <= M; start++) {

			for (int i = 0; i <= M; i++) {	visited[i] = 0;	}			
			if (dfs(start)) {
				size++;
			}
		}


		cout << size << endl;
	}
	return 0;
}