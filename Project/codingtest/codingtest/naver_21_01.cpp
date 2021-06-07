#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <cmath>
#include <queue>
using namespace std;

string solution(string& S) {
    // write your code in C++14 (g++ 6.2.0)
    string answer;
    int flag = 0;
    int maxNum = 0;
   
    for (int i = 0; i < S.size(); i++) {
        maxNum =  max(S[i] - 'A', maxNum);
    }
    char a = maxNum + 'A';
    for (int i = 0; i < S.size(); i++) {
        if (a == S[i] && flag == 0) {
            flag = 1;
            continue;
         }
         answer.push_back(S[i]);
    }
    return answer;

}


int main(){

string a;

a= "codility";
 solution(a);

 return 0;


}