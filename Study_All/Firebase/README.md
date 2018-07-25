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

  

  

  ## Firebase 실시간 데이터베이스 규칙 이해

  Firebase 실시간 데이터베이스 규칙은 데이터베이스에 대한 *읽기 및 쓰기 권한, 데이터의 구조 및 색인 생성 여부를 결정합니다.* 이 규칙은 Firebase 서버에 적용되며 *항상 자동*으로 적용됩니다. 모든 읽기 및 쓰기 요청은 *규칙에 따라 허용될 때*만 완료됩니다. 기본적으로는 인증된 사용자에게만 데이터베이스 전체 읽기 및 쓰기 액세스가 허용되도록 규칙이 설정됩니다. 이는 규칙을 맞춤설정하거나 인증을 설정하기 전까지 데이터베이스가 악용되지 않도록 보호하기 위한 조치입니다.

  Firebase 데이터베이스 규칙은 자바스크립트와 유사한 문법을 사용하며 다음과 같은 4가지 유형이 있습니다,

  ## 사용자 기반 보안 

  

  **데이터보안** 의 개념을 복습하면서 사전 정의된  `auth`  변수를 통합하여 완벽한 데이터 보안 솔루션을 만들어 봅니다.

  

  ### 인증통합

  Firebase 인증은 Firebase 실시간 데이터베이스와 통합되어 사용자별 데이터 액세스를 제어하는 기능을 제공합니다. 

  

  사용자가 인증되면 Firebase 데이터베이스 규칙의    `auth`  변수에 사용자의 정보가 입력됩니다. 이 정보에는 고유식별자 (uid), 연결된 계정 데이터 (facebook Id 또는 이메일 주소) 및 기타 정보가 포함됩니다. 맞춤 인증 제공업체를 구현하는 경우 사용자의 인증 페이로드에 필드를 직접 추가할 수 있습니다. 

  -> *실시간 데이터베이스 규칙언어와 사용자의 인증 정보를 결합하는 방법을 설명*합니다. 두 개념을 사용하여 *사용자 ID에 따라 데이터 액세스 제어를 할 수 있습니다.* 

  

  ### auth 변수

  규칙에서 사전 정의된  `auth` '변수는 *인증이 완료되기전까지는 null 입니다.*

  Firebase 인증을 통해 *사용자가 인증되면 다음 속성이 포함됩니다.*  

![스크린샷 2018-07-25 오후 2.59.19](/Users/PARKHASIK/Desktop/firebase screenshot/스크린샷 2018-07-25 오후 2.59.19.png)

다음은 `auth` 변수를 사용하여 각 사용자가 자신에게 해당하는 경로에만 쓸 수 있도록 하는 규칙의 예시입니다.



```
{
  "rules": {
    "users": {
      "$user_id": {
        // grants write access to the owner of this user account
        // whose uid must exactly match the key ($user_id)
        ".write": "$user_id === auth.uid"
      }
    }
  }
}
```



### 데이터 베이스 구조화

보안 규칙을 작성하기 쉬운 방향으로 데이터베이스를 구조화하는 것이 도움이 될 수 있습니다. 예를 들어 실시간 데이터베이스에 사용자 데이터를 저장하는 일반적인 패턴 중 하나는 모든 사용자를 단일 `users` 노드에 저장하고 각 사용자의 `uid` 값으로 하위 항목을 만드는 것입니다. 로그인한 사용자만 자신의 데이터를 볼 수 있도록 이 데이터에 대한 액세스를 제한하려면 다음과 같은 규칙을 사용합니다.

```
{
  "rules": {
    "users": {
      "$uid": {
        ".read": "auth != null && auth.uid == $uid"
      }
    }
  }
}
```



### 맞춤 인증 토큰으로 작업

더욱 자세한 제어가 필요한 개발자를 위해 Firebase 인증은 [서버에 맞춤 인증 토큰을 만드는](https://firebase.google.com/docs/auth/admin/create-custom-tokens?hl=ko) 기능을 제공합니다.

개발자는 맞춤 인증 토큰을 만들 때 추가적인 클레임을 토큰에 추가할 수 있습니다. 규칙의 `auth.token` 변수에 이러한 추가 클레임이 배치됩니다. 다음은 `hasEmergencyTowel` 맞춤 클레임을 활용하는 규칙의 예입니다.

```
{
  "rules": {
    "frood": {
      // A towel is about the most massively useful thing an interstellar
      // hitchhiker can have
      ".read": "auth.token.hasEmergencyTowel === true"
    }
  }
}
```

또한 Admin SDK를 사용하면 액세스 제어를 위한 사용자 역할의 정의에 도움이 되는 맞춤 토큰 클레임을 설정할 수 있습니다. [맞춤 클레임 및 보안 규칙을 통한 액세스 제어](https://firebase.google.com/docs/auth/admin/custom-claims?hl=ko)를 참조하세요.

## 

 