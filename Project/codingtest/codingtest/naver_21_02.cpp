#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int vsize = A.size();
    int fNum = 0;
    int sNum = 1;

    int fcnt = 0;
    int scnt = 0;
    for (int i = 0; i < vsize; i++) {
        if (A[i] != fNum) {
            fcnt++;
        }
        if (A[i] != sNum) {
            scnt++;
        }
        fNum = fNum == 0 ? 1 : 0;
        sNum = sNum == 0 ? 1 : 0;
    }
    int a = fcnt > scnt ? scnt : fcnt;
    return a;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    solution(v);

    return 0;


}


