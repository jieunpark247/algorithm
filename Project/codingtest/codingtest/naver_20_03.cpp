#include <iostream>
#include <string>
#include <vector>

using namespace std;


int a[10] = { 6,2,5,5,4,5,6,3,7,6 };

long long cache[200][51];
long long dfs(int curr, int remain) {
    long long& ret = cache[curr][remain];
    if (ret != -1) return ret;
    if (remain == 0) {
        ret = 1;
        return ret;
    }
    ret = 0;
    for (int i = 0; i < 10; i++) {
        if (a[i] <= remain) {
            ret += dfs(curr + 1, remain - a[i]);
        }
    }
    return ret;
}


long long solution(int k) {
    long long answer = 0;
    memset(cache, -1, sizeof(cache));
    if (k == 6) answer++;
    for (int i = 1; i < 10; i++) {
        if (k >= a[i]) answer += dfs(1, k - a[i]);
    }

    return answer;
}