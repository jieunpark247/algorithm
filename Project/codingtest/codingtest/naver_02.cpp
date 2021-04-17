#include<string>
#include<vector>
#include <cmath>

using namespace std;

string solution(int n, vector<int> p, vector<int> c) {
    string answer = "";
    double totalSum = 0;
    int sat = 0;
    int takSum = 0;
    int takWant = 0;
    int price = 100;
    int delayDays = 0;
    for (int i = 0; i < n; i++) {
        takSum = p[i];
        takWant = c[i];
        if (takSum >= takWant) {
            if (i < n - 1)
                p[i + 1] += (takSum - takWant);
            totalSum += takWant * price;
            delayDays = 0;
            price = 100;
        }
        else {
            if (delayDays == 2) { n = i+1; break; }
            p[i + 1] += takSum;
            if (delayDays == 0 || delayDays == 1) {
                price = price / 2;
            }
            delayDays++;
        }

    }

 
   double res = totalSum/n + 0.005;
    answer = to_string(res);
    char tmp[100001];
    strcpy(tmp, answer.c_str());
    int a = answer.find('.');
    tmp[a + 3] = '\0';
    string tmp2(tmp);
    answer = tmp2;
    return answer;

}

int main() {
    vector <int> a1;
    a1.push_back(6);
    a1.push_back(2);
    a1.push_back(1);
    a1.push_back(0);
    a1.push_back(2);
    a1.push_back(4);
    a1.push_back(3);
    vector<int> b1;
    b1.push_back(3);
    b1.push_back(6);
    b1.push_back(6);
    b1.push_back(2);
    b1.push_back(3);
    b1.push_back(7);
    b1.push_back(6);

    solution(7, a1, b1);
}