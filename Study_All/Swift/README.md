# swift

### 주요 기능들

**딕서너리(해시테이블)** : 대괄호를 사용하여 해시테이블을 만들 수 있다. 이것을 딕셔너리라고 부르며 초기화 할 수 있는 구문을 제공한다. 

```
var airports = [String:String?]()
airports["ICN"] = "Inchon Internetional Airport"
airport["ICN"] = nil // remove from dictionary
```



**데이터 타입 추론 -함수영 프로그래밍 언어** : 코드를 실행해보기전에 버그를 미리 잡을 수 있다. 비호환성이 발견되면 오류를 검출해준다. 

```
let meaningOfLife = 42 //int 형으로 자동으로 추론 
```



**데이터 구초체 타입 선언 : ** 어떤 타입의 데이터가 데이터 구조체가 저장될지 컴파일러에 미리 알려줌 -> 데이터구조에 저장될 타입을 컴파일러에게 미리 알려줄 수 있다. 

```
var namesOfIntegers = Dictionary<int,String>()
// empty 
```

**문자열 템플릿** : 문자열 이어붙일 수 있다. 

**선택사항인 세미콜론 ** 



**프로토콜 (인터페이스) ** : 클래스가 정의에 부합하기 위해 제공해야하는 모든 함수에 대한 구조를 정의하는 기본클래스이다. 스위프트는 '프로토콜'이라는 용어로 사용한다.

```
protocol ExampleProtocol{
    var simpleDescription : String{ get }
    mutation func adjust()
}
```

**Tuple** : 함수나 메소드에 가끔 두개 이상의 값을 반환해야할 때 

```
func getGasPrices() -> (Double,Double,Double){
    return (3.5, 4.6, 5.6)
}
getGasPrice()
```

**자동참조(가비지콜렉터와 비슷)** : 메모리를 탐색하면서 더이상 사용되지 않는 메모리 영역을 회수하는 자동 루틴이다. 스위프트는 자동참조카운트를 사용한다. 

**부호있는 정수와 부호없는 정수 제공 **

**클로저 : ** 소량의 코드를 묶어서 함수처럼 전달한다. 

```
let numbers  = [Int]()

number.map({
    (number:Int) -> Int in
    let result = 3*number
    return result
})
```

### 구조적 특징 

빠름, 설계에의한 안정성, 현대적, 상호반응, 완전한 플랫폼, 통합



# Swift 기본문법

swift는 *객체 지향적 성격을 지닌 스크립트 스타일의 언어*라고 이야기하지만 이것은 스위프트위 모든 성격을 드러내주지는 못한다. 다양한 언어로 부터 차용한 현대적 프로그래밍 개념이 모두 반영된 결과물이 바로 스위프트이기 때문이다. 



**엔트리포인트로 사용되는 main() 함수가 없다** : 대신 @UIApplicationMain어노테이션을 사용하여 앱을 시작하는 객체를 지정한다. -> 단 하나뿐이여야 한다.

**try catch 방식의 오류처리를 지원한다** : 함수나 메소드가 리턴값 또는 매개변수를 이용하지 않고 외부로 직접 오류를 던질 수 있도록 하는 기능이다. 대신 오류가 생길 가능성을 미리 차단 할 수 있는 *옵셔널*  개념을 사용하기도 하였다. BUT 옵셔널 방식은 한계를 드러냈다. 네트워크처리나 데이터 파싱처리등 다양한 오류가 발생할 수 있는 상황에서 유연하게 대응하기에는 너무 단편적이였다. 



## 변수와 상수

```
// 변수를 선언할 때
var + 변수명

//상수를 선언할 때
let + 상수명
```

```
var year : Int
year = 1999
```



#### UInt

Unsigned Integer를 줄인 단어로 부호가 없는 정수를 의미한다. 양수만 저장할 수 있다. 플러스 정수에 대해서는 Int보다 두 배 큰 범위까지 저장할 수 있다. 



## 연산자

**c++ 와 다른것들 **

- a <== b  는  <= 라는 의미 
- !a 는 !(NOT) 
- 1 ... 5 는 1 2 3 4 5 를 나타낸다. (닫힌범위 연산자)
- 1 ..< 5 는 1 2 3 4를 나타낸다. (반 닫힌범위 연산자) 



## 흐름제어 구문

#### For 문

```
for(i in 0...5){
    print("출력값은 \(i)입니다.")
}
```

#### repeat ~ while

do ~ while 에 해당한다. 

#### guard

if와 마찬가지 guard 는 else 가 없다. 



#### #available



## 배열

```
var cities : [String] //선언
cities = [String]() //초기화

var country : [String] // 선언
country = [] // 초기화

var list : [int] = [] // 타입 어노테이션 + 초기화

var rows : Array<Float> = [Float]() // 타입 어노테이션 + 제네릭 + 초지화

var tables : [String] = Array() //타입 어노테이션 + 구방식 초기화
```



#### 배열 아이템 동적 추가

- append(_:) : `append(contentsOf:)` 배열을 한꺼번에 추가할 때 메서드
- insert(_:at:)
- append(contentsOf:)



### NSArray, NSMutableArray

파운데이션프레임워크에서 제공하는 객체이다. NSArray는 수정이 필요없는 배열에 NSMutableArray는 수정이 필요한 배열에 각각 사용한다. 

데이터 타입에 상관없이 저장할 수 있다는 장점이 있다. 그래서 타입이 정해지지않은 불특정 집합데이터나 여러종류의 값이 섞여있는 집합데이터를 처리할 때는 이것을 써야 한다.



## set

set 집합은 같은 타입의 서로 중복 없이 저장하고자 할 때 사용하는 집단자료형 이다. 해시연산을 할 수 있는 타입이여야 한다. 

