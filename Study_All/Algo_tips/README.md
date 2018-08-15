## 1. if return,continue 사용법

```
if(..)  
  {  
  ...
  return;  
  ...  
   }
```



> return의미는 조건에 해당된다면 함수를 끝낸다라는 의미



```
if(...)

continue;
```



> if 조건에 해당한다면 그냥 그 부분은 아무것도 하지 않고 넘어감

## 2. 재귀

재귀를 쓸 때 안끝난 채로 재귀에 들어가기 때문에 조건에 부합하지 않아 함수가 끝난다면 다른 경우의 수를 수행하게끔 **백트래킹**을 하여 경우의 수가 끝날 때 까지 수행한다.

## 3. 순열과 조합 

```

	vector<int> ind;

	int k = ....;

	for (int i = 0; i < k; i++) {
		ind.push_back(1);
	}
	for (int i = 0; i < ....size() - k; i++) {
		ind.push_back(0);
	}
	sort(ind.begin(), ind.end()); //오름차순 정렬

	do { //순열 돌리기

		for (int i = 0; i < ind.size(); i++) {
			if (ind[i] == 1) {

				...

			}
		}	
	} 

	while (next_permutation(ind.begin(), ind.end())); 


```
: 조합 만들기 



```  
		
	do { //순열  돌리기

		for (int i = 0; i < ind.size(); i++) { 
			if (ind[i] == 1) {
				//ind는 순열을 돌릴 vector 값
				.....

			}
		}	
	} 

	while (next_permutation(ind.begin(), ind.end())); 

```
:  순열 만들기



```
sort(v.begin(), v.end());  
```
:  오름차순 정렬

## 4. 공백없는 입력

```    
scanf_s("%1d",&map[i][j])
```


## 5. max,min(define) 선언

```
#define max(a,b) (a < b ? a : b)

#define min(a,b) (a < b ? a : b)

#define MAX 987654321;
```



## 6. vector 여러가지 선언 방법 (2,3차원 등)

```
vector <  int  > v;

vector < pair < int, int > > v;

vector < pair < int, int > > vv[MAX];

vector < pair < pair < int, int >, int > > v;
```



## 7. enum

```
enum { PATH = 1 }; 
```

 

## 8. 이동 좌표 

int dx[4] = { -1,0,1,0 }; //이동할 때 쓰는 x 좌표  int dy[4] = { 0,-1,0,1 }; //이동할 때 쓰는 y 좌표

```
int dx[4] = { -1,0,1,0 }; //이동할 때 쓰는 x 좌표  

int dy[4] = { 0,-1,0,1 }; //이동할 때 쓰는 y 좌표
```

int dx[4] = { -1,0,1,0 }; //이동할 때 쓰는 x 좌표  int dy[4] = { 0,-1,0,1 }; //이동할 때 쓰는 y 좌표int dx[4] = { -1,0,1,0 }; //이동할 때 쓰는 x 좌표  int dy[4] = { 0,-1,0,1 }; //이동할 때 쓰는 y 좌표