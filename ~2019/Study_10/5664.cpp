//
//  5664.cpp
//  Project
// 무선충전기

#include<iostream>
#include<vector>
#include <string.h>
#include<algorithm>
using namespace std;
#define max(a,b) (a < b ? a : b)

//bc개수 8이하 충전범위(c) 4이하 ,,( >=10 <=500 power)
vector <int> bc[4]; // x,y,c,p
int bcA;//충전기 갯수
int mapT[11][11][8];
vector<int> map[11][11];
vector<int> check[11][11];
int a,b,x,y,c,p;
vector < int > A;
vector < int > B; //a출발 1,1b 출발 10,10 ( 이동정보 저장)
int m; // 총이동시간
int dx[5]={0,-1,0,1,0};
int dy[5]={0,0,1,0,-1};
int sum;
int fl;

bool isRange(int x, int y){return (x>=1&&x<11)&&(y>=1&&y<11);} //범위 안에 있으면 true

void rangeBC(int x, int y , int c, int p,int n){ //bc1,2,3,4...등의 범위만큼 값 집어넣기
    int nexty;
    int endp;
    
    for(int i=0;i<=c-1;i++){
        int upNextx=x-c+i;
        int downNextx=x+c-i;
        
        endp=i*2;
        nexty=y-endp/2;
        for(int j =0; j<=endp;j++){
            if(isRange(upNextx, nexty+j)){
                map[upNextx][nexty+j].push_back(p); // 실제 c 값
                check[upNextx][nexty+j].push_back(n); // bc 번호값
            }
            
            if(isRange(downNextx, nexty+j)){
                map[downNextx][nexty+j].push_back(p);
                check[downNextx][nexty+j].push_back(n);
            }
        }
    }
    endp=c*2;
    nexty=y-endp/2;
    for(int i =0; i<=endp;i++)
        
        if(isRange(x, nexty+i)){
            map[x][nexty+i].push_back(p);
            check[x][nexty+i].push_back(n);
        }
    
    for(int i=1;i<=10;i++) // 맵 sort 내림차순(최댓값을 구하는 것이기 때문)
        for(int j=1;j<=10;j++)
            sort(map[i][j].begin(), map[i][j].end(),greater<int>());
    
    for(int i=1;i<=10;i++)// mapT에 복사하기(vector 는 size==0 일떄 안돌아감)
        for(int j =1;j<=10;j++)
            for(long a=0;a < map[i][j].size();a++)
                mapT[i][j][a] = map[i][j][a];

}

int goAB(int anx,int any,int bnx,int bny){ //A,B 이동하면서 합 구해주기
    
    for(int ab=0;ab<=m;ab++){ //이동하는 경로
        anx= anx + dx[A[ab]];
        any= any + dy[A[ab]];
        bnx= bnx + dx[B[ab]];
        bny= bny + dy[B[ab]];
        fl = 1;
        if(isRange(anx, any)&& isRange(bnx, bny)){ //범위 내에 있고
          
            for(int ii=0;ii<check[anx][any].size();ii++){ //이동한 좌표의 bc 범위 값 (A)
                for(int jj=0;jj<check[bnx][bny].size();jj++){//이동한 좌표의 bc 범위 값 (B)
                    if(check[anx][any][ii] == check[bnx][bny][jj]){ //이 값다면 범위가 겹친다는것
                        fl=0;  // 범위가 겹치면 처리할거 많음 안겹치면 그냥 더함
                        break;
                    }
                }
            }
            
                //값이 같고 , 범위안이 다를 수 가 있다 and 범위안이 같더라도 최댓값이 아니여서 값이 다를 수 가 있다 => 그래서 둘다 만족해야함
                if(mapT[anx][any][0] == mapT[bnx][bny][0] && fl == 0){ //값이 같으면서 && 범위안에 있는 숫자이라면 ?
                        if(map[anx][any].size()>1 && map[bnx][bny].size()==1){ //map B사이즈는 1인데  map A의 사이즈 2이상이면 A선택
                            sum = sum + mapT[anx][any][1] + mapT[bnx][bny][0];
                        }else if(map[bnx][bny].size()>1 &&map[anx][any].size()==1){//map A사이즈는 1인데  map B의 사이즈 2이상이면 A선택
                            sum = sum + mapT[anx][any][0] + mapT[bnx][bny][1];
                        }else if(map[anx][any].size()>1 && map[bnx][bny].size()>1){//map A B 사이즈 둘다 2이상이면
                            if(mapT[anx][any][1] >map[bnx][bny][1] ){           //두번째 값중 큰 값 선택
                                sum = sum + mapT[anx][any][1] + mapT[bnx][bny][0];
                            }else{
                                sum = sum + mapT[anx][any][0] + mapT[bnx][bny][1];
                            }
                        }else if(map[anx][any].size()==1 && map[bnx][bny].size()==1){   //둘다 사이즈 1이면 나눠서 더해줌(= 한번더해줌)
                            sum = sum + mapT[anx][any][0];
                        }
                } else{ //다르면 각자의것 선택하면됨
                    sum = sum +  mapT[anx][any][0] + mapT[bnx][bny][0];
                }
        }
    }

    return sum;
}

int main(){
    int testcase;
    cin>>testcase;
    for(int t=1;t<=testcase;t++){
        //=====
        A.clear();B.clear();
        sum=0;
        for(int i =0;i<4;i++)
            bc[i].clear();
        for(int i =1;i<=10;i++)
            for(int j =1;j<=10;j++)
                for(int aa=0;aa<8;aa++)
                    mapT[i][j][aa]=0;
        for(int i =1;i<=10;i++){
            for(int j =1;j<=10;j++){
                map[i][j].clear();
                check[i][j].clear();
            }}
        //===== init ALL
        cin>>m>>bcA;
          A.push_back(0); B.push_back(0);
        for(int i =0;i<m;i++){
            cin>>a;
            A.push_back(a);
        }for(int i =0;i<m;i++){
            cin>>b;
            B.push_back(b);
        }
        for(int i =0;i<bcA;i++){
            cin>>x>>y>>c>>p;
            bc[0].push_back(x); bc[1].push_back(y);
            bc[2].push_back(c);  bc[3].push_back(p);
        }
        // =====입력
        
        
        for(int i =0;i<bc[0].size();i++)
            rangeBC(bc[1][i],bc[0][i],bc[2][i],bc[3][i],i+1);
 
        cout<<"#"<<t<<" "<<goAB(1,1,10,10)<<endl;
    }
}
