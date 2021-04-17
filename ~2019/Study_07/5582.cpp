//
//  5582.cpp
//  Project
//
//  Created by PARKHASIK on 2018. 7. 17..
//  Copyright © 2018년 PARKJIEUN. All rights reserved.
//

#include <iostream>

using namespace std;

string A,B;
int ans;
int LCS[4001][4001];

int main(){
    cin>>A>>B;
    
    for (int i = 1; i <= A.length(); i++)
    {
        for (int j = 1; j <= B.length(); j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
                if (ans < LCS[i][j])
                {
                    ans = LCS[i][j];
                }
            }
        }
        
    }
    
    cout<<ans<<endl;;
    
}
