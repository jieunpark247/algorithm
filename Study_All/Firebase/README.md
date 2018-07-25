## Firebase 이점 



![image](/Users/PARKHASIK/Downloads/image.jpeg)



사진을 보면 서버개발이 사라진 것을 볼 수 있다.   
1.firebase를 쓴다면 작업시간을 단축할 수 있다. 

2.firebase는 많은 기능들이 있다.   


![image2](/Users/PARKHASIK/Downloads/image2.png)

3.빠른시간안에 앱의 프로토타입을 만들어낼수 있다

### 실행 

pod 'Firebase/Core'  
pod 'Firebase/Database'  
--> 이 기능들을 추가해줌  



![image3](/Users/PARKHASIK/Downloads/image3.png)

​	

•	앱에서 FIRUser 개체로부터 사용자의 기본 프로필 정보를 가져올 수 있습니다. 사용자 관리를 참고하세요. 
	•	Firebase 실시간 데이터베이스와 Cloud Storage 보안 규칙에서 auth 변수로부터 로그인한 사용자의 고유 사용자 ID를 가져온 후 이 ID를 통해 사용자의 데이터 액세스를 관리할 수 있습니다. 





## FCM 에서 APN 구성			

[firebase cloud messaging APN Interface](https://firebase.google.com/docs/cloud-messaging/ios/certs?hl=ko)



Firebase 클라우드 메시징 APN 인터페이스는 [Apple 푸시 알림 서비스(APN)](https://developer.apple.com/notifications/)를 사용하여 백그라운드 상태인 앱을 포함한 iOS 앱으로 최대 4KB의 메시지를 보냅니다.

APN을 통해 푸시 알림을 보내려면 다음이 필요합니다. 

* Apple 개발자 계정의 Apple 푸시알림인증키 , Firebase 클라우드 메세징은 이 토큰을 사용하여 앱 ID로 식별되는 애플리케이션에 푸시 알림을 보냅니다.

* 해당 앱 ID의 프로비저닝 프로필

  이러한 인증서와 프로필은 Apple Developer Member Center 에서 만들 수 있습니다.

  

  .....

  

  

  ## 사용자 기반 보안 

  

  **데이터보안** 의 개념을 복습하면서 사전 정의된 auth 변수를 통합하여 완벽한 데이터 보안 솔루션을 만들어 봅니다.

  

  ### 인증통합

  Firebase 인증은 Firebase 실시간 데이터베이스와 통합되어 사용자별 데이터 액세스를 제어하는 기능을 제공합니다. 

  

  사용자가 인증되면 Firebase 데이터베이스 규칙의   **auth** 변수에 사용자의 정보가 입력됩니다. 이 정보에는 고유식별자 (uid), 연결된 계정 데이터 (facebook Id 또는 이메일 주소) 및 기타 정보가 포함됩니다. 맞춤 인증 제공업체를 구현하는 경우 사용자의 인증 페이로드에 필드를 직접 추가할 수 있습니다. 

  -> 실시간 데이터베이스 규칙언어와 사용자의 인증 정보를 결합하는 방법을 설명합니다. 두 개념을 사용하여 사용자 ID에 따라 데이터 액세스 제어를 할 수 있습니다. 

  

  ### auth 변수

  규칙에서 사전 정의된 

  

