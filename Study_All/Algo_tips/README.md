[1. if return,continue 사용법](#1)

[2. 재귀](#2)

[3. 순열과 조합](#3)

[4. 공백없는 입력](#4)

[5. max,min(define) 선언](#5)

[6. vector 여러가지 선언 방법 (2,3차원 등)](#6)

[7. enum](#7)

[8. 이동좌표 ](#8)

[9. memset , memcpy ](#9)

[11. #includ <string> ](#11)

[12. char  string 변환 ](#12)

[13. 16진수 10진수 변환 ](#13)

[14. is_Range()](#14)

[15.엔터입력시 종료](#15)

[16. goto문](#16)

[17.for문 ](#17)

[18.string-> int 변환](#18)

[19.아스키코드 A -> 0 변환](#19)

[20.for 문](#20)

[21.auto](#21)

[22.명시적 형 변환 (Explict type conversion)](#22)



# 1

## if return,continue 사용법

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



# 2

## 재귀

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



# 4

## 공백없는 입력

```    
scanf_s("%1d",&map[i][j])
```



# 5

## max,min(define) 선언

```
#define max(a,b) (a < b ? a : b)

#define min(a,b) (a < b ? a : b)

#define MAX 987654321;
```



# 6

##  vector 여러가지 선언 방법 (2,3차원 등)

```
vector <  int  > v;

vector < pair < int, int > > v;

vector < pair < int, int > > vv[MAX];

vector < pair < pair < int, int >, int > > v;
```



# 7

##  enum

```
enum { PATH = 1 ,...}; 
```



C++에는 많은 자료형이 내장되어 있다. 하지만 이 자료형들이 원하는 걸 표현하기에 항상 충분하지는 않다. 그래서 C++은 프로그래머들이 자신만의 자료형을 만들 수 있게 해 주는 기능을 포함하고 있다. 이러한 자료형을 사용자 정의 자료형이라고 한다.

아마도 가장 간단한 사용자 정의 자료형은 열거된 유형일 것이다. 열거된 유형(열거형이라고도 함)은 가능한 모든 값이 기호 상수(열거형)로 정의되는 자료형이다. 열거형은 `enum` 키워드를 통해 정의된다.

```
// Color라는 새로운 열거형(enum)을 정의한다.
enum Color
{
    // 열거자(enumerator)
    // 각 열거자는 세미콜론(;)이 아니라 쉼표(,)로 구분된다.
    COLOR_BLACK,
    COLOR_RED,
    COLOR_BLUE,
    COLOR_GREEN,
    COLOR_WHITE,
    COLOR_CYAN,
    COLOR_YELLOW,
    COLOR_MAGENTA,
}; // 그러나 enum 자체는 세미콜론으로 끝나야 한다.

// 열거형 Color의 변수들 정의
Color paint = COLOR_WHITE;
Color house(COLOR_BLUE);
Color apple { COLOR_RED };
```

열거형을 정의해도 메모리는 할당되지 않는다. 열거된 유형의 변수가 정의된 경우, 해당 변수에 대해 메모리가 할당된다.

각 열거자는 쉼표(,)로 구분되고, 전체 열거는 세미콜론(;)으로 끝난다.

------

#### Naming enums

`enum` 식별자는 대문자로 시작하는 경우가 많으며, 열거자(enumerator)는 종종 모두 대문자로 이름이 지어진다. 열거자는 열거와 같은 네임스페이스에 배치되므로, 열거자 이름은 같은 네임스페이스 내의 여러 열거(enum)에서 사용할 수 없다.

```
enum Color
{
    RED,
    BLUE, // BLUE is put into the global namespace
    GREEN
};

enum Feeling
{
    HAPPY,
    TIRED,
    BLUE // error, BLUE was already used in enum Color in the global namespace
};
```

따라서 이름 충돌을 방지하기 위해 열거자 앞에 ANIMAL *또는 COLOR*와 같은 접두어를 붙이는 것이 일반적이다.

------

#### Enumerator values

각 열거자는 열거 목록의 위치에 따라 정수 값이 자동으로 할당된다. 기본적으로 첫 번째 열거자에는 정수 값 0이 할당되며, 각 이후 열거자에는 이전 열거자보다 1 더 큰 값이 할당된다.

```
enum Color
{
    COLOR_BLACK, // assigned 0
    COLOR_RED,   // assigned 1
    COLOR_BLUE,  // assigned 2
    COLOR_GREEN, // assigned 3
    COLOR_WHITE, // assigned 4
    COLOR_CYAN,  // assigned 5
    COLOR_YELLOW,// assigned 6
    COLOR_MAGENTA// assigned 7
};

Color paint(COLOR_WHITE);
std::cout << paint;      // 4
```

위 프로그램은 4를 출력한다.

열거자의 값을 명시적으로 정의할 수 있다. 이러한 정수 값은 양 또는 음의 값일 수 있으며 다른 열거자와 같은 값을 공유할 수 있다. 정의되지 않은 모든 열거자는 이전 열거자보다 1 더 큰 값이 부여된다.

```
enum Animal
{
    ANIMAL_CAT     = -3,
    ANIMAL_DOG,    // assigned -2
    ANIMAL_PIG,    // assigned -1
    ANIMAL_HORSE   = 5,
    ANIMAL_GIRAFFE = 5, // shares same value as ANIMAL_HORSE
    ANIMAL_CHICKEN // assigned 6
};
```

------

#### Enum type evaluation and input/output

열거형 값은 정수로 평가되므로 정수 변수에 할당할 수 있다. `std:cout`은 정수 출력 방법을 알고 있으므로 정수로 출력할 수도 있다.

```
int mypet = ANIMAL_PIG;
std::cout << ANIMAL_HORSE; // evaluates to integer before being passed to std::cout
// 5
```

컴파일러는 정수를 열거형 값으로 암시적으로 변환하지 않는다. 다음과 같은 경우 컴파일러 오류가 발생한다.

```
Animal animal = 5; // will cause compiler error
```

그러나 `state_cast`를 통해 강제로 변환할 수 있다.

```
Color color = static_cast<Color>(5); // ugly
```

또한, 컴파일러는 std:cin을 사용하여 열거형을 입력할 수 없다.

```
enum Color
{
    COLOR_BLACK, // assigned 0
    COLOR_RED,   // assigned 1
    COLOR_BLUE,  // assigned 2
    COLOR_GREEN, // assigned 3
    COLOR_WHITE, // assigned 4
    COLOR_CYAN,  // assigned 5
    COLOR_YELLOW,// assigned 6
    COLOR_MAGENTA// assigned 7
};

Color color;
std::cin >> color; // will cause compiler error
```

한가지 해결 방법은 정수를 읽고, `static_cast`를 사용하여 컴파일러가 정수 값을 열거형으로 입력하도록 하는 것이다.

```
int inputColor;
std::cin >> inputColor;

Color color = static_cast<Color>(inputColor);
```

열거형은 고유한 자료형으로 간주한다. 따라서 열거형에 다른 열거형을 할당하려고 하면 컴파일 오류가 발생한다.

```
Animal animal = COLOR_BLUE; // will cause compiler error
```

상수(const) 변수와 마찬가지로 열거형은 디버거에 표시되므로 `#define`보다 유용하다.

또한, 열거형은 정수 자료형의 일부로 간주하므로 열거형 변수에 할당할 메모리 크기는 컴파일러에 따라 결정된다. C++ 표준에 따르면 열거형 크기는 모든 열거형 값을 나타낼 만큼 커야 한다. 대부분 열거형 변수는 표준 int와 같은 크기다.

------

#### 열거형은 언제 유용할까?

열거형은 특정한 상태 집합을 나타내야 할 때 코드 문서화 및 가독성 목적으로 매우 유용하다.

예를 들어 함수는 함수 내부에 문제가 발생했을 때 오류 코드를 나타내기 위해 호출자에게 정수를 반환하는 경우가 많다. 일반적으로 오류 코드를 나타내는 데는 음수가 사용된다.

```
int readFileContents()
{
    if (!openFile())
        return -1;
    if (!readFile())
        return -2;
    if (!parseFile())
        return -3;

    return 0; // success
}
```

하지만 매직 넘버를 사용하는 것은 좋지 않다. 대신에 열거형을 사용하는 게 좋다.

```
enum ParseResult
{
    SUCCESS = 0,
    ERROR_OPENING_FILE = -1,
    ERROR_READING_FILE = -2,
    ERROR_PARSING_FILE = -3
};

ParseResult readFileContents()
{
    if (!openFile())
        return ERROR_OPENING_FILE;
    if (!readFile())
        return ERROR_READING_FILE;
    if (!parsefile())
        return ERROR_PARSING_FILE;

    return SUCCESS;
}
```

위 코드는 매직 넘버를 반환하는 것보다 훨씬 가독성이 좋다. 또한, 호출자는 해당 열거자에 대해 함수의 반환 값을 테스트할 수 있으며, 이는 특정 정수 값에 대한 반환 결과를 테스트하는 것보다 이해하기 쉽다.

```
if (readFileContents() == SUCCESS)
{
    // do something
}
else
{
    // print error message
}
```

열거형은 관련 집합을 정의할 때도 사용하기 좋다. 예를 들어, 플레이어가 아이템 하나만 가지고 다닐 수 있는 게임을 만든다고 해보자. 아이템은 여러 가지 종류가 있다.

```
#include <iostream>
#include <string>

enum ItemType
{
    ITEMTYPE_SWORD,
    ITEMTYPE_TORCH,
    ITEMTYPE_POTION
};

std::string getItemName(ItemType itemType)
{
    if (itemType == ITEMTYPE_SWORD)
        return std::string("Sword");
    if (itemType == ITEMTYPE_TORCH)
        return std::string("Torch");
    if (itemType == ITEMTYPE_POTION)
        return std::string("Potion");

    // Just in case we add a new item in the future and forget to update this function
    return std::string("???");
}

int main()
{
    // ItemType is the enumerated type we've defined above.
    // itemType (lower case i) is the name of the variable we're defining (of type ItemType).
    // ITEMTYPE_TORCH is the enumerated value we're initializing variable itemType with.
    ItemType itemType = ITEMTYPE_TORCH;

    std::cout << "You are carrying a " << getItemName(itemType) << "\n";

    return 0;
}
```

많은 프로그래밍 언어에서 불리언(boolean)을 정의하기 위해 열거형을 사용한다. 부울(`bool`)은 기본적으로 `false`와 `true`의 두 열거자를 가진 열거형이다. 그러나 C++에서 `true`와 `false`는 열거자 대신 키워드로 정의되어있다.

 

# 8 

##  이동 좌표 

int dx[4] = { -1,0,1,0 }; //이동할 때 쓰는 x 좌표  int dy[4] = { 0,-1,0,1 }; //이동할 때 쓰는 y 좌표

```
int dx[4] = { -1,0,1,0 }; //이동할 때 쓰는 x 좌표  

int dy[4] = { 0,-1,0,1 }; //이동할 때 쓰는 y 좌표
```

int dx[4] = { -1,0,1,0 }; //이동할 때 쓰는 x 좌표  int dy[4] = { 0,-1,0,1 }; //이동할 때 쓰는 y 좌표int dx[4] = { -1,0,1,0 }; //이동할 때 쓰는 x 좌표  int dy[4] = { 0,-1,0,1 }; //이동할 때 쓰는 y 좌표

int dx[4] = { -1,0,1,0 }; //이동할 때 쓰는 x 좌표  int dy[4] = { 0,-1,0,1 }; //이동할 때 쓰는 y 좌표int dx[4] = { -1,0,1,0 }; //이동할 때 쓰는 x 좌표  int dy[4] = { 0,-1,0,1 }; //이동할 때 쓰는 y 좌표



## 9.

##  memset , memcpy

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


# 10

##  알파벳 -> 숫자

```
s[0] - 'A' 
```



# 11

##  #include <string>

```
string s  

cin>>s;  //벡터처럼 배열에 저장 
```

![스크린샷 2018-08-27 오후 10.10.48](/Users/PARKHASIK/Desktop/스크린샷 2018-08-27 오후 10.10.48.png)

![스크린샷 2018-08-27 오후 10.10.59](/Users/PARKHASIK/Desktop/스크린샷 2018-08-27 오후 10.10.59.png)

![스크린샷 2018-08-27 오후 10.11.11](/Users/PARKHASIK/Desktop/스크린샷 2018-08-27 오후 10.11.11.png)

![스크린샷 2018-08-27 오후 10.11.21](/Users/PARKHASIK/Desktop/스크린샷 2018-08-27 오후 10.11.21.png)



# 12

##  char  string 변환

```
string oneN; 

for(int jj=0;jj<number_pwd.size();jj++){

           numn[jj]=number_pwd[jj]; //number_pwd는 벡터배열

        }

 oneN=numn;

//벡터char배열에서 string 으로는 변환 불가능 
그래서 char형 배열에서 string 값으로 변환 
```



# 13

##  16진수 10진수 변환

```
   char *s = (char*) oneN.c_str();
                  // ----string 형을 char포인터로 바꾼다.

   long aa = strtol(s, NULL, 16);
            //long (16진수 수가 크기때문)형으로 10진수로 변환
```



# 14

##  is_Range()

```
bool is_range(int x, int y){

    return(x>=0&&x<n&&y>=0&&y<n);

} //이 범위 안이면 리턴
```



# 15

##  엔터입력시 종료

```
  do {

        scanf("%d", &va);

    } while (getc(stdin) == ' ');


```



# 16

##  goto문

```
#include <stdio.h>  
int main()  
{  
    int i, j;  
  
    for ( i = 0; i < 10; i++ )  
    {  
        printf_s( "Outer loop executing. i = %d\n", i );  
        for ( j = 0; j < 2; j++ )  
        {  
            printf_s( " Inner loop executing. j = %d\n", j );  
            if ( i == 3 )  
                goto stop;  
                //stop 이 있는곳으로 간다
        }  
    }  
  
    // This message does not print:   
    printf_s( "Loop exited. i = %d\n", i );  
  
    stop:   
    printf_s( "Jumped to stop. i = %d\n", i );  
}  
```

 

# 17

##  for문 

```
nt array[5] = { 9, 7, 5, 3, 1 }; 

for (auto element: array) // element will be a copy of the current array element 

std::cout << element << ' '; 
```



# 18 

##  string-> int 변환 

**1) 함수 설명**

- **int atoi (const char \* str)**
  헤더파일(C) : <stdlib.h>
  헤더파일(CPP) : <cstdlib>
  설명 : C style의 문자열을 입력받아서 int (숫자) 타입으로 변환하여 리턴한다.

- **std::string c_str()** 
  반환형이 char * 이므로, 해당하는 string의 첫번재 문자의 주소값(포인터)를 반환합니다.
  사용방법은 아래에 나와있습니다.

  

  **{Test 1} char\* --> string** 

   : C style의 char * 형을 C++ style의 string 으로 변환.

  ```
  char * cStr = "Cstring";
  string cppStr = cStr;
   
  cout << "[test1] : char * --> string " << endl;
  cout << "==> cppStr : " << cppStr << endl << endl;
  ```

  Test 1 : 결과

  ![img](https://t1.daumcdn.net/cfile/tistory/2629DF3859632F9814)

  

  

  **{Test 2} string --> char \***

    : C++의 string을 C style의 char * 형으로 변환.

  ```
  string cppStr = "CPPstring";
  const char * cStr2 = cppStr.c_str();
  
  
  cout << "[test2] : string --> char *" << endl;
  printf("==> printf > cStr2 : %s\n", cStr2);
  cout << "==> cout > cStr2 : " << cStr2 << endl << endl;
  ```

  

  Test 2 : 결과

  ![img](https://t1.daumcdn.net/cfile/tistory/250E7D35596330671F)

  

  

  **{Test 3} char \* --> int**

    : C style의 char * 를 int 타입으로 변환.

  ```
  char * cStr = "20170711";
  int num = atoi(cStr);
  
  printf("printf : %d\n", ++num);  //증가 후 출력.
  cout <<"cout : "<< ++num << endl;//증가 후 출력.
  ```

  

  Test 3 : 결과

  ![img](https://t1.daumcdn.net/cfile/tistory/26016E485963327529)

   

  

  **{Test 4} string --> char \* --> int (한번에 int로 변환)**

    : C++의 string을 int 타입으로 한번에 변환.

  ```
  string s = "2017";
  int num = atoi(s.c_str());
  
  printf("printf : %d\n", ++num);     //증가 후 출력
  cout << "cout : " << ++num << endl; //증가 후 출력.
  ```

  

  Test 4 : 결과

  ![img](https://t1.daumcdn.net/cfile/tistory/2633904A5963328829)

  

  

  # 19

  ##  아스키코드 A -> 0 변환

  ```
   cin >> A;
   int Aa = A - 65;
   cout<< Aa;
  ```



# 20

##  for 문

```
#include <iostream>
using namespace std;

int main() {

   int array[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
   for (int number : array) // number 에 모든 array[] 안의 값 array[0],array[1].. 를 출력
      cout << number << ' ';

    for (auto number : array) // auto 를 하면 모든 타입 가능
        cout << number << ' ';
    return 0;

}
```

> `element_declaration`은 배열 요소와 같은 자료형을 가져야 하므로, auto 키워드를 사용해서 C++이 자료형을 추론하도록 하는 것이 이상적이다.(auto 사용)
>
> 

#### Ranged-based for loops and references

위에서 본 예제들에서 `element_declaration`은 값으로 선언된다.

```
int array[5] = { 9, 7, 5, 3, 1 };
    for (auto element: array) // element will be a copy of the current array element
        std::cout << element << ' ';
```

반복된 각 배열 요소가 `element`에 복사된다. 배열 요소를 복사하는 것은 비용이 많이들 수 있다. 다행히도 다음과 같이 참조를 사용할 수 있다.

```
int array[5] = { 9, 7, 5, 3, 1 };
    for (auto &element: array) // The ampersand makes element a reference to the actual array element, preventing a copy from being made
        std::cout << element << ' ';
```

위 예제에서 `element`는 현재 반복된 배열 요소에 대한 참조이므로 값이 복사되지 않는다. 또한, `element`를 수정하면 배열의 요소에 영향을 미친다.

읽기 전용으로 사용하려는 경우 `element`를 const로 만드는 것이 좋다.

```
int array[5] = { 9, 7, 5, 3, 1 };
    for (const auto& element: array) // element is a const reference to the currently iterated array element
        std::cout << element << ' ';
```

*성능상의 이유로 ranged-based for 루프에서 참조 또는 const 참조를 사용하는 게 좋다.*



#### Ranged-based for loops and non-arrays

범위 기반 for 루프(ranged-based for loop)는 고정 배열뿐만 아니라 `vector`, `list`, `set`, `map`과 같은 구조에서도 작동한다. ranged-based for 문이 유연하다

```
#include <vector>
#include <iostream>
using namespace std;

int main()
{
   vector<int> fibonacci = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 }; 
   // note use of vector here rather than a fixed array
   for (const auto& number : fibonacci)
      	cout << number << ' ';

    return 0;
}
```



#### Ranged-based for loops doesn’t work with pointers to an array

포인터로 변환된 배열에서 범위 기반 for 루프를 사용할 수 없다. (배열의 크기를 알지 못하기 때문이다.)

```
#include <iostream>
using namespace std;

int sumArray(int array[]) // array is a pointer
{
    int sum = 0;
    for (const auto& number : array) // compile error, the size of array isn't known
        sum += number;

    return sum;   
}

int main()
{
     int array[5] = { 9, 7, 5, 3, 1 };
     cout << sumArray(array); // array decays into a pointer here
     return 0;
}
```

[출처](https://boycoding.tistory.com/210)

# 21

##  auto

#### C++ 11에서 타입 추론 (Type inference in C++ 11)

C++ 11에서 `auto` 키워드는 유용하다.

```
double d = 5.0;
```

5.0이 부동 소수점 숫자 리터럴이라는 것을 이미 알고 있다면, 왜 d의 타입(=자료형)을 `double`이라고 명시적으로 선언해야 할까? 변수를 초기화할 때 사용하는 값을 기준으로 적절한 타입을 추론하도록 하면 편하지 않을까?

auto 키워드는 선언된 변수의 초기화 식을 사용하여 해당 형식을 추론하도록 컴파일러에 지시한다.

즉, **auto 키워드를 사용하면 초깃값의 형식에 맟춰 선언하는 인스턴스(변수)의 형식이 '자동'으로 결정된다.** 이것을 **타입 추론(type inference)**이라고 한다.

```
auto d = 5.0;   // 5.0 is a double literal, so d will be type double
auto i = 1 + 2; // 1 + 2 evaluates to an integer, so i will be type int
```

변수를 함수의 반환 값으로 초기화 할 때도 사용 가능하다.

```
int add(int x, int y)
{
    return x + y;
}

int main()
{
    auto sum = add(5, 6); // add() returns an int, so sum will be type int
    return 0;
}
```

주의: 이 기능은 생성 시 변수를 초기화할 때만 작동한다. 초기화 값을 사용하지 않고 생성된 변수는 이 기능을 사용할 수 없다.

------



#### auto 키워드는 함수 매개 변수와 함께 사용할 수 없다. (The auto keyword can’t be used with function parameters)

```
#include <iostream>

void addAndPrint(auto x, auto y)
{
    std::cout << x + y;
}
```

위 코드는 작동하지 않는다. 컴파일러가 컴파일 시 함수 매개 변수 x와 y에 대한 타입을 추론할 수 없기 때문이다.

------



#### C++ 14에서 함수를 위한 타입 추론 (Type inference for functions in C++14)

C++ 14는 `auto` 키워드가 함수의 반환 타입을 자동으로 추론할 수 있도록 확장되었다.

```
auto add(int x, int y)
{
    return x + y;
}
```

`x + y`는 정수로 평가되기 때문에 컴파일러는 `add()` 함수가 `int` 타입의 반환 값을 가져야 한다고 추론한다.

위 문법은 좋아 보일 수도 있지만 사용하지 않는 게 좋다. 함수의 반환 타입은 호출자가 함수에서 어떤 값을 반환할지 예상하는데, auto 키워드를 사용하면 잘못 해석할 수 있으며, 이로 인해 의도하지 않은 오류가 발생할 수 있다.

[출처](https://boycoding.tistory.com/210)



# 22

##  명시적 형 변환 (Explict type conversion)

이전 포스트 '[05.01 - 암시적 형 변환 (Implict type conversion)](http://boycoding.tistory.com/176?category=1008283)'에서 컴파일러가 어떤 경우 자료형 간의 값을 암시적으로 변환한다는 것을 배웠다. 한 자료형의 값을 더 큰 자료형으로 승격하려면 암시적 형 변환 시스템을 사용해도 좋다.

초보 프로그래머들은 `float f = 10 / 4;`와 같은 걸 시도한다. 그러나 10과 4는 모두 정수이므로 "숫자 승격"이 일어나지 않는다. 정수값 나누기 표현식 `10 / 4`는 2의 값을 생성하고, 그 값은 암시적으로 2.0으로 변환되어 변수 `f`에 할당된다.

위 같은 경우에는 정수 리터럴 값(Ex. 2, 4)중 하나를 부동 소수점 숫자 리터럴 값(Ex. 2.0, 4.0)으로 바꾸면 나누기는 부동 소수점 숫자 나누기로 수행될 것이다.

하지만 변수를 사용하는 경우 어떻게 될까? 다음 예제를 보자.

```
int i1 = 10;
int i2 = 4;
float f = i1 / i2;
```

변수 `f`의 값은 2로 끝난다. 정수 나누기 대신 부동 소수점 숫자 나누기를 한다고 컴파일러에 어떻게 말할까? 답은 "형 변환 연산자"를 사용해야 한다. 형 변환 연산자를 사용해서 컴파일러에 **명시적 형 변환**을 하도록 지시해야 한다.

------

#### 형 변환 (Type casting)

C++에는 `C-style cast`, `static_cast`, `const_cast`, `dynamic_cast`, 그리고 `reinterpret_cast`와 같은 5가지 변환 방식이 있다.

이 포스트에서는 `C-style cast`와 `static_cast`를 다룬다.

#### C-style cast

표준 C 프로그래밍에서는 `()`연산자에 변환할 자료형의 이름을 사용해 형 변환한다.

```
int i1 = 10;
int i2 = 4;
float f = (float)i1 / i2;
```

위 프로그램에서는 컴파일러가 `i1`을 부동 소수점 값으로 변환하기 위해서 `(float)`을 사용한다. `i1`은 이제 부동 소수점 값이므로 `i2`는 부동 소수점 값으로 변환되며, 정수 나누기 대신 부동 소수점 나누기를 수행한다.

C++ 에서는 다음과 같이 함수적인 C-style cast를 사용할 수 있다.

```
int i1 = 10;
int i2 = 4;
float f = float(i1) / i2;
```

C-style cast는 컴파일 시간에 검사되지 않으므로 오용될 수 있다. (const를 제거하는 등) 그러므로 C-style cast는 일반적으로 피하는 게 좋다.

#### static_cast

C++ 에서는 `static_cast`라는 형 변환 연산자를 도입했다. 이전에 '[02.08 - 문자 (char)](http://boycoding.tistory.com/154?category=1007180)' 포스트에서 `static_cast`를 사용하여 `char`을 `int`로 변환하여 `std :: cout`이 `char` 대신 정수로 출력하도록 했었다.

```
char c = 'a';
std::cout << static_cast<int>(c) << std::endl; // prints 97, not 'a'
```

`static_cast`는 하나의 자료형을 다른 자료형으로 변환하는 데 가장 좋은 방법이다.

```
int i1 = 10;
int i2 = 4;
float f = static_cast<float>(i1) / i2;
```

static_cast의 주요 장점은 컴파일 타임에 타입 검사를 제공하여 부주의한 오류를 만들기가 더 어렵다는 것이다. satic_cast는 C-style cast보다 덜 강력하여서 실수로 `const`를 제거하는 등 의도하지 않은 작업을 할 확률을 줄여준다.

컴파일러는 안전하지 않은 암시적 형 변환을 할 때마다 불평한다.

```
int i = 48;
char ch = i; // implicit conversion
```

int(4-byte)를 char(1-byte)로 변환하면 잠재적으로 안전하지 않으므로 컴파일러는 불평한다. 이 형 변환을 사용자가 인지하고 사용한다는 것을 알리기 위해 다음과 같이 형 변환 연산자를 사용하면 된다.

```
int i = 48;
char ch = static_cast<char>(i);
```

다음 프로그램에서 컴파일러는 `double`을 `int`로 변환하면 데이터 손실이 발생할 수 있다고 불평한다.

```
int i = 100;
i = i / 2.5;
```

명시적인 의미를 컴파일러에 알려주면 된다.

```
int i = 100;
i = static_cast<int>(i / 2.5);
```

------

#### 정리 (Summary)

형 변환을 할 때마다 문제가 발생할 가능성이 있으므로 가능하면 형 변환을 피해야 한다. 그러나 피할 수 없는 경우, C-style cast 대신 C++의 `static_cast`를 사용해야 한다.

