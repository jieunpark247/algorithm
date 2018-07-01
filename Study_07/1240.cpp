 #include<iostream>
 #include<vector>
#include <stdio.h>

 using namespace std;

 int n,m;
 int map[100][50],temp[56][56];
 int visited[100][50];
 int ans,cnt,c;
 int num_;
 vector <int> v;
 int xx, yy;
 int  result[8],r;

 int calcNum(int num)
 {
	 switch (num)
	 {
	 case 1101:
		 return 0;
	 case 11001:
		 return 1;
	 case 10011:
		 return 2;
	 case 111101:
		 return 3;
	 case 100011:
		 return 4;
	 case 110001:
		 return 5;
	 case 101111:
		 return 6;
	 case 111011:
		 return 7;
	 case 110111:
		 return 8;
	 case 1011:
		 return 9;
	 default:
		 return -1;
	 }

 }


 void solve() {
	 
	 for (int i = 0; i <= 56; i++) {
		 cout << v[i];
	 }

	 c = 0;
	 cnt = 0;
	 for (int i = cnt; i < cnt + 8; i++) {
		 num_ = v[0 + i] + (v[1 + i] * 10) + (v[2 + i] * 100) + (v[3 + i] * 1000) + (v[4 + i] * 10000) + (v[5 + i] * 100000) + (v[6 + i] * 1000000);
		 result[c] = calcNum(num_);
		 c++;
	 }
 }

 int main() {
	 int testcase;
	 cin >> testcase;
	 for (int t = 1; t <= testcase; t++) {
		 cin >> n >> m;
		 for (int i = 0; i < n; i++) {
			 for (int j = 0; j < m; j++) {
				 scanf_s("%1d",&map[i][j]);
			 }
		 }
			
		

		 //----------------------
		 for (int i = 0; i < n; i++) {
			 for (int j = 0; j <m; j++) {
				 if (map[i][j] == 1) {
					 xx = i;
					 yy = j;
					 cout <<yy << " ";
					 break;
				 }
			 }
		 }

		 for (int i = yy; i < yy+56; i++) {
			 v.push_back(map[xx][i]);

		 }

		 ///--
		 solve();

		 r = 0;
		 for (int i = 0; i < 8; i++) {
			 if ((i % 2) == 0)
				 r = result[i] * 3;

			 else
				 r += result[i];
		 }
		 
		 if (r % 10 == 0)
			 for (int i = 0; i < 8; i++)
				 r += result[i];
		 else
			 ans = 0;

		 cout << "#" << t << " " << ans << endl;
	 }


}
