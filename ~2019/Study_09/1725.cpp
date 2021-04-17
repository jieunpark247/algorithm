//
//  1725.cpp
//  Project
// 히스토그램
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> h;
int n,a;


int solve(int left , int right){
    if(left == right) //같아지면 리턴 solve(6,6리턴)
        return h[left];
    
    int mid = (left+right)/2; // 중간 정함
    
    int ret= max(solve(left, mid),solve(mid+1,right)); //좌, 우 둘중 큰것을 ret 에 넣기
    int lo = mid, hi = mid +1;
    int height = min(h[lo],h[hi]); // lo ~ hi 의 최소 높이값 구하기
    ret = max(ret, height*2); // lo ~ hi는 항상 2차이가 남 *2 해줌
    while(left < lo||hi<right){
        if(hi<right &&(lo==left || h[lo-1]<h[hi+1])){
            ++hi;
            height=min(height,h[hi]);
        }
        else {
            --lo;
            height=min(height,h[lo]);
        }
        
        ret = max(ret, height*(hi-lo+1)); // 2개에서 hi lo를 각각 왼 오른쪽으로 넓혀가 그 직사각형의 넒이를 구해서 max값 추출
    }
    return ret;
}

int main(){
    cin>> n;
    for(int i =0;i<n;i++){
        cin>>a;
        h.push_back(a);
    }
    
    cout<<solve(0,n-1)<<endl;;
    
  
    
}
