#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int map[16][16];
int checked[16][16];
int A, B;
int ax, ay;
vector <int> v;
vector <int> vA;
vector <int> vB;
int dx[] = { 1,0 };
int dy[] = { 0,1 };
int ans;

void init_map() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			map[i][j] = 0;
}
void init_checked() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			checked[i][j] = 0;
}
void detailTaste() { //A,B각각 맛 구하기
	int row,col; //열 행
	A = 0; B = 0;
	init_checked();

	for (int vv = 0; vv < vA.size(); vv++) {
		row = vA[vv];
		col = vA[vv];
		
		for(int i = 1; i <= n; i++) {
			checked[i][row] =checked[i][row]+1;
			checked[col][i]= checked[col][i]+1;
		}
	} //

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (checked[i][j] == 2)
				A = A + map[i][j];


/*	//============
	for (int i = 1; i <= n; i++) {
		cout << '\n';
		for (int j = 1; j <= n; j++) {
			cout << checked[i][j];
		}
	}
		cout << '\n';
	//============
	*/
	init_checked();

	for (int vv = 0; vv < vB.size(); vv++) {
		row = vB[vv];
		col = vB[vv];

		for (int i = 1; i <= n; i++) {
			checked[i][row] = checked[i][row] + 1;
			checked[col][i] = checked[col][i] + 1;
		}
	} //

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (checked[i][j] == 2)
				B = B + map[i][j];


	/*
//============
	for (int i = 1; i <= n; i++) {
		cout << '\n';
		for (int j = 1; j <= n; j++) {
			cout << checked[i][j];
		}
	}
		cout << '\n';
	//============

	*/
//		cout << "ans" << abs(A - B) << '\n';
		ans = min(abs(A - B), ans);

		
}


void solve(int dFood) { //detail->재료  food->음식
	v.clear();

	
	for (int i = 1; i <= n; i++) {
	v.push_back(i);
	}

	vector<int> ind;

	int k = dFood;

	for (int i = 0; i < k; i++) {
		ind.push_back(1);
	}
	for (int i = 0; i < v.size() - k; i++) {
		ind.push_back(0);
	}
	sort(ind.begin(), ind.end()); //오름차순 정렬

	do { //순열 돌리기
		vA.clear();
		vB.clear();
		for (int i = 0; i < ind.size(); i++) {
			if (ind[i] == 1) {
				vA.push_back(i+1);//A음식의 재료값들을 저장 ex>123이면 123저장 
				
			}
			if (ind[i] == 0) { 
				vB.push_back(i+1); //B음식의 재료값들을 저장 ex>456이면 456저장
				
			}

		}
		
		//=================================
		/*
		cout << "-------- A:";
		for (int i = 0; i < vA.size(); i++) {
			cout << " "<<vA[i];
		}	
		cout << "-------- B:";
		for (int i = 0; i < vB.size(); i++) {
			cout << " " << vB[i];
		}
		
		*/
		detailTaste();
	//	cout << "=======";

		//=================================
	


	}

	while (next_permutation(ind.begin(), ind.end()));





}
int main() {
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		cin >> n;
		init_map();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> map[i][j];

		v.clear();
		init_checked();
		ans = 999999999;
		solve(n/2);
		
		cout << "#" << t << " " << ans << endl;;


	}
}