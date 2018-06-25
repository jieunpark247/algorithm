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


**UIApplication**객체는 앱 전체에서 하나만 존재하는 객체이다. Event Loop 에서 발생하는 여러 이벤트를 감지하고 Delegate 전달하는 역할을 한다.   

**AppDelegate** 객체는 UIApplication객체로 부터 메세지를 받았을 때, 해당 상황에서 실행 될 함수를 정의한다. swift 프로젝트를 만들면 자동으로 생성되는 AppDelegate.swift 파일이 있는데 이 파일이 AppDelegate 가 된다. AppDelegate.swift 파일 안에 클래스 선언부에  @UIApplicationMain 어노테이션이 붙어있다. -> 결국 앱이 구동되면 AppDelegate.swift 의 AppDelegate 클래스를 델리게이트 객체로 지정한다. 

# ViewController Lifecycle

https://camo.githubusercontent.com/edc26469ab7a1b7616e77aead09cc7ab5b144864/68747470733a2f2f646f63732d6173736574732e646576656c6f7065722e6170706c652e636f6d2f7075626c69736865642f663036663330666136332f554956696577436f6e74726f6c6c65725f436c6173735f5265666572656e63655f32785f64646361613030632d383764382d346338352d393631652d6363666239666134616163322e706e67

