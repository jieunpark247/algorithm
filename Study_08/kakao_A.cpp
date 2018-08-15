


#include <iostream>

using namespace std;

int a,b;
int ansA[7],ansB[7];
int ansa,ansb;
int arrayA[7][3], arrayB[7][3];

void solve(){
    
    int cnt=0;
    for(int i =0;i<6;i++){
        if(a <=arrayA[i][1]){
            ansA[cnt]=i;
            cnt++;
        }
    }
    
            ansa=arrayA[ansA[0]][0];
    
    
    int ccnt=0;
    for(int i =0;i<5;i++){
        if(b <=arrayB[i][1]){
            ansB[ccnt]=i;
            ccnt++;
        }
        
        
    }

      ansb=arrayB[ansB[0]][0];
}


int main(){
    
    int testcase;
    cin>>testcase;
    
    arrayA[0][0]=5000000;
    arrayA[1][0]=3000000;
    arrayA[2][0]=2000000;
    arrayA[3][0]=500000;
    arrayA[4][0]=300000;
    arrayA[5][0]=100000;
    arrayA[0][1]=1;
    arrayA[1][1]=3;
    arrayA[2][1]=6;
    arrayA[3][1]=10;
    arrayA[4][1]=15;
    arrayA[5][1]=21;
    
    arrayB[0][0]=5120000;
    arrayB[1][0]=2560000;
    arrayB[2][0]=1280000;
    arrayB[3][0]=640000;
    arrayB[4][0]=320000;
    arrayB[0][1]=1;
    arrayB[1][1]=3;
    arrayB[2][1]=7;
    arrayB[3][1]=15;
    arrayB[4][1]=31;
    
    for(int t=1;t<=testcase;t++){
        cin>>a>>b;
        
        
         for(int i =0;i<7;i++){
                ansA[i]=0;    ansB[i]=0;
         }
      

   
        
        solve();
        if(a>21|| a==0)
            ansa=0;
        if(b>31||b==0)
            ansb=0;
        
        cout<<ansa+ansb<<endl;
      
        
    }
}
