#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

stack <char> s;
stack <char> s2;
stack <char> q;

int testcase;
int main() {
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++) {
		char ch[1000005];
		scanf("%s", ch);
		int chSize = 0;
		while (ch[chSize]!='\0') {
			chSize++;
		}
//		
		for (int j = 0; j < chSize; j++) {
			if (ch[j] == '<') {
				if (!s.empty()) {
					 q.push(s.top());
					 s.pop();
				}
			}else if (ch[j] == '>') {
				if (!q.empty()) {
					s.push(q.top());
					q.pop();
				}
			}else if (ch[j] == '-') {
				if (!s.empty()) {
					s.pop();
				}
			}else {
				s.push(ch[j]);
			}
		}

		while (!s.empty()) {
			s2.push(s.top());
			s.pop();
		}

		while (!s2.empty()) {
			printf("%c" ,s2.top());
			s2.pop();
		}
		while (!q.empty()) {
			printf("%c", q.top());
			q.pop();
		}
		printf("\n");
	
	}
		return 0;
}