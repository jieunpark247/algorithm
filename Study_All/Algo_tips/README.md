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

초기화 할때 재귀돌아가는 곳 안에 할것인지 아닌지 잘 살펴보기 

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
		
	   vector<int> ind;
        
        int k = ...;
        
        for (int i = 0; i < ...; i++) {
            ind.push_back(1);
        }
        for (int i = 0; i < ///// - ....; i++) {
            ind.push_back(0);
        }
        sort(ind.begin(), ind.end(),greater<int>());
        
        do { //순열 돌리기
          
            for (int i = 0; i < ind.size(); i++) {
                if (ind[i] == 1) {
                  
                    
                }
            }
          
            
        }
        
        while (next_permutation(ind.begin(), ind.end(),greater<int>()));


```
:  순열 만들기



```
sort(v.begin(), v.end());  
sort(ind.begin(), ind.end(),greater<int>());
```
:  오름차순 정렬 , 내림차순

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
enum { PATH = 1 ,...}; 
```

 

## 8. 이동 좌표 

int dx[4] = { -1,0,1,0 }; //이동할 때 쓰는 x 좌표  int dy[4] = { 0,-1,0,1 }; //이동할 때 쓰는 y 좌표

```
int dx[4] = { -1,0,1,0 }; //이동할 때 쓰는 x 좌표  

int dy[4] = { 0,-1,0,1 }; //이동할 때 쓰는 y 좌표
```

int dx[4] = { -1,0,1,0 }; //이동할 때 쓰는 x 좌표  int dy[4] = { 0,-1,0,1 }; //이동할 때 쓰는 y 좌표int dx[4] = { -1,0,1,0 }; //이동할 때 쓰는 x 좌표  int dy[4] = { 0,-1,0,1 }; //이동할 때 쓰는 y 좌표

int dx[4] = { -1,0,1,0 }; //이동할 때 쓰는 x 좌표  int dy[4] = { 0,-1,0,1 }; //이동할 때 쓰는 y 좌표int dx[4] = { -1,0,1,0 }; //이동할 때 쓰는 x 좌표  int dy[4] = { 0,-1,0,1 }; //이동할 때 쓰는 y 좌표



## 9. memset , memcpy

1. 

```
#include <string.h>

void * memset (void * s, int c, size_t n);
```

memset 은 말 그대로 해당 영역의 memory 데이터를 c로 초기화 하는 것을 뜻한다.

 

```
int test1[5] ;  

memset( test1, 0, 5, * sizeof(int) ) ;
```

>   int 형의 크기가 5인 배열에 값을 0으로 초기화 하는것



```
memset(visited, 0, sizeof(visited)); 
```

>  visited 배열을 visited 크기만큼 0으로 초기화 시킴 



2. 

```
#include <string.h>

void *memcpy(void *dest, const void *src, size_t n);
		
```

memcpy의 경우 *dest의 값을 src의 값으로 복사하는 것을 뜻한다.

이 경우도 count의 값 만큼 dest의 시작 메모리 주소값에서 부터 메모리 영역에 복사하는 것

[memcpy](https://www.joinc.co.kr/modules/moniwiki/wiki.php/manSearch?google=none&name=memcpy)() 함수는 포인터 dest 를 반환한다.

ex>

```
#include <unistd.h>

#include <string.h>

struct mydata
{
    int age;
    int weight; 

    char name[16];
    char juso[80];
};

int main()
{
    struct mydata data;
    struct mydata *mdata;
    char f_data[120];
    int my_weight;

    data.age    = 29;
    data.weight = 64;

    strcpy(data.name, "yundream"); 
    strcpy(data.juso, "seoul korea");

    memset(f_data, 0x00, 120);
    
    // data 구조체를 f_data 로 메모리 복사한다.  
    memcpy(f_data, (void *)&data, sizeof(struct mydata));

    mdata = (void *)&f_data; 

    printf("pcopy %d\n", mdata->age);

    memcpy((void *)&my_weight, f_data+4, sizeof(int)); 

    printf("%d\n", my_weight);
} 
```
## 10. 알파벳 -> 숫자

```
s[0] - 'A' 
```



## 11. #include <string>

```
string s  

cin>>s;  //벡터처럼 배열에 저장 
```

![스크린샷 2018-08-27 오후 10.10.48](/Users/PARKHASIK/Desktop/스크린샷 2018-08-27 오후 10.10.48.png)

![스크린샷 2018-08-27 오후 10.10.59](/Users/PARKHASIK/Desktop/스크린샷 2018-08-27 오후 10.10.59.png)

![스크린샷 2018-08-27 오후 10.11.11](/Users/PARKHASIK/Desktop/스크린샷 2018-08-27 오후 10.11.11.png)

![스크린샷 2018-08-27 오후 10.11.21](/Users/PARKHASIK/Desktop/스크린샷 2018-08-27 오후 10.11.21.png)



## 12. char  string 변환

```
string oneN; 

for(int jj=0;jj<number_pwd.size();jj++){

           numn[jj]=number_pwd[jj]; //number_pwd는 벡터배열

        }

 oneN=numn;

//벡터char배열에서 string 으로는 변환 불가능 
그래서 char형 배열에서 string 값으로 변환 
```



## 13. 16진수 10진수 변환

```
   char *s = (char*) oneN.c_str();
                  // ----string 형을 char포인터로 바꾼다.

   long aa = strtol(s, NULL, 16);
            //long (16진수 수가 크기때문)형으로 10진수로 변환
```

