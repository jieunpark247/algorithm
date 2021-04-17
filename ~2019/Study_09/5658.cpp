//
//  5658.cpp
//  Project
//
//  보물상자 비밀번호

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

char pwd[30];
int n,k;
int pwdlength;
vector<long> mNum;
int a;
char numn[8];

void makeNum(int p,int a){
    if(a==p+1)
        return;
    
    vector<char> number_pwd;
    
    for (int i = a; i <= n; i += pwdlength){
        number_pwd.clear();
        for(int j=0;j<pwdlength;j++){
            if(i+j>n)
                number_pwd.push_back(pwd[(i+j)%n]);
            else
                number_pwd.push_back(pwd[i+j]);
            }
        string oneN;
        for(int ii=0;ii<7;ii++) numn[ii]=0;
        
        for(int jj=0;jj<number_pwd.size();jj++){
            numn[jj]=number_pwd[jj];
        }
        
        oneN=numn;
//        for(int jj=0;jj<number_pwd.size();jj++)
//            oneN+=number_pwd[i];

            char *s = (char*)oneN.c_str();
            long aa = strtol(s, NULL, 16);
            int r=0;
            for(int i=0;i<mNum.size();i++)
                if(mNum[i]==aa)
                    r=1;
            
            if(r==0) mNum.push_back(aa);
        
        
        }
    
        
        makeNum(pwdlength,a+1);
    
}
int main(){
    int testcase;
    cin>>testcase;
    for(int t=1;t<=testcase;t++){
        cin>>n;
        cin>>k;
        mNum.clear();
        //for(int i=0;i<=n;i++) pwd[i]=0;
        for(int i=-1;i<=n;i++){
            scanf("%c",&pwd[i]);
        }

        pwdlength=n/4;
        a=1;
        makeNum(pwdlength,a);
        sort(mNum.begin(), mNum.end(),greater<int>());
        // printf("%d\n", a);
        cout<<"#"<<t<<" "<<mNum[k-1]<<endl;

    }
}
