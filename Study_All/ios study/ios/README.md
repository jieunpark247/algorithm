[ios관련 홈페이지](https://academy.realm.io/kr/section/apple/)

# Object-c 와 Swift 의 차이점

[Object-c vs Swift](https://academy.realm.io/kr/posts/from-objective-c-to-swift-ios-techtalk/)

# App Life Cycle

* Not Running
	* 실행되지 않는 모드와 상태를 모두 의미.
* Foreground
	* Active  
	* Inactive
* Background
	* Running  
	* Suspend
* Not Running >> Active
	* 앱을 터치해서 실행이 되는 상태이다.
* Active >> Inactive >> Running
	* 앱을 활성화 상태에서 비활성화 상태로 만든 뒤, 백그라운드에서도 계속 실행중인 상태이다.
* Active >> Inactive >> Suspen
	* 앱을 활성화 상태에서 비활성화 상태로 만든 뒤, 백그라운드에서도 정지되어 있는 상태이다.
* Running >> Active
	* 백그라운드에서 실행 중인 앱이 다시 포어그라운드에서 활성화되는 상태이다.


**UIApplication** 객체는 앱 전체에서 하나만 존재하는 객체이다. Event Loop 에서 발생하는 여러 이벤트를 감지하고 Delegate 전달하는 역할을 한다.   

**AppDelegate** 객체는 UIApplication객체로 부터 메세지를 받았을 때, 해당 상황에서 실행 될 함수를 정의한다. swift 프로젝트를 만들면 자동으로 생성되는 AppDelegate.swift 파일이 있는데 이 파일이 AppDelegate 가 된다. AppDelegate.swift 파일 안에 클래스 선언부에  @UIApplicationMain 어노테이션이 붙어있다. -> 결국 앱이 구동되면 AppDelegate.swift 의 AppDelegate 클래스를 델리게이트 객체로 지정한다. 

# ViewController Lifecycle

![](https://camo.githubusercontent.com/edc26469ab7a1b7616e77aead09cc7ab5b144864/68747470733a2f2f646f63732d6173736574732e646576656c6f7065722e6170706c652e636f6d2f7075626c69736865642f663036663330666136332f554956696577436f6e74726f6c6c65725f436c6173735f5265666572656e63655f32785f64646361613030632d383764382d346338352d393631652d6363666239666134616163322e706e67)

* **viewDidLoad** : 뷰 컨트롤러 클래스가 생성될 때 가장 먼저 실행 된다. 딱 한번만 실행되기 때문에 초기화 할때 사용할 수 있다.  

* **ViewWillAppear** : 뷰가 생성되기 직전에 항상 실행되기 때문에 뷰가 나타나기 전까지 실행해야 하는 작업들을 여기서 할 수 있다.

* **ViewDidAppear** : 뷰가 생성되고 난 뒤에 실행 됩니다. 데이터를 받아서 화면에 뿌려주거나 애니메이션 등의 작업을 하는 로직을 위치시킬 수 있다. ViewWillAppear 에서 로직을 넣었다가 뷰에 반영이 안되는 경우가 있기 때문이다. 

* **ViewWillDisappear** : 뷰가 사라지기 직전에 실행 된다.

* **ViewDidDisappear** : 뷰가 사라지고 난 뒤에 실행 된다.


# Delegate vs Block vs Notification

**Delegate** : 객체 간의 데이터 통신을 할 경우 전달자 역할을 한다. 이벤트 처리할 때 많이 사용하게 되는데 특정 객체에서 발생한 이벤트를 다른 객체에 통보할 수 있도록 해준다. 가장 기본적인 예는 ```UITableView``` 이다. 

**Block**는 이벤트가 딱 하나일 때 사용하기 좋다. Completion block 을 사용하는 것이 좋은 예로 ```NSURLConnection sendAsynchronousRequest:queue:completionHandler:``` 가 있다.

**Notification**은 이벤트에 대해 여러가지 리스너가 있을 때 사용하면 좋다. ex) <UI가  특정 이벤트를 기반으로 정보를 표시하는 방법을 notification으로 브로드캐스팅하여 변경하거나 문서 창을 닫을 때 문서의 객체가 상태를 저장하는지 확인하는 방법으로 notification 을 사용할 수 있다. > 일반적인 목적은 - > 다른 객체에 이벤트를 알리면 적절하게 응답할 수 있다 그러나 noti를 받는 객체는 이벤트가 발생한 수 반응할 수 있다. 

# Memory Management

* java와 달리 가비지 컬렉션은 존재하지 않는다
	* **가비지컬랙션**이란? : 메모리는 OS가 관리함 모든프로그램도 OS위에서 돌아감-> 프로그램이 돌아가려면 메모리가 필요! 때문에 프로그램들은 OS에게 메모리를 주라고 요청한다. 자바를 실행하는 JVM도 마찬가지이다. 메모리가 필요하면 OS에 요청해야한다. OS는 각 프로그램에게 일정 부분만 메모리를 빌려주는 방식으로 관리한다. 이때 프로그램을 실행하다보면 '가비지'가 발생한다.(=정리되지 않은 메모리, 유효하지 않는 메모리주소라는 의미) 즉, 메모리가 부족할 때 가비지를 정리해주어 '메모리 해제'를 시키는  프로그램이 가비지 컬렉션이다.
*  MRC와 ARC 방식을 이용해서 메모리를 관리한다.

### 메모리 관리의 필요성 

메모리 관리에서 알아야 하는 것이 **Reference Counting**이다. Reference Counting은 메모리에 할당된 객체에 참조중인 개수를 세는 것 이다. **즉, 특정 객체에 얼마나 많은 참조가 있는지를 숫자로 세는 것!**

## MRC

* 수동 레퍼런스 카운트 : 개발자가 수동으로 Reference Counting 을 하는것.
* Object-c 에서만 지원
* retain : 객체 참조 / release: 참조를 풀고 싶을때 
-> 이 방식은 문제가 있다. 어떤 메소드에서 retain이 되어 release를 해주는데 만약 값을 return 해줘야 한다면 이미 release를 통해 Reference Count가 0이 되어 객체가 이미 죽어있게 된다.

이럴때 사용하는것이 Autorelease이다.

## Autorelease

* autorelease는 AutoreleasePool에 release가 필요한 객체들을 보관한다.
* 어떤 시점이 되면 pool -> drain이 되고 release가 된다.
 하지만 딱히 좋은 방법은 아님

## MRC Summary

* alloc/new/copy/retain을 사용했다면 release를 해주어야 한
* retain을 사용했다는 말은 언젠가 release를 호출해야 한다.
* release를 하더라도 Reference Count가 0이 되기 전까진 메모리에서 없어지지 않는다.
* iOS에서는 release가 더 좋다고 한다.
* 앱이 종료되면 모든 객체는 release 된다.

## ARC
* 자동 레퍼런스 카운트 : 자동으로 메모리 관리를 처리한다.

* Memory Method에 접근할 수 없다. -> retain/release/autorelease 등을 부를 수 없고 compiler가 알아서 처리한다.
* C구조체에 객체를 넣을 수 없다.
* id와 void 간에 Casual Casting을 할 수 없다.
* NSAutoreleasePool을 사용할 수 없다.

# assign vs weak

* **assign** : 개게의 retain count 를 증가시키지 않는다. 외부에서 retain count 를 감소시켜 객체가 소멸 될 수 있기 때문에 int 와 같은 primitive type에 적당하다.
* **weak** : assign과 거의 비슷하지만 assign은 객체가 소멸되어도 포인터 값이 변하지 않는다. weak는 객체가 해제되는 시점에 포인터 값이 nil이 된다. assign의 문제점은 객체가 해제되더라도 포인터 값이 남아있어 접근하려다 죽는 경우가 생긴다. 

#  Frame vs Bounds

* Frame : 부모 뷰의 상대적인 위치 (x,y) 및 크기 (width , height) 로 표현되는 사각형
* Bound : 자체 좌표계(0,0)을 기준으로 위치 (x,y)및 크기 (width,heigh)로 표현되는 사각형이다.

# 기타 etc ios 질문

* 블록 객체는 어디에 생성되는가 	
	* 블록은 함수와 비슷하게 생겼고 함수와 동작도 유사하다. 그러나 함수와 달리 정의한 함수나 메서드 안에서 정의 할 수 있고 블록 바깥에서 정의된 변수에도 접근이 가능하다. 장점으로는 시스템 블록을 애플리케이션이 사용하는 다른 프로세서나 스레드에서 실행되도록 분산처리가 가능하다는 것! (= 동시실행의 의미) 
	* automatic은 스택메모리를 사용
	* managed는 힙 메모리에 생성된다.
	* 블록은 ^(캐럭분자)로 시작한다.
* 오토레이아웃을 코드로 작성해보았는가? 
	* 비주얼 포맷을 이용해서 작성할 수 있다.
* @property로 프로퍼티를 선언했을 때와 _와 . 연산자로 접근하는 것의 차이점 
	* _는 인스턴스 변수에 직접 접근하는 연산자이다.
	* .는 getter 메소드 호출을 간단하게 표현한것 
* init 메소드에서 . 연산자를 써도 될까?
	* 불가능하다. 객체가 초기화 안되어 있기 때문에 getter 메소드 호출 불가하다.
* 데이터를 저장하는 방법
	> 각각의 방법에 대한 장단점과 언제 어디서 사용해야 하는지 이해하는것 필요!!
	* Server/Cloud
	* Property List
	* Archive
	* SQLite
		* sql 관련 지식 필요  
	* File
	* CoreDate
		* sql 이해 없이도 간단하게 데이터를 저장할 수 있다. 내부적으로 Wrapping 되어서 SQLite에 저장하게 된다. 
	* etc...
* Dynamic Binding
	* 동적 바인딩을 컴파일 타임이 아닌 런타임에 메세지 메소드 연결을 이동시킨다. 그래서 이 기능을 사용하면 응답하지 않을 수도 있는 객체로 메세지를 보낼 수 있습니다. 개발에 유연성을 가져다 주지만 런타임에는 가끔 충돌을 발생시킨다.  
* Block 에서의 순환 참조 관련 질문
	* 순환 참조에서 weak self로만 처리하면 되는가 에 대한 질문  
