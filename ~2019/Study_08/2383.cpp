//
//  2383.cpp
//  Project
// 점심 식사시간

#include <iostream>
#include<vector>
#include<algorithm>

#define max(a,b) (a > b ? a : b)

using namespace std;
int n;
vector <pair < int,int > > k;
vector <pair < int,int > > p;
vector <int> pk1;vector <int> Npk1;
vector <int> pk2;vector <int> Npk2;
int map[12][12];
int ans,res1,res2,res;
int pk1_,pk2_;
vector<int> ind;


void stairsPK1(){ // 계단1을 사람들이 내려가는 시간 res1 을 구하기
  
    for (int i = 0; i < ind.size(); i++) {
        if (ind[i] == 1) {
            Npk1.push_back(pk1[i]); // 조합으로 돌린 사람들의 사람-계단1 거리(pk1)를  Npk1에 넣어주기
            
        }
    }
    
    sort(Npk1.begin(), Npk1.end()); //오름차순으로 정렬
    
    if(Npk1.size()>3){ //그 배열 크기가 3보다 크다면?
        for(int i =0;i<3;i++){
            Npk1[i]=Npk1[i]+pk1_; //3명이 먼저 내려갈 수 있으니 시간이 작은 애들 순으로 pk1_(시간)을 더해준다
        }
      
        //int a= ((Npk1.size()-1)/3)*3-1; //
         //  int w=(Npk1.size()-1)%3 + ((Npk1.size()-1)/3-1)*3;
        
        int w=(Npk1.size()-1)%3 ; // 3개씩 나눴을때 맨 마지막 번호의 위치 값을 구하기
        if(Npk1[(Npk1.size()-1)]>=Npk1[w]+pk1_* ((Npk1.size()-1)/3-1)){ // 맨 마지막 사람의 도착시간이 >= 내가 그 계단은 가기 시작할 수 있는 시간보다 크다면 ? (바로 계단에 내려갈 수 없고 사람이 도착할 때까지 기다려야한다)
         
            res1=Npk1[(Npk1.size()-1)]+pk1_; // 맨마지막 사람의 도착시간 + 계단을 내려가는데 거리는 시간을 해준다 (이게 결국 최대 걸리는 시간이므로 이 값안에 모든 사람들이 다 내려갈 수 있음)
            
        }else{ // 그게 아니면?
            
            res1 = Npk1[w]+ pk1_*((Npk1.size()-1)/3); //마지막 사람이 계단을 내려갈 수 있는 시간+계단 내려가는 시간을 해준다.
        
        //다음 남은 값들 +pk1_만큼 더해줘서 최댓값 구해내기
        
        }
    }else{ //3보다 작으면 그 값들 + 계단 내려가는 시간인 pk1_값을 더해주어 최댓값을 구해준다 (3명이서 같이 내려갈수 있으니 대기시간 없음)
    
        for(int i =0;i<Npk1.size();i++){
          res1= max(res1,Npk1[i]+pk1_);
    
    
    }
        

    }
        
    
    
}

void stairsPK2(){//계단2을 사람들이 내려가는 시간 res2 을 구하기
    for (int i = 0; i < ind.size(); i++) {
        if (ind[i] == 0) {
            Npk2.push_back(pk2[i]);
            
        }
    }
   
    sort(Npk2.begin(), Npk2.end());
    
    if(Npk2.size()>3){
        for(int i =0;i<3;i++){
            Npk2[i]=Npk2[i]+pk2_;
        }
        
     
       // int a= ((Npk2.size()-1)/3)*3-1;
      //   int w=(Npk2.size()-1)%3 + ((Npk2.size()-1)/3-1)*3;
         int w=(Npk2.size()-1)%3;
        
        if(Npk2[(Npk2.size()-1)]>=Npk2[w]+pk2_* ((Npk2.size()-1)/3-1)){
            res2=Npk2[(Npk2.size()-1)]+pk2_;
        }else{
            
            res2= Npk2[w]+ pk2_*((Npk2.size()-1)/3);
        
        //다음 남은 값들 +pk1_만큼 더해줘서 최댓값 구해내기
        }
        
    }else{
        for(int i =0;i<Npk2.size();i++){
            res2=max(res2,Npk2[i]+pk2_);
        }
    
}

}


void selectPK(int k){ //계단1 ,2 가 각각 몇사람이 가는지 조합 돌리기
    if(k>pk1.size()) // k가 사람수보다 많으면 리턴
        return;
    

    
    for (int i = 0; i < k; i++) {
        ind.push_back(1);
    }
    for (int i = 0; i < pk1.size() - k; i++) {
        ind.push_back(0);
    }
    sort(ind.begin(), ind.end());
    
    do {
        
        Npk2.clear();
        Npk1.clear();
        res1=res2=0;
        //distancePK1, 2 에서 사용할 함수 초기화
       
        stairsPK1();
        stairsPK2();
        
        
        if(res1<res2)
            res=res2;
        else
            res=res1; // res1, res2 중 큰값을 res 에  넣어준다. 적어도 최댓값만큼 걸리면 그시간안에 모두 해결가능)
        
        if(ans>res) // 그 res 값들중 최솟값을 찾기
            ans=res;
                
            
        }

    
    while (next_permutation(ind.begin(), ind.end())); 
    
    ind.clear();
    selectPK(k+1);
    
}


int main(){
    int testcase;
    cin>>testcase;
    
    for(int t=1;t<=testcase;t++){
        
        for(int i =1;i<=n;i++)
            for(int j =1;j<=n;j++)
                map[i][j]=0;
        ans=987654321;
        res=0;
        pk1.clear();
        pk2.clear();
        k.clear();
        p.clear();
        
        //초기화
        
        cin>>n;
        for(int i =1;i<=n;i++){
            for(int j =1;j<=n;j++){
                cin>>map[i][j];
                //입력
                
                if(map[i][j]==1)
                   p.push_back(make_pair(i, j));
                else if(map[i][j]>1)
                     k.push_back(make_pair(i, j));
                //1이면 P에 1보다 크면 k 배열에 x , y 값 넣기
                
            }
        }
        
        
        pk1_=map[k[0].first][k[0].second]; // pk1 은 첫번째 계단
        pk2_=map[k[1].first][k[1].second]; // 두번째 계단
        
        
       for(int i =0;i<p.size();i++){
           pk1.push_back(abs(p[i].first-k[0].first)+abs(p[i].second-k[0].second)); //사람 위치부터 계단1 위치까지의 값 구하기
           pk2.push_back(abs(p[i].first-k[1].first)+abs(p[i].second-k[1].second)); //사람 위치부터 계단2 위치까지의 값 구하기
        }
        
        
        
        selectPK(0); // 조합돌리기(계단1, 계단2 를 사람 몇명이 각각 가는지 경우의수 돌리기) 0부터 시작
        
    
        cout<<"#"<<t<<" "<<ans+1<<endl; // 계단 도착한후 1분후 출발 이라 +1
        
    
        
    }
    
}
