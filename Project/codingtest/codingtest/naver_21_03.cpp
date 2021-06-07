#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int solution(vector<string>& A) {
    int alphebat[100];
    // write your code in C++14 (g++ 6.2.0)
	int asize = A.size();
	for (int aa = 0; aa < asize; aa++) {
		vector<int> n;

		for (int i = 0; i < asize; i++) {
			n.push_back(i + 1);
		}
		vector<int> ind;
		int k = aa ;
		for (int i = 0; i < k; i++) {
			ind.push_back(1);
		}
		for (int i = 0; i < n.size() - k; i++) {
			ind.push_back(0);
		}
		sort(ind.begin(), ind.end());

		do {
			string str;
			for (int i = 0; i < ind.size(); i++) {
				if (ind[i] == 1) {
					str = str+= A[i];

				}
			}
		} while (next_permutation(ind.begin(), ind.end()));

	}
}

int main() {
    vector<string> v;
    v.push_back("abc");
    v.push_back("yyy");
    v.push_back("def");
    v.push_back("csv");

    solution(v);
}