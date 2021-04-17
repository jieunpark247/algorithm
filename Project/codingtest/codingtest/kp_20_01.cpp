#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> solution(int N) {
	vector<int> answer;
	int totalSum = 0;
	int num;
	int mulSum;
	for (int i = 2; i < 10; i++) {
		int re;
		int n = N; 
		mulSum = 1;
		while (1) {
			if(n > i){
				re = n % i;
				n /= i;
				mulSum *= re;
			}
			else {
				mulSum *= n;
				break;
			}

		}
		if (totalSum < mulSum) {
			totalSum = mulSum;
			num = i;
		}
		else if (totalSum == mulSum) {
			num = i;
		}
	}

	answer.push_back(num);
	answer.push_back(totalSum);
	return answer; 
}
int main() {
	solution(1000023);
}