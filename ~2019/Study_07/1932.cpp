#include <iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int n;
int p[502][502];
int ans, sum;

int main() {
	scanf_s("%d",&n);

			ans = 0;
			sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf_s("%d", &p[i][j]);


			if (j == 1)//맨앞이거나
				p[i][j] = p[i - 1][j] + p[i][j];

			else if (j == i) //맨끝이면 겹치는겂 없음
				p[i][j] = p[i - 1][j - 1] + p[i][j];

			else
				p[i][j] = max(p[i - 1][j - 1], p[i - 1][j]) + p[i][j];

			ans = max(p[i][j], ans);

	


		}
	}	

	

	printf("%d", ans);
	return 0;
	
}