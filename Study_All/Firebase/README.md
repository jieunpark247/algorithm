# list

[Firebase이점](#Firebase이점)   

[APN 구성](#APN구성)

[보안 및 규칙](#보안및규칙)

[실시간 데이터베이스](#실시간데이터베이스)



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

| pod                         | 서비스                               |
| --------------------------- | ------------------------------------ |
| pod 'Firebase/Core'         | 필수 조건 라이브러리 및 애널리틱스   |
| pod 'Firebase/AdMob'        | AdMob                                |
| pod 'Firebase/Messaging'    | 클라우드 메시징                      |
| pod 'Firebase/Database'     | 실시간 데이터베이스                  |
| pod 'Firebase/Invites'      | 초대                                 |
| pod 'Firebase/DynamicLinks' | 동적 링크                            |
| pod 'Firebase/Crash'        | 오류 보고                            |
| pod 'Firebase/RemoteConfig' | 원격 구성                            |
| pod 'Firebase/Auth'         | 인증                                 |
| pod 'Firebase/Storage'      | 저장소                               |
| pod 'Firebase/Performance'  | 성능 모니터링                        |
| pod 'Firebase/Firestore'    | Cloud Firestore                      |
| pod 'Firebase/Functions'    | Firebase용 Cloud 함수 클라이언트 SDK |

•	앱에서 FIRUser 개체로부터 사용자의 기본 프로필 정보를 가져올 수 있습니다. 사용자 관리를 참고하세요. 
	•	Firebase 실시간 데이터베이스와 Cloud Storage 보안 규칙에서 auth 변수로부터 로그인한 사용자의 고유 사용자 ID를 가져온 후 이 ID를 통해 사용자의 데이터 액세스를 관리할 수 있습니다. 

[list](#list)



# APN구성

## FCM 에서 APN 구성			

[firebase cloud messaging APN Interface](https://firebase.google.com/docs/cloud-messaging/ios/certs?hl=ko)



Firebase 클라우드 메시징 APN 인터페이스는 [Apple 푸시 알림 서비스(APN)](https://developer.apple.com/notifications/)를 사용하여 백그라운드 상태인 앱을 포함한 iOS 앱으로 최대 4KB의 메시지를 보냅니다.

APN을 통해 푸시 알림을 보내려면 다음이 필요합니다. 

* Apple 개발자 계정의 Apple 푸시알림인증키 , Firebase 클라우드 메세징은 이 토큰을 사용하여 앱 ID로 식별되는 애플리케이션에 푸시 알림을 보냅니다.

* 해당 앱 ID의 프로비저닝 프로필

  이러한 인증서와 프로필은 Apple Developer Member Center 에서 만들 수 있습니다.

  

  [list](#list)

  

  .....

  

  # 보안및규칙

  ## Firebase 실시간 데이터베이스 규칙 이해

  Firebase 실시간 데이터베이스 규칙은 데이터베이스에 대한 *읽기 및 쓰기 권한, 데이터의 구조 및 색인 생성 여부를 결정합니다.* 이 규칙은 Firebase 서버에 적용되며 *항상 자동*으로 적용됩니다. 모든 읽기 및 쓰기 요청은 *규칙에 따라 허용될 때*만 완료됩니다. 기본적으로는 인증된 사용자에게만 데이터베이스 전체 읽기 및 쓰기 액세스가 허용되도록 규칙이 설정됩니다. 이는 규칙을 맞춤설정하거나 인증을 설정하기 전까지 데이터베이스가 악용되지 않도록 보호하기 위한 조치입니다.

  Firebase 데이터베이스 규칙은 자바스크립트와 유사한 문법을 사용하며 다음과 같은 4가지 유형이 있습니다,

  | 규칙 유형     |                                                              |
  | ------------- | ------------------------------------------------------------ |
  | **.read**     | 사용자가 데이터를 읽을 수 있는 조건을 기술합니다.            |
  | **.write**    | 사용자가 데이터를 쓸 수 있는 조건을 기술합니다.              |
  | **.validate** | 값의 올바른 형식, 하위 속성을 갖는지 여부 및 데이터 유형을 정의합니다. |
  | **.indexOn**  | 정렬 및 쿼리를 위해 색인화할 하위 항목을 지정합니다.         |

  

  ### 실시간 데이터베이스 보안 개요 

  Firebase 실시간 데이터베이스는 앱의 보안 관리를 위한 *전체 도구 세트를 제공*합니다. 이러한 도구로 *손쉽게 사용자를 인증하고, 사용자 권한을 적용하고, 입력을 검증*할 수 있습니다.

  Firebase 기반 앱은 다른 기술 스택에 비해 *클라이언트측 코드를 더 많이 실행*합니다. 따라서 보안에 대한 접근법도 지금까지 익숙했던 방식과는 조금 다를 수 있습니다.

  ` Firebase 실시간 데이터베이스는 다양한 세부 보안 기능을 자동으로 처리합니다. 예를 들어 SSL 인증서에 강력한 2048비트 키를 사용하며 인증 토큰에 대한 권장사항을 준수합니다.`

  

  ### 인증

  앱 보안의 첫 단계는 일반적으로 사용자 식별이며 이 프로세스를 *인증*이라고 합니다.[Firebase 인증](https://firebase.google.com/docs/auth/?hl=ko)으로 사용자가 앱에 로그인하도록 할 수 있습니다. Firebase 인증은 Google, Facebook, 이메일 주소 및 비밀번호 로그인, 익명 로그인 등의 보편적인 로그인 방법을 즉각적으로 지원합니다.

  사용자의 ID는 중요한 보안 개념입니다. 사용자마다 다른 데이터를 보유하며, 사용자의 권한도 서로 다를 수 있습니다. 예를 들어 채팅 애플리케이션에서 각 메시지는 메시지를 작성한 사용자에 연결됩니다. 또한 사용자는 자신의 메시지를 삭제할 수 있지만 다른 사용자가 게시한 메시지는 삭제할 수 없습니다.

  

  ### 승인

  사용자 식별은 보안의 일부에 불과합니다. 사용자가 누구인지 알아냈으면 데이터베이스의 데이터에 대한 액세스를 제어할 방법이 필요합니다. Firebase 데이터베이스 규칙으로 각 사용자의 액세스를 제어할 수 있습니다. 예를 들어 다음은 `/foo/` 경로를 누구나 읽을 수 있지만 아무도 쓸 수 없도록 하는 보안 규칙입니다.

  ```
  {
    "rules": {
      "foo": {
        ".read": true,
        ".write": false
      }
    }
  }
  ```

  `.read` 및 `.write` 규칙은 하위로 전파되므로 이 규칙 세트는 `/foo/` 경로 및 `/foo/bar/baz`와 같은 더 깊은 경로의 모든 데이터를 읽도록 허용합니다. 데이터베이스에서 상위 `.read` 및 `.write` 규칙이 하위 규칙을 재정의하므로 이 예에서는 `/foo/bar/baz` 경로의 규칙이 false로 판정되어도 `/foo/bar/baz`에 대한 읽기 권한이 부여됩니다.

  

  Firebase 데이터베이스 규칙은 다른 경로, 서버측 타임스탬프, 인증 정보 등을 참조할 수 있도록 하는 [기본 제공 변수](https://firebase.google.com/docs/database/security/securing-data?hl=ko#predefined_variables)를 포함합니다. 다음은 인증된 사용자에게 `/users/<uid>/`에 대한 쓰기 권한을 부여하는 규칙 예시입니다. 여기에서 <uid>는 Firebase 인증을 통해 확인된 사용자 ID입니다.

  ```
  {
    "rules": {
      "users": {
        "$uid": {
          ".write": "$uid === auth.uid"
        }
      }
    }
  }
  ```

  

  ## 데이터베이스 규칙 시작하기

  Firebase 실시간 데이터베이스가 제공하는 자바스크립트와 유사한 문법의 유연한 표현식 기반 규칙 언어를 사용하여 데이터의 구조, 색인 생성 방법 및 데이터를 읽고 쓸 수 있는 조건을 정의할 수 있습니다. Firebase 인증 서비스와 결합하면 사용자별 데이터 액세스 권한을 정의하고 사용자의 개인정보를 무단 액세스로부터 보호할 수 있습니다.

  ### 규칙 구성

  [Firebase 콘솔](https://console.firebase.google.com/?hl=ko)에서 데이터베이스의 규칙을 검색하고 변경할 수 있습니다. 프로젝트를 선택하고, 왼쪽의 **데이터베이스** 섹션을 선택하고, **규칙** 탭을 선택하기만 하면 됩니다. 보안 규칙을 실제로 적용하기 전에 테스트해 보려면 콘솔에서 규칙 편집기 오른쪽 상단의 시뮬레이션 버튼을 사용하면 됩니다.

  [명령줄 인터페이스](https://firebase.google.com/docs/cli/?hl=ko#deployment)에서 규칙을 업데이트할 수도 있습니다. 이 방법은 자동 배포 시스템과 같이 프로그래매틱 방식으로 규칙을 업데이트할 때 특히 유용합니다.

  ### 샘플 규칙

  기본적으로 데이터베이스 규칙은 Firebase 인증을 요구하며, 인증된 사용자에게만 전체 읽기 및 쓰기 권한을 부여합니다. 기본 규칙은 사용자가 직접 규칙을 구성하기 전에 데이터베이스에 아무나   수 없도록 합니다. 설정을 완료하고 나면 규칙을 필요에 따라 맞춤설정할 수 있습니다. 다음은 일반적인 몇 가지 예입니다.

  기본

  > 기본 규칙은 [인증](https://firebase.google.com/docs/auth/?hl=ko)을 요구합니다. 앱의 인증된 사용자에게는 전체 읽기 및 쓰기 액세스가 허용됩니다. 이 규칙은 데이터를 외부에 공개하지 않으면서 앱의 모든 사용자에게만 데이터를 공개하려는 경우에 유용합니다.

  ```
  // These rules require authentication
  {
    "rules": {
      ".read": "auth != null",
      ".write": "auth != null"
    }
  }
  ```

  공개

  > 개발 중에는 기본 규칙 대신 공개 규칙을 사용하여 파일의 읽기 및 쓰기를 공개적으로 허용할 수 있습니다. 이 방법은 [인증](https://firebase.google.com/docs/auth/?hl=ko)을 설정할 필요가 없으므로 프로토타입 개발을 시작할 때 유용합니다. **이 액세스 수준은 모든 사용자가 데이터베이스를 읽고 쓸 수 있음을 의미합니다. 앱을 출시하기 전에 보다 안전한 규칙을 구성해야 합니다.**

  ```
  // These rules give anyone, even people who are not users of your app,
  // read and write access to your database
  {
    "rules": {
      ".read": true,
      ".write": true
    }
  }
  ```

  사용자만 공개

  > 다음은 인증된 각 사용자에게 개인 노드(`/users/$user_id`)를 제공하는 규칙의 예시입니다. 여기에서 `$user_id`는 [인증](https://firebase.google.com/docs/auth/?hl=ko)을 통해 확인된 사용자 ID입니다. 개별 사용자의 비공개 데이터를 갖고 있는 앱에서 흔히 볼 수 있는 시나리오입니다.

  ```
  // These rules grant access to a node matching the authenticated
  // user's ID from the Firebase auth token
  {
    "rules": {
      "users": {
        "$uid": {
          ".read": "$uid === auth.uid",
          ".write": "$uid === auth.uid"
        }
      }
    }
  }
  ```

  비공개

  > 비공개 규칙은 사용자의 데이터베이스 읽기 및 쓰기 액세스를 금지합니다. 이 규칙을 사용하면 [Firebase 콘솔](https://console.firebase.google.com/?hl=ko)을 통해서만 데이터베이스에 액세스할 수 있습니다.

  ```
  // These rules don't allow anyone read or write access to your database
  {
    "rules": {
      ".read": false,
      ".write": false
    }
  }
  ```

  

  ## 사용자 기반 보안 

  

  **데이터보안** 의 개념을 복습하면서 사전 정의된  `auth`  변수를 통합하여 완벽한 데이터 보안 솔루션을 만들어 봅니다.

  

  ### 인증통합

  Firebase 인증은 Firebase 실시간 데이터베이스와 통합되어 사용자별 데이터 액세스를 제어하는 기능을 제공합니다. 

  

  사용자가 인증되면 Firebase 데이터베이스 규칙의    `auth`  변수에 사용자의 정보가 입력됩니다. 이 정보에는 고유식별자 (uid), 연결된 계정 데이터 (facebook Id 또는 이메일 주소) 및 기타 정보가 포함됩니다. 맞춤 인증 제공업체를 구현하는 경우 사용자의 인증 페이로드에 필드를 직접 추가할 수 있습니다. 

  -> *실시간 데이터베이스 규칙언어와 사용자의 인증 정보를 결합하는 방법을 설명*합니다. 두 개념을 사용하여 *사용자 ID에 따라 데이터 액세스 제어를 할 수 있습니다.* 

  

  ### auth 변수

  규칙에서 사전 정의된  `auth` '변수는 *인증이 완료되기전까지는 null 입니다.*

  Firebase 인증을 통해 *사용자가 인증되면 다음 속성이 포함됩니다.*  

| provider | 사용된 인증 방법('password', 'anonymous', 'facebook", 'github', 'google', 또는 'twitter') |
| -------- | ------------------------------------------------------------ |
| uid      | 고유 사용자 ID(제공업체에 관계없이 항상 고유함)              |
| token    | Firebase 인증                                                |



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



[list](#list)



# 실시간데이터베이스

## iOS에서 설치 및 설정



Firebase 실시간 데이터베이스는 클라우드 호스팅 데이터베이스입니다. 데이터는 JSON으로 저장되며 연결된 모든 클라이언트에 실시간으로 동기화됩니다. Android, iOS 및 자바스크립트 SDK로 교차 플랫폼 앱을 개발하면 모든 클라이언트가 하나의 실시간 데이터베이스 인스턴스를 공유하고 자동 업데이트로 최신 데이터를 수신합니다.

### Firebase 데이터베이스 규칙 구성

실시간 데이터베이스가 제공하는 선언적 규칙 언어로 데이터의 구조, 색인 생성 방법 및 데이터를 읽고 쓸 수 있는 조건을 정의할 수 있습니다. 기본적으로 데이터베이스에 대한 읽기 및 쓰기 액세스는 인증된 사용자만 데이터를 읽거나 쓸 수 있도록 제한됩니다. [인증](https://firebase.google.com/docs/auth/?hl=ko)을 설정하지 않고 개발을 시작하려면 [공개 액세스를 위해 규칙을 구성](https://firebase.google.com/docs/database/security/quickstart?hl=ko#sample-rules)하면 됩니다. 이렇게 하면 앱을 사용하지 않는 사람을 포함하여 모두에게 데이터베이스가 공개되므로 인증을 설정할 때 데이터베이스를 다시 제한해야 합니다.

### Firebase 실시간 데이터베이스 설정

Firebase 앱 참조를 만들거나 사용하려면 우선 Firebase를 초기화해야 합니다. 다른 Firebase 기능을 위해 이 단계를 이미 수행했다면 건너뛰어도 무방합니다.

1. `UIApplicationDelegate`에서 Firebase 모듈을 가져옵니다.

```
import Firebase
```

2. 일반적으로 애플리케이션의 `application:didFinishLaunchingWithOptions:` 메소드에서 [`FirebaseApp`](https://firebase.google.com/docs/reference/ios/firebasecore/api/reference/Classes/FIRApp?hl=ko) 공유 인스턴스를 구성합니다.

3. ```
   FirebaseApp.configure()
   ```

   

   Firebase 실시간 데이터베이스가 초기화되었으면 다음과 같이 데이터베이스 참조를 정의하고 생성합니다.

   ```
   var ref: DatabaseReference!
   
   ref = Database.database().reference()
   ```

 

 



## 데이터베이스 구조화

이 가이드에서는 Firebase 실시간 데이터베이스의 JSON 데이터 구조화와 관련된 주요 데이터 아키텍처 개념과 몇 가지 권장사항을 설명합니다.

데이터베이스를 적절히 구조화하려면 철저한 사전 준비가 필요합니다. 가장 중요한 것은 최대한 쉽게 데이터를 저장하고 이후에 검색할 방법에 대해 계획을 세우는 것입니다.

### 데이터의 구조: JSON 트리

모든 Firebase 실시간 데이터베이스 데이터는 JSON 개체로 저장됩니다. 데이터베이스를 클라우드 호스팅 JSON 트리라고 생각하면 됩니다. SQL 데이터베이스와 달리 테이블이나 레코드가 없으며, JSON 트리에 추가된 데이터는 연결된 키를 갖는 기존 JSON 구조의 노드가 됩니다. 사용자 ID 또는 의미 있는 이름을 키로 직접 지정할 수도 있고, [`childByAutoId`](https://firebase.google.com/docs/reference/ios/firebasedatabase/interface_f_i_r_database_reference.html?hl=ko#a18f449729a922397587a9f0c5e0ab812)를 사용하여 자동으로 지정할 수도 있습니다.

키를 직접 만드는 경우 키는 UTF-8로 인코딩되어야 하고 768바이트 이하여야 하며 `.`, `$`, `#`, `[`, `]`, `/`, ASCII 제어문자 0~31 또는 127을 포함할 수 없습니다.

예를 들어 사용자가 기본적인 프로필과 연락처 목록을 저장할 수 있는 채팅 애플리케이션을 가정해 보겠습니다. 사용자 프로필은 일반적으로 `/users/$uid`와 같은 경로에 위치합니다. 사용자 `alovelace`의 데이터베이스 항목은 다음과 같이 표시됩니다.

```
{
  "users": {
    "alovelace": {
      "name": "Ada Lovelace",
      "contacts": { "ghopper": true },
    },
    "ghopper": { ... },
    "eclarke": { ... }
  }
}
```

데이터베이스는 JSON 트리를 사용하지만 데이터베이스에 저장되는 데이터는 사용 가능한 JSON 유형에 대응하는 특정한 기본 유형으로 표현하여 코드를 보다 쉽게 관리할 수 있습니다.

### 데이터 구조 권장사항

#### 데이터 중첩 배제

Firebase 실시간 데이터베이스는 최대 32단계의 데이터 중첩을 허용하므로 기본 구조에 중첩을 도입해도 괜찮다고 생각할 수도 있습니다. 그러나 데이터베이스의 특정 위치에서 데이터를 가져오면 모든 하위 노드가 함께 검색됩니다. 또한 사용자에게 데이터베이스의 특정 노드에 대한 읽기 또는 쓰기 권한을 부여하면 해당 노드에 속한 모든 데이터에 대한 권한이 함께 부여됩니다. 따라서 실제 구현에서는 데이터 구조를 최대한 평면화하는 것이 좋습니다.

다음은 데이터 중첩을 배제해야 하는 이유를 보여 주는 다중첩 구조의 예입니다.

```
{
  // This is a poorly nested data architecture, because iterating the children
  // of the "chats" node to get a list of conversation titles requires
  // potentially downloading hundreds of megabytes of messages
  "chats": {
    "one": {
      "title": "Historical Tech Pioneers",
      "messages": {
        "m1": { "sender": "ghopper", "message": "Relay malfunction found. Cause: moth." },
        "m2": { ... },
        // a very long list of messages
      }
    },
    "two": { ... }
  }
}
```

이 중첩 설계에서는 전체 데이터 반복이 어렵습니다. 예를 들어 채팅 대화 제목을 나열하려면 모든 회원과 메시지를 포함하여 전체 `chats` 트리를 클라이언트에 다운로드해야 합니다.

#### 데이터 구조 평면화

비정규화를 통해 데이터를 서로 다른 경로로 분할하면 필요에 따라 별도의 호출을 통해 효율적으로 다운로드할 수 있습니다. 아래의 평면화된 구조를 살펴 보세요.

```
{
  // Chats contains only meta info about each conversation
  // stored under the chats's unique ID
  "chats": {
    "one": {
      "title": "Historical Tech Pioneers",
      "lastMessage": "ghopper: Relay malfunction found. Cause: moth.",
      "timestamp": 1459361875666
    },
    "two": { ... },
    "three": { ... }
  },

  // Conversation members are easily accessible
  // and stored by chat conversation ID
  "members": {
    // we'll talk about indices like this below
    "one": {
      "ghopper": true,
      "alovelace": true,
      "eclarke": true
    },
    "two": { ... },
    "three": { ... }
  },

  // Messages are separate from data we may want to iterate quickly
  // but still easily paginated and queried, and organized by chat
  // conversation ID
  "messages": {
    "one": {
      "m1": {
        "name": "eclarke",
        "message": "The relay seems to be malfunctioning.",
        "timestamp": 1459361875337
      },
      "m2": { ... },
      "m3": { ... }
    },
    "two": { ... },
    "three": { ... }
  }
}
```

이제 대화당 몇 바이트만 다운로드하여 대화방 목록 전체를 반복하면서 메타데이터를 가져와서 UI에 대화방을 나열하거나 표시할 수 있습니다. 메시지가 도착하면 별도로 메시지를 가져와서 표시할 수 있으므로 UI가 빠른 반응 속도를 유지합니다.

#### 확장 가능한 데이터 만들기

앱을 개발할 때는 목록의 일부만 다운로드하는 것이 나을 때가 많습니다. 목록에 수천 개의 레코드가 포함된 경우에 특히 그러합니다. 이 관계가 정적이며 일방적인 경우에는 상위 개체 아래에 하위 개체를 중첩하면 간단히 해결됩니다.

경우에 따라서는 이 관계가 동적이거나 데이터를 비정규화해야 할 수 있습니다. 대체적으로 쿼리를 사용하여 데이터의 일부를 검색하면 데이터를 비정규화할 수 있습니다. 자세한 내용은 [데이터 검색](https://firebase.google.com/docs/database/ios/retrieve-data?hl=ko)을 참조하세요.

이 방법도 충분하지 않을 수 있습니다. 사용자와 그룹 간의 양방향 관계를 예로 들 수 있습니다. 사용자는 그룹에 속할 수 있으며, 그룹은 사용자의 목록으로 구성됩니다. 이때 사용자가 어떠한 그룹에 속할지를 결정하려면 문제가 다소 복잡해집니다.

이러한 경우 특정 사용자가 속하는 그룹을 나열하고 해당 그룹의 데이터만 가져오는 깔끔한 방법이 필요합니다. 이때 그룹 *색인*이 상당한 도움이 될 수 있습니다.

```
// An index to track Ada's memberships
{
  "users": {
    "alovelace": {
      "name": "Ada Lovelace",
      // Index Ada's groups in her profile
      "groups": {
         // the value here doesn't matter, just that the key exists
         "techpioneers": true,
         "womentechmakers": true
      }
    },
    ...
  },
  "groups": {
    "techpioneers": {
      "name": "Historical Tech Pioneers",
      "members": {
        "alovelace": true,
        "ghopper": true,
        "eclarke": true
      }
    },
    ...
  }
}
```

위와 같이 Ada의 레코드와 그룹 모두에 관계를 저장하면 일부 데이터가 중복됨을 알 수 있습니다. `alovelace`는 그룹 아래에 색인화되었고 `techpioneers`는 Ada의 프로필에 나열되었습니다. 따라서 Ada를 그룹에서 삭제하려면 두 위치에서 업데이트가 이루어져야 합니다.

이러한 중복성은 양방향 관계에서 불가피합니다. 사용자 또는 그룹 목록이 수백만으로 늘어나거나 실시간 데이터베이스 보안 규칙으로 인해 일부 레코드에 액세스할 수 없더라도 이 중복성 덕분에 Ada의 소속 그룹을 빠르고 효율적으로 확인할 수 있습니다.

이와 같이 ID를 키로 나열하고 값을 true로 설정하여 데이터를 반전하는 방식을 사용하면 키를 확인할 때 `/users/$uid/groups/$group_id`를 읽어서 `null`인지만 확인하면 됩니다. 색인은 데이터보다 쿼리 또는 스캔 속도가 빠르고 훨씬 효율적입니다.

## 



 ## ios에서 데이터 읽기 및 쓰기

### FIRDatabaseReference 가져오기

데이터베이스에서 데이터를 읽거나 쓰려면 `FIRDatabaseReference`의 인스턴스가 필요합니다.

```
var ref: DatabaseReference!

ref = Database.database().reference()
```

### 데이터 읽기 및 쓰기

이 문서에서는 Firebase 데이터를 읽고 쓰는 기초적인 방법을 설명합니다.

Firebase 데이터는 `FIRDatabase` 참조에 기록되며, 데이터를 검색하려면 참조에 비동기 리스너를 연결합니다. 리스너는 데이터의 초기 상태가 확인될 때 한 번 호출된 후 데이터가 변경될 때마다 다시 호출됩니다.

> **참고:** 기본적으로 데이터베이스에 대한 읽기 및 쓰기 액세스는 인증된 사용자만 데이터를 읽거나 쓸 수 있도록 제한되어 있습니다. [인증](https://firebase.google.com/docs/auth/?hl=ko)을 설정하지 않고 개발을 시작하려면 [공개 액세스를 위해 규칙을 구성](https://firebase.google.com/docs/database/security/quickstart?hl=ko#sample-rules)하면 됩니다. 이렇게 하면 앱을 사용하지 않는 사람을 포함하여 모두에게 데이터베이스가 공개되므로 인증을 설정할 때 데이터베이스를 다시 제한해야 합니다.



### 기본 쓰기 작업

기본 쓰기 작업의 경우 `setValue`를 사용하여 지정된 참조에 데이터를 저장하고 기존 경로의 모든 데이터를 대체할 수 있습니다. 이 메소드의 용도는 다음과 같습니다.

- 사용 가능한 JSON 유형에 해당하는 다음과 같은 유형을 전달합니다.

  * `NSString`

  - `NSNumber`
  - `NSDictionary`
  - `NSArray`

예를 들어 `setValue`로 다음과 같이 사용자를 추가할 수 있습니다.

```
self.ref.child("users").child(user.uid).setValue(["username": username]
```

이 방법으로 `setValue`를 사용하면 지정된 위치에서 하위 노드를 포함하여 모든 데이터를 덮어씁니다. 그러나 전체 개체를 다시 쓰지 않고도 하위 항목을 업데이트하는 방법이 있습니다. 사용자가 프로필을 업데이트하는 것을 허용하려면 다음과 같이 사용자 이름을 업데이트할 수 있습니다.

```
self.ref.child("users/\(user.uid)/username").setValue(username)
```

### value 이벤트 수신 대기

특정 경로의 데이터를 읽고 변경을 수신 대기하려면 `FIRDatabaseReference`의 `observeEventType:withBlock` 또는 `observeSingleEventOfType:withBlock` 메소드를 사용하여 `FIRDataEventTypeValue` 이벤트를 관찰합니다.



> **중요:** `FIRDataEventTypeValue` 이벤트는 지정된 데이터베이스 참조의 데이터 및 하위 데이터가 변경될 때마다 발생합니다. 스냅샷의 크기를 제한하려면 변경을 확인할 필요가 있는 최상위 위치에만 연결하세요. 예를 들어 데이터베이스 루트에 리스너를 연결하는 것은 좋은 방법이 아닙니다.

다음 예제에서는 데이터베이스에서 글의 세부정보를 검색하는 소셜 블로깅 애플리케이션을 보여 줍니다

```
refHandle = postRef.observe(DataEventType.value, with: { (snapshot) in
  let postDict = snapshot.value as? [String : AnyObject] ?? [:]
  // ...
})
```

리스너는 이벤트 발생 시점에 데이터베이스에서 지정된 위치에 있던 데이터를 `value`속성에 포함하는 `FIRDataSnapshot`을 수신합니다. 이 값을 `NSDictionary` 등의 적절한 기본 유형에 대입할 수 있습니다. 해당 위치에 데이터가 없는 경우 `value`는 `nil`입니다.



### 데이터 한 번 읽기

한 번만 호출되고 즉시 삭제되는 콜백이 필요한 경우가 있습니다. 이후에 변경되지 않는 UI 요소를 초기화할 때가 그 예입니다. 이러한 경우 `observeSingleEventOfType` 메소드를 사용하면 시나리오가 단순해집니다. 이렇게 추가된 이벤트 콜백은 한 번 호출된 후 다시 호출되지 않습니다.

이 방법은 한 번 로드된 후 자주 변경되지 않거나 능동적으로 수신 대기할 필요가 없는 데이터에 유용합니다. 예를 들어 위 예시의 블로깅 앱에서는 사용자가 새 글을 작성하기 시작할 때 이 메소드로 사용자의 프로필을 로드합니다.

```
let userID = Auth.auth().currentUser?.uid
ref.child("users").child(userID!).observeSingleEvent(of: .value, with: { (snapshot) in
  // Get user value
  let value = snapshot.value as? NSDictionary
  let username = value?["username"] as? String ?? ""
  let user = User(username: username)

  // ...
  }) { (error) in
    print(error.localizedDescription)
}
```

## 데이터 업데이트 또는 삭제

### 특정 필드 업데이트

다른 하위 노드를 덮어쓰지 않고 특정 하위 노드에 동시에 쓰려면`updateChildValues` 메소드를 사용합니다.

`updateChildValues`을 호출할 때 키의 경로를 지정하여 하위 수준 값을 업데이트할 수 있습니다. 확장성을 위해 여러 위치에 데이터가 저장된 경우 [데이터 팬아웃](https://firebase.google.com/docs/database/ios/structure-data?hl=ko#fanout)을 사용하여 해당 데이터의 모든 인스턴스를 업데이트할 수 있습니다. 예를 들어 소셜 블로깅 애플리케이션에서 글을 만든 후 최근 활동 피드 및 게시자의 활동 피드에 동시에 업데이트해야 할 수 있습니다. 이러한 경우 다음과 같은 코드를 사용합니다.

```
let key = ref.child("posts").childByAutoId().key
let post = ["uid": userID,
            "author": username,
            "title": title,
            "body": body]
let childUpdates = ["/posts/\(key)": post,
                    "/user-posts/\(userID)/\(key)/": post]
ref.updateChildValues(childUpdates)
```

이 예제에서는 `childByAutoId`를 사용하여 모든 사용자의 글을 포함하는 노드(`/posts/$postid`)에 글을 만드는 동시에 `getKey()`로 키를 검색합니다. 그런 다음 이 키로 사용자의 글 목록(`/user-posts/$userid/$postid`)에 두 번째 항목을 만듭니다.

이러한 경로를 사용하면 이 예제에서 두 위치에 새 글을 만드는 방법과 같이 `updateChildValues`를 한 번만 호출하여 JSON 트리의 여러 위치에 동시에 업데이트할 수 있습니다. 이러한 동시 업데이트는 유기적 종속성을 갖습니다. 즉, 모든 업데이트가 한꺼번에 성공하거나 실패합니다.

### 데이터 삭제

데이터를 삭제하는 가장 간단한 방법은 해당 데이터 위치의 참조에 대해`removeValue`를 호출하는 것입니다.

`setValue` 또는 `updateChildValues` 등의 다른 쓰기 작업에 대한 값으로 `nil`을 지정하여 삭제할 수도 있습니다. `updateChildValues`에 이 방법을 사용하면 API를 한 번 호출하여 여러 하위 항목을 삭제할 수 있습니다.

### 리스너 분리

관찰자는 `ViewController`에서 벗어날 때 데이터 동기화를 자동으로 중지하지 않습니다. 관찰자를 적절히 삭제하지 않으면 데이터가 계속 로컬 메모리에 동기화됩니다. 관찰자가 더 이상 필요하지 않은 경우 `removeObserverWithHandle` 메소드에 해당 `FIRDatabaseHandle`을 전달하여 삭제하세요.

참조에 콜백 블록을 추가하면 `FIRDatabaseHandle`이 반환됩니다. 이 핸들을 사용하여 콜백 블록을 삭제할 수 있습니다.

한 데이터베이스 참조에 여러 리스너를 추가하면 이벤트가 발생할 때 각 리스너가 모두 호출됩니다. 해당 위치의 데이터 동기화를 중지하려면 `removeAllObservers` 메소드를 호출하여 모든 관찰자를 삭제해야 합니다.

리스너에서 `removeObserverWithHandle` 또는 `removeAllObservers`를 호출해도 하위 노드에 등록된 리스너는 자동으로 삭제되지 않으므로 이러한 참조 또는 핸들을 추적하여 직접 삭제해야 합니다.

### 데이터를 트랜잭션으로 저장

증가 카운터와 같이 동시 수정으로 인해 손상될 수 있는 데이터를 다루는 경우 [트랜잭션 작업](https://firebase.google.com/docs/reference/ios/firebasedatabase/interface_f_i_r_database_reference.html?hl=ko#a796bff455159479a44b225eeaa2ba9d6)을 사용할 수 있습니다. 이 작업에 지정하는 두 인수는 업데이트 함수 및 선택적 완료 콜백입니다. 업데이트 함수는 데이터의 현재 상태를 인수로 취하고 이 데이터에 새로 기록하려는 값을 반환합니다.

예를 들어 소셜 블로깅 앱에서는 다음과 같이 사용자가 글에 별표를 주거나 삭제할 수 있고 글이 별표를 몇 개 받았는지 집계할 수 있습니다.

```
ref.runTransactionBlock({ (currentData: MutableData) -> TransactionResult in
  if var post = currentData.value as? [String : AnyObject], let uid = Auth.auth().currentUser?.uid {
    var stars: Dictionary<String, Bool>
    stars = post["stars"] as? [String : Bool] ?? [:]
    var starCount = post["starCount"] as? Int ?? 0
    if let _ = stars[uid] {
      // Unstar the post and remove self from stars
      starCount -= 1
      stars.removeValue(forKey: uid)
    } else {
      // Star the post and add self to stars
      starCount += 1
      stars[uid] = true
    }
    post["starCount"] = starCount as AnyObject?
    post["stars"] = stars as AnyObject?

    // Set value and report transaction success
    currentData.value = post

    return TransactionResult.success(withValue: currentData)
  }
  return TransactionResult.success(withValue: currentData)
}) { (error, committed, snapshot) in
  if let error = error {
    print(error.localizedDescription)
  }
}
```

 트랜잭션을 사용하면 여러 사용자가 같은 글에 동시에 별표를 주거나 클라이언트 데이터의 동기화가 어긋나도 별표가 잘못 집계되지 않습니다. `FIRMutableData` 클래스에 포함되는 값은 애초에 해당 경로에 대해 클라이언트에 마지막으로 알려진 값이거나 값이 없는 경우 `nil`입니다. 서버는 초기 값과 현재 값을 비교하여 값이 일치하면 트랜잭션을 수락하고, 그렇지 않으면 거부합니다. 트랜잭션이 거부되면 서버에서 현재 값을 클라이언트에 반환하며, 클라이언트는 업데이트된 값으로 트랜잭션을 다시 실행합니다. 트랜잭션이 수락되거나 시도가 일정 횟수를 초과할 때까지 이 과정이 반복됩니다.

**참고:** `runTransactionBlock:andCompletionBlock:`은 여러 번 호출되므로 `nil` 데이터를 처리할 수 있어야 합니다. 원격 데이터베이스에 기존 데이터가 있더라도 트랜잭션 함수가 실행될 때 로컬에 캐시된 데이터가 없으면 초기 값이 `nil`이 될 수도 있습니다.

### 오프라인으로 데이터 쓰기

클라이언트의 네트워크 연결이 끊겨도 앱은 계속 정상적으로 작동합니다.

Firebase 데이터베이스에 연결된 모든 클라이언트는 자체적으로 활성 데이터의 내부 버전을 유지합니다. 데이터를 쓰면 우선 로컬 버전에 기록됩니다. 그런 다음 Firebase 클라이언트가 해당 데이터를 원격 데이터베이스 서버 및 다른 클라이언트와 '최선을 다해' 동기화합니다.

이와 같이 데이터베이스에 대한 모든 쓰기 작업은 로컬 이벤트를 즉시 발생시키며, 그 이후에 서버에 데이터가 기록됩니다. 따라서 앱은 네트워크 지연 또는 연결 여부에 관계없이 응답성을 유지합니다.

네트워크에 다시 연결되면 앱에서 적절한 이벤트 세트를 수신하여 클라이언트와 현재 서버 상태를 동기화하므로 맞춤 코드를 별도로 작성할 필요가 없습니다.

[list](#list)

 