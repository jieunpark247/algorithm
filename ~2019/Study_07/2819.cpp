
//
//  2819.cpp

//격자판의 숫자 이어 붙이기

#include <iostream>
//#include<vector>
#include<math.h>

using namespace std;

int map[4][4],visited[4][4];
int dx[4]= {1,-1,0,0};
int dy[4]= {0,0,1,-1};
int countt;
//vector <int> v;
int findNum[10000000];
int numSum;

void init_visited(){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            visited[i][j]=0;
}

void solve(int x , int y,double cnt){
   
    if(cnt==7){
        //7자리수 넘으면 리턴
       /* int check_=0;
        for(int i =0;i<v.size();i++){
            countt++;
            if(v[i]==numSum)
                check_=1;
            
        }
        
        if(check_==0)
            v.push_back(numSum);
        */
        if(findNum[numSum]==0){ //numsum자리에 0이라면 (한번도 그 자리에 가본적이 없다면?)
            findNum[numSum]=1; //1으로 넣어주고
            countt++; //카운트 갯수 증가
        }
        return;
    }
    
    
    for(int i=0;i<4;i++){
        
        int nx = x+dx[i];
        int ny = y+dy[i];
        
        if(nx>=0 && ny>=0 && nx<4 && ny<4){ //조건에 부합함?
            if(visited[nx][ny] < 4){ // visitd가 4보다 작으면? ,,, 원래 7로 했는데 4까지 가능해서 줄여줌
                numSum = numSum+ map[nx][ny]*pow(10.0,cnt); //10의 cnt 제곱만큼 더해주기
                visited[nx][ny]=visited[nx][ny]+1;
                
                solve(nx,ny,cnt+1); //재귀로 다음값
               
                numSum = numSum-map[nx][ny]*pow(10,cnt); //빼주기
                visited[nx][ny]=visited[nx][ny]-1; //방문표시 취소
            }
            
        }
        
        
        
        
    }
    
}


int main(){
    int testcase;
    cin>>testcase;
    for(int t=1;t<=testcase;t++){
   
        
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cin>>map[i][j];
            }
        }
        
      
        //v.clear();
     //   v.push_back(-1);
        
        for(int i=0;i<=9999999;i++)
            findNum[i]=0;
        
        countt=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                
                init_visited();
                visited[i][j]=visited[i][j]+1; //처음 시작하는 i j 를 방문표시해줌
                
                numSum=+map[i][j];
                
                solve(i,j,1);
            }
        }
        
      
      //  cout<<"#"<<t<< " " <<v.size()-1<<endl;
        
        cout<<"#"<<t<< " " <<countt<<endl;

    }
    
}
