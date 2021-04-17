//
//  9252.cpp
//  Project
//
//  Created by PARKHASIK on 2018. 7. 17..
//  Copyright © 2018년 PARKJIEUN. All rights reserved.
//

#include <iostream>

using namespace std;

#define max(a,b) (a > b ? a : b)
string A,B;
int LCS[1003][1003];

int jj;
int check;
void print(){
    check++;
    
       if(check>LCS[A.length()][B.length()])
        return;
    
    
       for(int i=1;i<=A.length();i++) {
           if(LCS[i][jj]==check){
               cout<<A[i-1];
               
               print();
           }
      }


}

int main(){
    cin>>A>>B;
    
    for(int i=1;i<=A.length();i++) {
        for(int j=1;j<=B.length();j++) {
            if (A[i-1] == B[j-1]) {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            } else {
                LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]);
            }
        }
        
    }
    
  
    cout<<LCS[A.length()][B.length()]<<'\n';
  
    check=0;
    
    for(int i=1;i<=A.length();i++) {
        for(int j=1;j<=B.length();j++) {
            if(LCS[i][j]==LCS[A.length()][B.length()])
                jj=j;
        }
        
    }
    
    print();
    cout<<endl;

  }
