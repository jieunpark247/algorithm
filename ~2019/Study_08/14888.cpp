//
//  14888.cpp
//  Project
// 연산자 끼워넣기

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int a[12];
int b[11];
int plu, mi, mul, di;
vector <int> v;
vector <int> vCal;
int ansMax,ansMin,ans;
int sum;

int main() {
     ansMax = -987654321;
        ansMin = 987654321;
        ans = 0;
        
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> plu >> mi >> mul >> di;
    
        vCal.clear();
        for (int i = 0; i < plu; i++)
            vCal.push_back(20); //20 + 21 - 22 * 23 /
        for (int i = plu; i < plu + mi; i++)
            vCal.push_back(21);
        for (int i = plu + mi; i < plu + mi + mul; i++)
            vCal.push_back(22);
        for (int i = plu + mi + mul; i < plu + mi + mul + di; i++)
            vCal.push_back(23);
        
        do {
            for (int i = 0; i < n - 1; i++)
                b[i] = 0;
            b[0] = 20;
            sum = 0;
            
            for (int i = 0; i <n-1; i++) {
                
                b[i+1] = vCal[i];
            }
            
            
            for (int i = 0; i < n; i++) {
                if(b[i] == 20){
                    sum = sum + a[i];
                }
                if (b[i] == 21) {
                    sum = sum - a[i];
                }
                if (b[i] == 22) {
                    sum = sum *a[i];
                }
                if (b[i] == 23) {
                    sum = sum / a[i];
                }
            }
            v.push_back(sum);
            
        } while (next_permutation(vCal.begin(),vCal.end()));
        
        
        for (int i = 0; i < v.size(); i++) {
            ansMax = max(ansMax, v[i]);
            ansMin = min(ansMin, v[i]);
            
        }

    
        cout<<ansMax<<'\n';
        cout<<ansMin<< endl;
        v.clear();
    
}
