[1. if return,continue 사용법](#1)

[2. 재귀](#2)

[3. 순열과 조합](#3)

[4. 공백없는 입력](#4)

[5. max,min(define) 선언](#5)

[6. vector](#6)

[7. enum](#7)

[8. 이동좌표 ](#8)

[9. memset , memcpy ](#9)

[11. string ](#11)

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

[23.Switch](#23)

[24.비트 단위 연산자](#24)

[25. priority queue](#25)

[26. queue 초기화 시키기](#26)

[27. 여러가지 방법](#27)

[28. 레퍼런스&](#28)

[29. 마름모 영역 구하기](#29)

[30. ](#30)



# 1

### if return,continue 사용법

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

### 재귀

재귀를 쓸 때 안끝난 채로 재귀에 들어가기 때문에 조건에 부합하지 않아 함수가 끝난다면 다른 경우의 수를 수행하게끔 **백트래킹**을 하여 경우의 수가 끝날 때 까지 수행한다. 

초기화 할때 재귀돌아가는 곳 안에 할것인지 아닌지 잘 살펴보기 



# 3 

###  순열과 조합 

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

### max,min(define) 선언

```
#define max(a,b) (a < b ? a : b)

#define min(a,b) (a < b ? a : b)

#define MAX 987654321;
```



# 6

### Vector



####  vector 여러가지 선언 방법 (2,3차원 등)

```
vector <  int  > v; //1차원

vector < pair < int, int > > v; //pair (make_pair)

vector <  int  > v[10]; //2차원
vector < vector <int> > v;

vector < pair < int, int > > vv[MAX]; //3차원
vector < pair < pair < int, int >, int > > v;
```

#### vector erase

```
int i // i번째 것을 지우고 싶을때 

vector <int> v;

v.erase(v.begin()+i);

# 
```



- **v.assign(5, 2);**- 2의 값으로 5개의 원소 할당.
- **v.at(idx);**- idx번째 원소를 참조
  \- v[idx] 보다 속도는 느리지만, 범위를 점검하므로 안전함
- **v[idx];**- idx 번째 원소를 참조
  \- 범위를 점검하지 않으므로 속도가 v.at(idx)보다 빠름
- **v.front();**- 첫번째 원소를 참조
- **v.back();**- 마지막 원소를 참조
- **v.clear();**- 모든 원소를 제거
  **- 원소만 제거하고 메모리는 남아있음**
  \- size만 줄어들고 capacity는 그대로 남아있음
- **v.push_back(7);**- 마지막 원소 뒤에 원소 7을 삽입
- **v.pop_back();**- 마지막 원소를 제거
- **v.begin();**- 첫번째 원소를 가리킴. (iterator와 사용)
- **v.end();**- 마지막의 "다음"을 가리킴(iterator와 사용)
- **v.rbegin();**- reverse begin을 가리킴(거꾸로 해서 첫번째 원소를 가리킴)
  \- iterator와 사용.
- **v.rend();**- reverse end 을 가리킴 (거꾸로 해서 마지막의 다음을 가리킴)
  \- iterator와 사용.
- **v.reserve(n);**- n개의 원소를 저장할 위치를 예약(미리 동적할당 해놓음)
- **v.resize(n);**- 크기를 n으로 변경
  \- 더 커졌을 경우 default값인 0으로 초기화 

- **v.resize(n,3);**- 크기를 n으로 변경
  \- 더 커졌을 경우 인자의 값을 3으로 초기화

- **v.size();**- 원소의 갯수를 리턴한다.

- **v.capacity();**- 할당된 공강의 크기를 리턴한다
  \- 공간 할당의 기준은 점점 커지면서로 capacity를 할당
  \- dev c++ 기준으로 string 클래스로 vector 를 만들었을때.
  원소 갯수 1 => capacity 1   원소 갯수 2 => capacity 2
  원소 갯수 3 => capacity 4   원소 갯수 4 => capacity 4
  원소 갯수 5 => capacity 8   원소 갯수 6 => capacity 8
  원소 갯수 7 => capacity 8   원소 갯수 8 => capacity 8
  원소 갯수 9 => capacity 16
  이런식으로 메모리 할당을 하는 이유는 push_back이 일어날때 마다 동적할당을 하면,
  비효율적이므로 미리 정해둔 만큼 동적할당을 한번에 한다.   

  **capacity와 size는 다름**

  ##### size()는 메모리에 들어있는 값들의 갯수  vs capacity 는 전체 할당된 배열 크기 

  

- **v2.swap(v1);**- v1과 v2의 원소와 capacity 바꿔줌. (모든걸 스왑해줌)
  - v1의 capacity를 없앨때 (할당한 메모리를 프로그램이 끝나기 전에 없애고 싶을때) 사용하기도 함
  - v2를 capacity가 0인 임시 객체로 만들어서 스왑을 해줌.
  - `vector<int>().swap(v1);`
- **v.insert(2, 3, 4);**- 2번째 위치에 3개의 4값을 삽입 (뒤엣놈들은 뒤로 밀림)
- **v.insert(2, 3);**- 2번째 위치에 3의 값을 삽입
  \- 삽입한 곳의 iterator를 반환
- **v.erase(iter);**- iter 가 가리키는 원소를 제거
  \- size만 줄어들고 capacity(할당된 메모리)는 그대로 남는다
  \- erase는 파라미터 하나를 받을때와 두개를 받을 때 다름

- **v.empty()**
  \- vector가 비었으면 리턴 true
  \- 비어있다의 기준은 size가 0이라는 것이지, capacity와는 상관이없음

 



# 7

###  enum

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

###  이동 좌표 

int dx[4] = { -1,0,1,0 }; //이동할 때 쓰는 x 좌표  int dy[4] = { 0,-1,0,1 }; //이동할 때 쓰는 y 좌표

```
int dx[4] = { -1,0,1,0 }; //이동할 때 쓰는 x 좌표  

int dy[4] = { 0,-1,0,1 }; //이동할 때 쓰는 y 좌표
```

int dx[4] = { -1,0,1,0 }; //이동할 때 쓰는 x 좌표  int dy[4] = { 0,-1,0,1 }; //이동할 때 쓰는 y 좌표int dx[4] = { -1,0,1,0 }; //이동할 때 쓰는 x 좌표  int dy[4] = { 0,-1,0,1 }; //이동할 때 쓰는 y 좌표

int dx[4] = { -1,0,1,0 }; //이동할 때 쓰는 x 좌표  int dy[4] = { 0,-1,0,1 }; //이동할 때 쓰는 y 좌표int dx[4] = { -1,0,1,0 }; //이동할 때 쓰는 x 좌표  int dy[4] = { 0,-1,0,1 }; //이동할 때 쓰는 y 좌표



# 9

###  memset , memcpy

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

###  알파벳 -> 숫자

```
s[0] - 'A' 
```



# 11

###  #include <string>

```
string s  

cin>>s;  //벡터처럼 배열에 저장 
```



C++의 문자열을 사용하려면 먼저 `std::string`에 대한 선언을 가져오기 위해 `<string>` 헤더 파일을 `#include`해야 한다. 이 작업이 완료되면 `std::string` 타입의 변수를 정의할 수 있다.

```
#include <string>

std::string myName;
```

일반 변수와 마찬가지로, 다음과 같이 값을 초기화하거나 문자열 값을 할당할 수 있다.

```
std::string myName("Alex"); // initialize myName with string literal "Alex"
myName = "John";            // assign variable myName the string literal "John"
```

문자열에는 숫자도 포함할 수 있다.

```
std::string myID("45"); // "45" is not the same as integer 45!
```

문자열 형식에서 숫자는 숫자가 아닌 텍스트로 처리되므로 숫자처럼 조작할 수 없다. (Ex. 곱하기, 더하기 등) C++는 문자열 숫자를 정수 또는 부동 소수 점 값으로 자동 변환하지 않는다.

------

#### 문자열 입력 및 출력 (String input and output)

`std::cout`을 사용하여 문자열을 예상대로 출력할 수 있다.

```
#include <string>
#include <iostream>

int main()
{
    std::string myName("Alex");
    std::cout << "My name is: " << myName;

    return 0;
}

// My name is: Alex
```

그러나 `std:cin`과 함께 문자열을 사용하면 놀랄 일이 발생할 수 있다!

```
#include <string>
#include <iostream>

int main()
{
    std::cout << "Enter your full name: ";
    std::string name;
    std::cin >> name; // this won't work as expected since std::cin breaks on whitespace

    std::cout << "Enter your age: ";
    std::string age;
    std::cin >> age;

    std::cout << "Your name is " << name << " and your age is " << age;
}
```

```
Enter your full name: Boy Coding
Enter your age: 27
Your name is Boy and your age is Coding
```

무슨 일일까? 연산자 `>>`를 사용하여 cin에서 문자열을 추출할 때, `>>`는 첫 번째 공백까지만 반환한다. 다른 모든 문자는 cin 내부에 남겨져 다음 추출을 기달린다.

따라서 연산자 `>>`를 사용하여 문자열을 변수 `name`으로 추출할 때 "Boy"만 추출되어 std::cin 내에 "Coding"가 남겨져 다음 추출을 기다린다. `>>` 연산자를 다시 사용하여 변수 `age`에 문자열을 추출하면 "27" 대신 "Coding"가 나타난다. 세 번째 추출을 수했한다면 "27"을 얻게 될 것이다.

------

#### std::getline()을 사용한 텍스트 입력 (Use std::getline() to input text)

문자열 전체를 읽으려면 `std::getline()` 함수를 사용하는 것이 좋다. `std::getline()`은 두 개의 매개 변수가 있다. 첫 번째 매개 변수는 `std::cin`이고, 두 번째 매개 변수는 `std::string` 변수다.

```
#include <string>
#include <iostream>

int main()
{
    std::cout << "Enter your full name: ";
    std::string name;
    std::getline(std::cin, name); // read a full line of text into name

    std::cout << "Enter your age: ";
    std::string age;
    std::getline(std::cin, age); // read a full line of text into age

    std::cout << "Your name is " << name << " and your age is " << age;
}
```

```
Enter your full name: Boy Coding
Enter your age: 27
Your name is Boy Coding and your age is 27
```

#### Mixing std::cin and std::getline()

std::cin과 std::getline을 모두 사용하여 입력을 받으면 예기치 않은 동작이 발생할 수 있다.

```
#include <string>
#include <iostream>

int main()
{
    std::cout << "Pick 1 or 2: ";
    int choice { 0 };
    std::cin >> choice;

    std::cout << "Now enter your name: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Hello, " << name << ", you picked " << choice << '\n';

    return 0;
}

// pick 1 or 2: 2
// Now enter your name: Hello, , you picked 2
```

위 프로그램은 먼저 1이나 2를 입력하도록 요청하고 입력할 때까지 기다린다. 그러면 입력을 하고 난 뒤 이름을 입력해야 한다. 하지만 실제로는 이름을 입력할 때까지 기다리지 않는다! 대신 "Hello" 라인을 출력한 다음 종료한다. 무슨 일일까?

`cin`을 사용하여 숫자 값을 입력하면 `cin`은 숫자 값만 캡처할 뿐만 아니라 "\n"도 캡처한다. 그럼 `cin`은 실제로 "2\n" 문자열을 얻는다. 그런 다음 숫자 값 2를 추출해서 `choice` 변수에 할당한다. 그러면 `getline()` 함수가 이름을 읽으러 갈 때 스트림에 "\n"이 남아있는 걸 보고 빈 문자열을 입력받았다고 생각하여 `name` 변수에 빈 문자열을 할당한다. 의도했던 결과가 아니다!

`std:cin`으로 숫자 값을 읽은 후 스트림에서 "\n"을 제거하는 것이 좋다.

```
std::cin.ignore(32767, '\n'); // ignore up to 32767 characters until a \n is removed
```

`choice` 변수를 읽은 직후에 위 코드를 삽입하면, 관련 없는 개행이 스트림에서 제거되고 프로그램이 예상대로 작동한다!

```
int main()
{
    std::cout << "Pick 1 or 2: ";
    int choice { 0 };
    std::cin >> choice;

    std::cin.ignore(32767, '\n'); // ignore up to 32767 characters until a \n is removed

    std::cout << "Now enter your name: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Hello, " << name << ", you picked " << choice << '\n';

    return 0;
}
// pick 1 or 2: 2
// Now enter your name: Boy Coding
// Hello, Boycoding, you picked 2
```

`std:cin`이 포함된 숫자 값을 읽는 경우, `std:cin.ignore()`를 사용하여 관련 없는 새 라인을 제거하는 것이 좋다.



##### 매직 넘버 32767은 무엇을 의미할까?

32767은 cin::ignore() 함수가 무시할 문자 수다. 이 숫자는 모든 플랫폼에서 2-byte 정수의 가장 큰 값이다.

기술적으로 무제한 입력을 무시하는 올바른 방법은 다음과 같다.

```
#include <limits>

// ...

std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore unlimited characters until a \n is removed
```

그러나 위 코드는 길뿐만 아니라 헤더 파일까지 포함해야 한다. 대부분은 버퍼링 된 입력을 두 줄 이상 무시할 필요가 없으므로 32767을 사용하는 게 실용적이다.

------

#### 문자열 추가 (Appending strings)

연산자 `+`을 사용해서 두 문자열을 연결하거나 연산자 `+=`를 사용해서 한 문자열을 다른 문자열에 추가할 수 있다.

```
#include <string>
#include <iostream>

int main()
{
    std::string a("45");
    std::string b("11");

    std::cout << a + b << "\n"; // a and b will be appended, not added
    a += " volts";
    std::cout << a;

    return 0;
}

// 4511
// 45 volts
```

연산자 +는 문자열 "45"와 "11"을 "4511"로 연결한다. 숫자처럼 더하지 않는다.

------

#### 문자열 길이 (String length)

문자열의 길이를 알고 싶으면 length() 멤버 함수를 통해 문자열의 길이를 요청할 수 있다.

```
#include <string>
#include <iostream>
int main()

{
    std::string myName("Alex");
    std::cout << myName << " has " << myName.length() << " characters\n";
    return 0;
}

// Alex has 4 characters
```

문자열 길이를 알려면 `length(myName)` 대신 `myName.length()`를 사용한다.

length() 함수는 지금까지 사용한 것처럼 일반적인 함수가 아니며, 멤버 함수라는 std::string에 속하는 특별한 유형의 함수다. 나중에 멤버 함수에 대해 자세히 설명할 예정이다.





# 12

###  char  string 변환

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

###  16진수 10진수 변환

```
   char *s = (char*) oneN.c_str();
                  // ----string 형을 char포인터로 바꾼다.

   long aa = strtol(s, NULL, 16);
            //long (16진수 수가 크기때문)형으로 10진수로 변환
```



# 14

###  is_Range()

```
bool is_range(int x, int y){

    return(x>=0&&x<n&&y>=0&&y<n);

} //이 범위 안이면 리턴
```



# 15

###  엔터입력시 종료

```
  do {

        scanf("%d", &va);

    } while (getc(stdin) == ' ');


```



# 16

###  goto문

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

###  for문

```
nt array[5] = { 9, 7, 5, 3, 1 }; 

for (auto element: array) // element will be a copy of the current array element 

std::cout << element << ' '; 
```



# 18 

###  string-> int 변환 

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

  ###  아스키코드 A -> 0 변환

  ```
   cin >> A;
   int Aa = A - 65;
   cout<< Aa;
  ```



# 20

###  for 문

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

###  auto

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

###  명시적 형 변환 (Explict type conversion)

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



# 23

### switch

많은 `if-else` 문을 연결할 수 있지만, 이것은 가독성이 떨어져 읽기 어렵다. 아래 프로그램을 보자.

```
#include <iostream>

enum Colors
{
    COLOR_BLACK,
    COLOR_WHITE,
    COLOR_RED,
    COLOR_GREEN,
    COLOR_BLUE
};

void printColor(Colors color)
{
    if (color == COLOR_BLACK)
        std::cout << "Black";
    else if (color == COLOR_WHITE)
        std::cout << "White";
    else if (color == COLOR_RED)
        std::cout << "Red";
    else if (color == COLOR_GREEN)
        std::cout << "Green";
    else if (color == COLOR_BLUE)
        std::cout << "Blue";
    else
        std::cout << "Unknown";
}

int main()
{
    printColor(COLOR_GREEN);

    return 0;
}
```

같음을 테스트하는 단일 변수에서 `if-else` 체인을 수행하는 것이 일반적이므로 C++은 `switch`라는 조건부 분기 문을 제공한다. 위와 같은 프로그램의 `switch` 문 형태를 소개한다.

```
void printColor(Colors color)
{
    switch (color)
    {
        case COLOR_BLACK:
            std::cout << "Black";
            break;
        case COLOR_WHITE:
            std::cout << "White";
            break;
        case COLOR_RED:
            std::cout << "Red";
            break;
        case COLOR_GREEN:
            std::cout << "Green";
            break;
        case COLOR_BLUE:
            std::cout << "Blue";
            break;
        default:
            std::cout << "Unknown";
            break;
    }
}
```

`switch` 문에 대한 개념은 간단하다. `switch` 표현식이 값을 평가하고, 각 `case` 레이블의 값과 '같은' 지 테스트한다. 레이블의 값과 같으면 레이블 뒤의 명령문을 실행한다. 일치하는 레이블이 없으면 `default` 뒤의 명령문을 실행한다. (존재하는 경우)

이러한 방식으로 구현되기 때문에 `switch` 문이 `if-else` 체인보다 일반적으로 더 효율적이다.

------

#### Starting a switch

`switch` 키워드를 사용하여 `switch` 문을 시작한 다음 평가한 표현식을 사용한다. 일반적으로 이 표현식은 단 하나의 변수이지만 nx + 2 또는 nx - ny와 같이 좀 더 복잡할 수 있다. 이 표현식에 대한 한 가지 제한 사항은 정수 유형(char, short, int, long, long long, enum)으로 평가되어야 한다는 것이다. 부동 소수점 변수 및 기타 비 정수 유형은 표현식으로 사용할 수 없다.

`switch` 식 뒤에 블록을 선언한다. 블록 안에는 **레이블(label)**을 사용하여 '같음'을 테스트하려는 모든 값을 정의한다. 레이블에는 두 가지 종류가 있다.

```
switch (expression)
{
    // '같음'을 테스트하는 레이블이 들어간다.
}
```

------

#### Case labels

첫 번째 종류의 레이블은 `case` 레이블이다. `case` 키워드를 사용하여 선언된 다음 상수 표현식이 온다. 상수 표현식은 상수값을 평가하는 표현식이다. 즉, 리터럴(Ex. 5), 열거형(Ex. COLOR_REN) 또는 상수 변수(Ex. const int 자료형인 변수 x) 등이다.

`case` 레이블 다음의 상수 표현식은 `switch` 키워드 다음의 표현식과 평가된 값이 '같은'지 테스트 된다. 같을 경우, `case` 레이블 아래의 코드가 실행된다.

주의: 모든 `case` 레이블 표현식은 고유한 값으로 평가되어야 한다.

```
switch (x)
{
    // 주의: 모든 case 레이블 표현식은 고유한 값으로 평가되어야 한다.
    case 4:
    case 4:          // illegal -- already used value 4!
    case COLOR_BLUE: // illegal, COLOR_BLUE evaluates to 4!
};
```

여러 `case` 레이블이 같은 명령문을 참조하도록 할 수 있다. 다음 함수는 여러 `case`를 사용하여 `c` 매개 변수가 ASCII 숫자인지 테스트하는 기능을 가진다.

```
bool isDigit(char c)
{
    switch (c)
    {
        case '0': // if c is 0
        case '1': // or if c is 1
        case '2': // or if c is 2
        case '3': // or if c is 3
        case '4': // or if c is 4
        case '5': // or if c is 5
        case '6': // or if c is 6
        case '7': // or if c is 7
        case '8': // or if c is 8
        case '9': // or if c is 9
            // 같은 명령문을 참조한다.
            return true; // then return true
        default:
            return false;
    }
}
```

위 함수는 `c`가 ASCII 숫자인 경우, 일치하는 `case` 문 다음 첫 번째 명령문이 실행된다. (즉, `return true;`)

------

#### The default label

두 번째 종류의 레이블은 `default` 레이블이다. (defualt case라고도 불린다.) `default` 키워드를 사용하여 선언된다. 이 레이블 아래의 코드는 `switch` 표현식과 일치하는 case가 하나도 없으면 실행된다. `default` 레이블은 선택사항이며 `switch` 문당 하나만 있을 수 있다. 일반적으로 `switch` 문 블록의 마지막 레이블로 선언되지만, 반드시 필요한 것은 아니다.

위 `isDisit()` 함수 예제에서 c가 ASCII 숫자가 아닌 경우 default case가 실행되고 false를 반환한다.

------

#### Switch execution and fall-through

`switch` 문의 주의점 중 하나는 `switch` 표현식의 값과 일치 할 때 실행이 진행되는 방식이다. 값이 일치하는 `case` 레이블을 만나거나 default case 문이 실행되면 해당 레이블 다음의 첫 번째 명령문에서 실행이 시작되고, **다음과 같은 종료 조건 중 하나가 충족 될 때까지 실행이 계속된다.**

- `switch` 블록의 끝에 도달할 경우
- `return` 문이 발생할 경우
- `goto` 문이 발생할 겨우
- `break` 문이 발생할 경우
- 뭔가 다른 것이 프로그램의 정상적인 흐름을 방해할 경우 (Ex. exit() 호출, 예외 발생 등)

이러한 종료 조건 중 하나가 충족되지 않으면 case 문은 계속해서 후속 case 문으로 넘어간다.

```
switch (2)
{
   case 1: // Does not match
       std::cout << 1 << '\n'; // skipped
   case 2: // Match!
       std::cout << 2 << '\n'; // Execution begins here
   case 3:
       std::cout << 3 << '\n'; // This is also executed
   case 4:
       std::cout << 4 << '\n'; // This is also executed
   default:
       std::cout << 5 << '\n'; // This is also executed
}
```

```
result:
2
3
4
5
```

실행 흐름이 한 case에서 다른 case로 넘어가는 경우를 **fall-through**라고 한다. fall-through는 의도적인 경우가 거의 없으므로 주의해야 한다.

> fall-through는 '구멍 사이로 떨어지다'에서 유래한 말이다.

------

#### Break statements

`break` 명령문(`break` 키워드를 사용하여 선언)은 컴파일러에 이 **switch 문 사용이 완료되었음을 알려준다.**( 또는 while, do while, for 루프) `break` 문이 발생하면 `switch` 블록이 끝난다.

`break` 문이 제대로 삽입된 예제를 보자.

```
switch (2)
{
   case 1: // Does not match -- skipped
       std::cout << 1 << '\n';
       break;
   case 2: // Match!  Execution begins at the next statement
       std::cout << 2 << '\n'; // Execution begins here
       break; // Break terminates the switch statement
   case 3:
       std::cout << 3 << '\n';
       break;
   case 4:
       std::cout << 4 << '\n';
       break;
   default:
       std::cout << 5 << '\n';
       break;
}
// Execution resumes here

2
```

이제 `case 2:`가 일치하면 정수 2가 출력되고, `break` 명령문으로 인해 `switch` 문이 종료된다.

*경고: C++에서 case 문 끝에 break를 잊어 버리는 경우는 가장 흔한 오류중 하나다!*

[출처](https://boycoding.tistory.com/186?category=1009239)



# 24

### 비트 단위 연산자 (Bitwise operators)

비트 단위(bitwise) 연산자는 사용하기 어렵고 까다롭다. **비트 단위 연산자는 변수 내의 비트(bit)를 조작한다.**

과거에 메모리는 매우 비싸서 컴퓨터는 메모리를 많이 가지고 있지 못했다. 그러므로 사용 가능한 메모리를 모두 사용하려고 하는 시도가 있었다. `bool` 자료형을 생각해보자. `true`와 `false`는 1비트 하나만 사용하지만 1바이트(8비트)나 차지한다. 메모리의 가장 작은 메모리 단위는 1바이트 이기 때문인데, 이는 1비트를 사용하고 7비트를 낭비하게 된다.

bitwise 연산자를 사용하면 8개 bool 값을 한 개의 1바이트 bool 변수에 압축하여 넣을 수 있으므로 메모리를 절약할 수 있다.

오늘날에는 하드웨어 발달로 유지 보수가 쉬운 코드를 코딩하는 것이 더 좋은 아이디어다. bitwise 연산자는 최적화가 필요한 특정 상황을 제외하고는 잘 쓰이지 않는다. (Ex. 방대한 데1이터를 사용하는 프로그램, 속도를 위해 비트 연산이 필요한 게임, 내장 메모리가 작은 하드웨어)

C++ 에는 6가지의 비트 단위(bitwise) 연산자가 있다.

| Operator    | Symbol | Form   | Operation                          |
| ----------- | ------ | ------ | ---------------------------------- |
| left shift  | <<     | x << y | all bits in x shifted left y bits  |
| right shift | >>     | x >> y | all bits in x shifted right y bits |
| bitwise NOT | ~      | ~x     | all bits in x flipped              |
| bitwise AND | &      | x & y  | each bit in x AND each bit in y    |
| bitwise OR  | l      | x l y  | each bit in x OR each bit in y     |
| bitwise XOR | ^      | x ^ y  | each bit in x XOR each bit in y    |

C++에서 비트 조작은 기호 있는(`signed`) 정수에서 적용 방식을 보장하지 않으므로 비트 단위 연산자는 부호 없는(`unsigned`) 정수 자료형을 사용해야 한다.

------

#### Bitwise left shift (<<) and bitwise right shift (>>) operators

편의와 이해를 돕기 위해서 앞으로 4bit binary를 사용할 것이다. C++에서 사용되는 비트 수는 자료형(byte당 8bit)의 크기에 따라 달라진다.

**왼쪽 시프트 연산자(<<)는 각 비트를 왼쪽으로 이동시킨다.** 왼쪽 피연산자는 이동할 수식이고 오른쪽 피연사자는 이동할 비트 정수 수다. 그래서 `3 << 1`은 리터럴 `3`의 비트를 왼쪽으로 `1`자리 이동시킨다.

###### 예를 들어, 숫자 3(binary: 0011)을 가정해보자:

```
3 = 0011
3 << 1 = 0110 = 6
3 << 2 = 1100 = 12
3 << 3 = 1000 = 8
```

`3 << 3` 경우에, 이동한 비트가 왼쪽 끝 범위를 넘어간다. 이진수의 끝에서 벗어난 비트는 손실된다.

(여기서는 4bit로 가정하고 있다. 8bit일 경우 `3 << 3`은 `0001 1000`이 되어 24가 된다. 이 경우 4번째 비트는 5번째 비트로 이동되므로 손실되지 않는다.)

**오른쪽 시프트 연산자(>>)는 각 비트를 오른쪽으로 이동시킨다.**

```
12 = 1100
12 >> 1 = 0110 = 6
12 >> 2 = 0011 = 3
12 >> 3 = 0001 = 1
```

`12 << 3` 경우에, 이동한 비트가 오른쪽 끝 범위를 넘어간다. 이진수의 끝에서 벗어난 비트는 손실된다.

###### 변수도 시프트할 수 있다:

```
unsigned int x = 4;
x = x << 1; // x will be 8
```

------

#### Bitwise NOT

비트 NOT 연산자(`~`)는 비트 단위 연산자 중 가장 이해하기 쉽다. **각 비트에서 0과 1을 서로 바꾼다.** 결과값은 자료형의 크기에 따라 다르다.

###### 4 bits:

```
4 = 0100
~4 = 1011 = 11 (decimal)
```

###### 8 bits:

```
4 = 0000 0100
~4 = 1111 1011 = 251 (decimal)
```

------

#### Bitwise AND, OR, and XOR

비트 AND 연산자(&)와 비트 OR 연산자(|)는 논리 AND 연산자(&&) 및 논리 OR 연산자(||)와 비슷하게 동작한다. 그러나 bool 값을 평가하는 대신 각 비트에 적용된다. 예를 들어, 식 `5 | 6`은 binary에서 `0101 | 0110`로 적용된다.

```
0 1 0 1 // 5
0 1 1 0 // 6
```

비트의 각 열에 연산이 적용된다. 논리 OR 연산자(`||`)는 왼쪽 또는 오른쪽 피연산자 중 하나 이상이 `true`면 `true`로 평가된다. **비트 OR 연산자(|)는 비트 두개 중 하나 이상이 1이면 1로 평가된다.**

###### `5 | 6`: `0111`(`7`)

```
0 1 0 1 // 5
0 1 1 0 // 6
-------
0 1 1 1 // 7
```

비트 AND 연산자(`&`)도 비슷하게 작동한다. 논리 AND 연산자(`&&`)는 왼쪽과 오른쪽 피연산자가 모두 `true`일 경우에만 `true`로 평가된다. **비트 AND 연산자(&)는 두 비트 모두 1인 경우에만 1로 평가된다.**

###### `5 & 6`: `0100`(`4`)

```
0 1 0 1 // 5
0 1 1 0 // 6
--------
0 1 0 0 // 4
```

마지막 비트 단위 연산자는 **비트 XOR 연산자(^)**다. **두 연산자를 평가할 때, 한 개의 피연산자만 1인 경우에만 1로 평가된다.** 두 비트 모두 `1`인 경우에는 `0`으로 평가된다.

###### `5 ^ 6`: `0101`(`5`)

```
0 1 1 0 // 6
0 0 1 1 // 3
-------
0 1 0 1 // 5
```

------

#### Bitwise assignment operators

산술 할당 연산자(`=`)처럼, C++ 에는 변수를 쉽게 수정할 수 있도록 비트 할당 연산자를 제공한다.

| perator                | Symbol | Form    | Operation               |        |
| ---------------------- | ------ | ------- | ----------------------- | ------ |
| Left shift assignment  | <<=    | x <<= y | Shift x left by y bits  |        |
| Right shift assignment | >>=    | x >>= y | Shift x right by y bits |        |
| Bitwise OR assignment  | l=     | x l= y  | Assign x \              | y to x |
| Bitwise AND assignment | &=     | x &= y  | Assign x & y to x       |        |
| Bitwise XOR assignment | ^=     | x ^= y  | Assign x ^ y to x       |        |

예를 들어, `x = x << 1`을 쓰는 대신 `x <<= 1` 을 쓸 수 있다.

------

#### 요약 (Summary)

###### 열에서 비트를 평가하는 방법:

- 비트 OR 연산자(`|`): 열의 하나 이상 비트가 1이면 해당 열에 대한 결과는 1이다.
- 비트 AND 연산자(`&`): 열의 모든 비트가 1이면 해당 열에 대한 결과는 1이다.
- 비트 XOR 연산자(`^`): 열에서 한 개 비트만 1이면 해당 열에 대한 결과는 1이다.

[출처](https://boycoding.tistory.com/163?category=1007523)



#  25

### priority queue

우선순위큐 -> 내림차순이 기본이다. (오름차순으로 하려면 - 표시 붙이기)

```
priority_queue <pair < long , pair < pair <long ,long>, pair < long, long > > > >  q; 
int n = q.top().second.second.second; 
```

-> 여러개 pair 써본것 



# 26

### queue 초기화 시키기

```
void ClearQueue(priority_queue <int> &someQueue)

{
    priority_queue <int> empty;

    swap(someQueue,empty); //새로운 큐와 원래 있던 큐를 바꾸기

}
```



# 27

### 여러가지 방법



```
//#define 사용 & 구조체 & 맵 
#define UP 1
#defint DOWN 2
...

typedef struct{

	int int;
	int dir
	int maxcnt;

}node;

node map[n+1][n+1];
node next_map[n+1][n+1];
int xy[5][2] = {{0,0}, {-1,0},{1,0},{0,-1},{0,1}};

..
if(map[i][j].cnt>0){
    int dir = map[i][j].dir;
    int nextx = i + xy[dir][0];
    int nexty = j + xy[dir][1];
    
    if(nextx==0 ..){
        next_map[nextx][nexty].cnt = map[i][j].cnt/2;
        
        if(dir == UP)
        	next_map[nextx][nexty].dir = DOWN;
        	...
    }
}
```

```
//구조체 큐
struct node {
	int x, y, d;
};
int visit[4][101][101], sx, sy, ex, ey, W, H, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0,1,0,-1 };
char map[101][101];
queue <node> q;

void bfs() {
	while (!q.empty()) {
		node value = q.front();
		q.pop();

		for (int i = 0,nx,ny; i < 4; i++) {
			nx = value.x + dx[i];
			ny = value.y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < W && ny < H && map[nx][ny] !='*') {
				int &n1 = visit[i][nx][ny];
				int &n2 = visit[value.d][value.x][value.y];
				if (n1 && n1 <= n2) continue;
					n1 = n2 + 1;
				if(value.d == i){
					n1--;
				}
			//	else {
				//}
				q.push({ nx,ny,i });
			}
		}
	}

}
```



```
//구조체 배열
const int maxu =2 ;

struct{
    int x,y;
}user[maxu];

user[0].x = 1;
user[0].y = 1;
```

```
int turningMagnets[5] = {0,};
```

```
#include <iostream>
#include <queue>

    using namespace std;
    
    struct Custom{
        
        int x;
        int y;
        int value;
        Custom(int value) : x(0), y(0), value(value) {
        }
        
    };
    
    // 오름차순 정렬
    struct cmp{
        bool operator()(Custom t, Custom u){
            return t.value > u.value;
        }
    };
    
    int main(){
        
        // priority_queue
        priority_queue< Custom, vector<Custom>,  cmp > pq;
        
        // push(element)
        pq.push(Custom(5));
        pq.push(Custom(2));
        pq.push(Custom(8));
        pq.push(Custom(9));
        pq.push(Custom(1));
        pq.push(Custom(14));
        
        
        // pop()
        pq.pop();
        pq.pop();
        
        
        // top();
        cout << "pq top : " << pq.top().value << '\n';
        
        
        // empty(), size()
        if(!pq.empty()) cout << "pq size : " << pq.size() << '\n';
        
        
        // pop all
        while(!pq.empty()){
            cout << pq.top().value << " ";
            pq.pop();
        }
        
        cout << '\n';
        
        return 0;
        
    }
```

```
    // struct people { ... } 구조체를 PEOPLE 이라는 데이터형으로 정의한다.
    typedef struct People{
        char name[20];
        int age;
        double height;
        double weight;
    } PEOPLE;
  
    // data 라는 변수명으로 people 구조체를 선언한다.
 
    PEOPLE data;      // 일반 변수
    PEOPLE list[20];  // 배열
    PEOPLE *p;         // 포인터
```

```
struct Rectangle { 
	double length = 1.0; 
	double width = 1.0; 
}; 

int main() { 
	Rectangle x; // length = 1.0, width = 1.0 
	x.length = 2.0; // you can assign other values like normal return 0; 
}

```



# 28

### 레퍼런스 &

```
using namespace std;

void swap(int& fnum1, int& fnum2) {

	int temp;
	temp = fnum1;
	fnum1 = fnum2;
	fnum2 = temp;
}
int main() {
	int n1 = 20; int n2 = 30;
	cout << n1 << n2;
	swap(n1, n2);
	cout << n1 << n2;

}
```

```
#include<iostream>
#include<queue>
#include<vector>
#include<queue>

using namespace std;


int main() {

	int v = 10;
	int& r = v;

	v++;
	cout << v << r;
	r++;
	cout << v << r;

}
```

> 참조하는 변수의 이름을 가지고 하는 연산과 같은 효과를 지닌다.



```
int main() {
	
	int &ref1; //초기화 되지 않았으므로 error
	int &ref2 = 10; //상수가 올 수 없으므로 error


}
```

> 레퍼런스는 선언과 동시에 초기화가 되어야한다



```
#include<iostream>
#include<queue>
#include<vector>
#include<queue>

using namespace std;

int& increment(int& v) {
	v++;
	return v;
}
int main() {
	
	int n = 100;
	int& ref = increment(n);

	cout << n <<" "<< ref;
	return 0;
}
```

> 레퍼런스를 리턴하는 함수 정의

**지역변수를 레퍼런스로 리턴할 수 없다**



```
#include<iostream>
#include<queue>
#include<vector>
#include<queue>

using namespace std;

void swap(int *fnum1, int *fnum2) {

	int temp;
	temp = *fnum1;
	*fnum1 = *fnum2;
	*fnum2 = temp;
} //포인터를 이용해서 메모리공간에 직접 접근 가능
int main() {
	

	int n1 = 20; int n2 = 30;
	cout << n1 << n2;
	swap(n1, n2);
	cout << n1 << n2;

}
```

> 포인터를 이용한 swap함수

```
int &t1 = visited[i][nx][ny], t2 = visited[dir][cx][cy];

if (t1 && t1 <= t2) continue;
```

이런식으로 t1의 값이 0일 때는 if(t1&&..) 식에 부합하지 않는다 1이상일때 값만 continu할 수 있다



# 29



### 마름모 영역 구하기 

```

	int nexty;
	int endp;

	for (int i = 0; i <= k - 1; i++) { // 제일 중간 값빼고 처리하기
		int upNextx = x - k + i;// k만큼 빼주고 (맨위로 올라간 다음에 i칸만큼 내려간 위치) 
		int downNextx = x + k - i;

		endp = i * 2 - 1; // 돌아갈 칸 갯수 (i가 2번째이면 3개의 칸이선택됨 i=1(1) i=2(3) i=3(5).. )
		nexty = y - endp / 2; // y는 중간에 있으니 y를 맨 왼쪽으로 보냄  endp만큼 오른쪽으로 가면서 (i=2(3개)) 확인
		for (int j = 0; j<endp; j++) { // 올라가면서(오른쪽으로 가면서 ) 범위안이고 맵이 1인지 확인
			if (isRange(upNextx, nexty + j) /*&& map[upNextx][nexty + j] == 1*/) 
			//map 조건은 내가 걸기
				//cnt++; -> 내가 집어넣기
			if (isRange(downNextx, nexty + j) /*&& map[downNextx][nexty + j] == 1*/)
				//cnt++;

		}
	}
	endp = k * 2 - 1; //중간값 처리 중간은 i=3이면 (5)전체다 체크해줌 
	nexty = y - endp / 2;
	for (int i = 0; i<endp; i++)
		if (isRange(x, nexty + i) /*&& map[x][nexty + i] == 1*/)
			//cnt++;
```