```
var genres : Set = ["Classic", "Rock" , "Balad"]

var g : Set<String> = [ ]
//초기화
```



## 집합연산 

intersection(_:)

symmertricDifference(_:) 

union(_:) 

subtract(_:) 

---

isSubset(of:)

isDisjoint(with:) 등 ..



## 옵셔널 

nil을 사용할 수 있는 타입과 없는 타입을 구분하고 사용할 수 있는 타입을 가리켜 옵셔널 타입이라고 부른다. 

nil -> 값이 없음을 의미하는 특수한 값

오류를 발생시키는 대신 결과값으로 nil을 반환하는것 

?를 붙이면 된다. 

`String?`

```
var opInt : Int?
var optArr : [String]?
var optDic : Dictionary<String , String>?
var optClass : AnyObject?
```



## 함수

##### 사용자 정의함수

```
func 함수이름(매개변수1 : 타입 , 매개2 : 타입 ....) -> 반환타입{
    실행내용 
    return 반환값
}

//매개변수가 없을땐 () 비워두면 된다. void 쓸 필요 없음
// 반환타입이 void 일 수 있음 -> 안쓰면됨 
```



```
func incrementBy(amount: Int, numberOfTimes : Int){
    var count = 0
    counr = amount * numberOfTimes
}
//amount 와 numberOfTimes의 매개변수를 가진다. 

```

함수를 호출할 때 인자값에 amount 와 numberOfTimes 레이블을 붙여줘야 한다.

> incrementBy(amount: 5, numberOfTimes : 2)

함수명은 incrementBy(amount:numberOfTimes)라고 한다.



### 함수의 반환값과 튜플

```
func getIndInfo() -> (Int, String){
    let height = 180
    let name = "jieun"
    
    return (height , name)
}
```

함수는 반드시 하나의 값만 반환한다. 여러개 값을 반환하려면 값을 집단 자료형에 담아야한다. 딕셔너리,배열,튜플,구조체 , 클래스가 있다. 



함수가 여러개 값을 반환할 때 간단하게 묶기위해 사용하는 것을 튜플이지만 특정 튜플타입이 여러곳에서 사용될 경우에는 타입 알리어스를 통해 새로운 축약형 타입을 정의하는 것이 좋다. 타입알리어스는 이름이 길거나 사용하기 복잡한 타입 표현을 새로운 타입명으로 정의해주는 문법으로 typealias를 사용하여 정의한다.

```
typealias <새로운 타입이름> =<타입표현>
```

```
typealias infoResult = (Int, Character, String)

func getUserInfo() -> infoResult {
    let gender : Character = "M"
    let height = 180
    let name = "jieun"
    
    return(height,gender,name)
}

let info = getUserInfo()
info.0 // 180
info.1 // "M"
info.2//"jieun"
```



### 외부매개변수

```
func printHello (to name : String , welcomMsg msg : String){
    print("\(name)님,\(msg)")
    //name과 msg는 내부매개변수 to ,welcomMsg는 외부매개변수 
}

printHello(to : "jieun" , welcomMsg :"hello" ) //호출 할 때 외부매개변수 쓴다
```





### 클로저 

일회용 함수를 작성할 수 있는 구문 -> 익명의 함수라고 부르기도 한다. 

```
{ (매개변수)-> 반환타입 in
	실행구문
}
```



```
{ ()-> Void in // in 은 시작한다는 의미
	print("클로저 실행")
}
```



## 구조체와 클래스

클래스는 하나의 큰 코드 블록이다. 이안에 변수나 상수를 넣어 값을 저장할 수도 있고, 함수를 넣어서 기능을 정의할 수 도 있다. *유연성* 을 가질 수 있게 해주는 근간을 이룬다. 

똑같은 변수와 상수더라도 구조체와 클래스 내부에서 정의되면 *프로퍼티*라는 이름을 가집니다. 속성변수 또는 상수라고 불리기도 한다. 함수도 마찬가지이다. 구조체와 클래스 내부에서 정의된 함수는 *function* 뿐만이 아니라 *메소드* 라고 불린다. ....... p414



객체를 만들어 내는 주요대상이 구조체와 클래스 이다. 



```
struct 구조체이름{
    
}
```

```
class 클래스이름{
    
}
```

구조체와 클래스 내부에서 정의된 변수나 상수는 *프로퍼티(Property)* 또는 속성이라고 한다. 또한 함수를 정의하여 특정 기능을 정의할 수 있는데 이를 *메소드(Method)* 라고 한다.



#### 인스턴스

틀 역할을 하는 클래스나 구조체를 정의하고 이를 바탕으로 실질적으로 값을 담을 여러 개의 그릇을 만들어 내는 것, 이것이 객체지향 프로그래밍의 원리이다. 원형 틀을 이용하여 찍어낸 그릇을 **인스턴스** 라고 한다. 타입의 설계도를 사용하여 메모리 공간을 할당 받은 것이 인스턴스이다. 

```
// Resolution 구조체에 대한 인스턴스를 생성하고 상수 inRes에 할당
let inRes = Resolution()
```

객체가 초기화 되면서 인스턴스가 생성되고 이 값을 변수나 상수에 할당하면 이제 원하는 곳에서 사용할 수 있게 된다. 



<인스턴스이름>.<프로퍼티이름>

```
let width = inRes.width
```

<인스턴스이름>.<프로퍼티이름>.<프로퍼티 서브프로퍼티이름>



```
let video = VideoMode()
video.name = "Origin"
```









.....



### Any , AnyObject

상속 관계에 있지 않아도 타입캐스팅 할 수 있는 예외가 있는데 Any , AnyObject을 사용할 때이다.