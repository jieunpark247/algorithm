[![중포 기지](https://firebase.google.com/_static/2bced1f68f/images/firebase/lockup.png?authuser=1)](https://firebase.google.com/?authuser=1)

(https://firebase.google.com/docs/reference/ios/firebasedatabase/api/reference/Classes/FIRDatabaseReference?authuser=1#database)

# Firebase 데이터베이스 프레임 워크 참조

# FIRDatabaseReference

```
@interface FIRDatabaseReference : FIRDatabaseQuery
```

FIRDatabaseReference는 Firebase 데이터베이스의 특정 위치를 나타내며 Firebase 데이터베이스 위치로 데이터를 읽거나 쓸 수 있습니다.

이 클래스는 모든 Firebase 데이터베이스 작업의 시작점입니다. [FIRDatabase reference]를 통해 첫 번째 FIRDatabaseReference를 얻은 후에는 데이터 (예 : observeEventType : withBlock :)를 읽고 데이터 (예 : setValue :)를 작성하고 새 FIRDatabaseReferences (예 : child :)를 작성할 수 있습니다. .

[어린이 위치에 대한 참조 얻기](https://firebase.google.com/docs/reference/ios/firebasedatabase/api/reference/Classes/FIRDatabaseReference?authuser=1#/Getting%20references%20to%20children%20locations)

- `-child:`

  

  

  지정된 상대 경로에있는 위치의 FIRDatabaseReference를 가져옵니다. 상대 경로는 간단한 자식 키 (예 : 'fred') 또는 더 깊은 슬래시로 구분 된 경로 (예 : 'fred / name / first') 일 수 있습니다.

  #### 선언

  목표 -C

  ```
  - (nonnull FIRDatabaseReference *)child:(nonnull NSString *)pathString;
  ```

  #### 매개 변수

  | `*pathString*` | 이 위치에서 원하는 하위 위치까지의 상대 경로입니다. |
  | -------------- | --------------------------------------------------- |
  |                |                                                     |

  #### 반환 값

  지정된 상대 경로에 대한 FIRDatabaseReference입니다.

- `-childByAppendingPath:`

  

  

  childByAppendingPath : 더 이상 사용되지 않으며, 대신 child :를 사용하십시오.

  #### 선언

  목표 -C

  ```
  - (nonnull FIRDatabaseReference *)childByAppendingPath:
      (nonnull NSString *)pathString;
  ```

- `-childByAutoId`

  

  

  childByAutoId는 고유 키를 사용하여 새 하위 위치를 생성하고 FIRDatabaseReference를 반환합니다. 이것은 Firebase 데이터베이스 위치의 하위 항목이 항목 목록을 나타내는 경우 유용합니다.

  childByAutoId :에 의해 생성 된 고유 키는 결과 목록이 시간순으로 정렬되도록 클라이언트 생성 타임 스탬프가 접두사로 사용됩니다.

  #### 선언

  목표 -C

  ```
  - (nonnull FIRDatabaseReference *)childByAutoId;
  ```

  #### 반환 값

  생성 된 위치에 대한 FIRDatabaseReference입니다.

[데이터 쓰기](https://firebase.google.com/docs/reference/ios/firebasedatabase/api/reference/Classes/FIRDatabaseReference?authuser=1#/Writing%20data)

- `-setValue:`

  

  

  이 Firebase 데이터베이스 위치에 데이터를 씁니다.

  이렇게하면이 위치의 모든 데이터와 모든 하위 위치를 덮어 씁니다.

  설정할 수있는 데이터 유형은 다음과 같습니다.

  - NSString - @ Hello World
  - NSNumber (부울 값 포함) - @YES, @ 43, @ 4.333
  - NSDictionary - @ {@ 키 : @ value , @ 중첩 : @ {@ another : @ value }}
  - NSArray

  쓰기 효과가 즉시 표시되고 해당 이벤트가 트리거됩니다. Firebase 데이터베이스 서버와의 데이터 동기화도 시작됩니다.

  새로운 값에 null를 건네 주는 것은 remove :;를 호출하는 것과 같습니다. 이 위치 또는 하위 위치의 모든 데이터가 삭제됩니다.

  setValue :는이 위치에 저장된 모든 우선 순위를 제거하므로 우선 순위를 유지하려는 경우 setValue : andPriority :를 사용해야합니다.

  #### 선언

  목표 -C

  ```
  - (void)setValue:(nullable id)value;
  ```

  #### 매개 변수

  | `*value*` | 쓸 값입니다. |
  | --------- | ------------ |
  |           |              |

- `-setValue:withCompletionBlock:`

  

  

  writeValue가 Firebase 데이터베이스 서버에 커밋 된 후에 트리거되는 블록과 setValue :와 동일합니다.

  #### 선언

  목표 -C

  ```
  - (void)setValue:(nullable id)value
      withCompletionBlock:(nonnull void (^)(NSError *_Nullable,
                                            FIRDatabaseReference *_Nonnull))block;
  ```

  #### 매개 변수

  | `*value*` | 쓸 값입니다.                                                 |
  | --------- | ------------------------------------------------------------ |
  | `*block*` | 쓰기가 Firebase 데이터베이스 서버에 커밋 된 후에 호출 할 블록입니다. |

- `-setValue:andPriority:`

  

  

  기록되는 데이터에 추가 우선 순위가있는 setValue :와 동일합니다. 우선 순위는 항목을 주문하는 데 사용됩니다.

  #### 선언

  목표 -C

  ```
  - (void)setValue:(nullable id)value andPriority:(nullable id)priority;
  ```

  #### 매개 변수

  | `*value*`    | 쓸 값입니다.                           |
  | ------------ | -------------------------------------- |
  | `*priority*` | 해당 데이터에 첨부 할 우선 순위입니다. |

- `-setValue:andPriority:withCompletionBlock:`

  

  

  쓰기 작업이 Firebase 데이터베이스 서버에 커밋 된 후에 트리거되는 블록과 setValue : andPriority :와 동일합니다.

  #### 선언

  목표 -C

  ```
  - (void)setValue:(nullable id)value
              andPriority:(nullable id)priority
      withCompletionBlock:(nonnull void (^)(NSError *_Nullable,
                                            FIRDatabaseReference *_Nonnull))block;
  ```

  #### 매개 변수

  | `*value*`    | 쓸 값입니다.                                                 |
  | ------------ | ------------------------------------------------------------ |
  | `*priority*` | 해당 데이터에 첨부 할 우선 순위입니다.                       |
  | `*block*`    | 쓰기가 Firebase 데이터베이스 서버에 커밋 된 후에 호출 할 블록입니다. |

- `-removeValue`

  

  

  이 Firebase 데이터베이스 위치에서 데이터를 제거하십시오. 하위 위치의 모든 데이터도 삭제됩니다.

  삭제의 효과가 즉시 표시되고 해당 이벤트가 트리거됩니다. Firebase 데이터베이스 서버에 대한 삭제 동기화도 시작됩니다.

  remove : setValue를 호출하는 것과 같습니다. nil

  #### 선언

  목표 -C

  ```
  - (void)removeValue;
  ```

- `-removeValueWithCompletionBlock:`

  

  

  제거 작업이 Firebase 데이터베이스 서버에 커밋 된 후에 트리거되는 블록과 함께 remove :와 동일합니다.

  #### 선언

  목표 -C

  ```
  - (void)removeValueWithCompletionBlock:
      (nonnull void (^)(NSError *_Nullable, FIRDatabaseReference *_Nonnull))block;
  ```

  #### 매개 변수

  | `*block*` | 제거가 Firebase 데이터베이스 서버에 커밋 된 후에 호출 할 블록입니다. |
  | --------- | ------------------------------------------------------------ |
  |           |                                                              |

- `-setPriority:`

  

  

  이 Firebase 데이터베이스 위치의 데이터 우선 순위를 설정합니다. 우선 순위를 사용하여 특정 위치의 어린이를위한 맞춤 주문을 제공 할 수 있습니다 (우선 순위가 지정되지 않은 경우 자녀는 키순으로 정렬 됨).

  빈 위치에 우선 순위를 설정할 수 없습니다. 이러한 이유 때문에 setValue : andPriority :는 특정 우선 순위로 초기 데이터를 설정할 때 사용해야하며 setPriority :는 기존 데이터의 우선 순위를 업데이트 할 때 사용해야합니다.

  어린이는 다음 규칙을 사용하여 우선 순위에 따라 정렬됩니다.

  우선 순위가없는 아이들이 먼저옵니다. 우선 순위에 숫자가있는 아이들이 다음에옵니다. 그들은 우선 순위 (작은 것에서 큰 것)에 의해 수치 적으로 정렬됩니다. 우선 순위에 따라 문자열을 가진 아이들이 마지막으로옵니다. 우선 순위에 따라 사전 순으로 정렬됩니다. 두 어린이가 같은 우선 순위 (우선 순위 없음 포함)를 가질 때마다 키순으로 정렬됩니다. 숫자 키가 먼저 나오고 (숫자순으로 정렬 된) 나머지 키가옵니다 (사전 식으로 정렬 됨).

  우선 순위는 IEEE 754 배정도 부동 소수점 숫자로 구문 분석되고 정렬됩니다. 키는 항상 문자열로 저장되며 32 비트 정수로 구문 분석 될 수있는 경우에만 숫자로 처리됩니다.

  #### 선언

  목표 -C

  ```
  - (void)setPriority:(nullable id)priority;
  ```

  #### 매개 변수

  | `*priority*` | 지정된 위치에 설정할 우선 순위입니다. |
  | ------------ | ------------------------------------- |
  |              |                                       |

- `-setPriority:withCompletionBlock:`

  

  

  setPriority : Firebase 데이터베이스 서버에 우선 순위가 지정되면 호출되는 블록과 동일합니다.

  #### 선언

  목표 -C

  ```
  - (void)setPriority:(nullable id)priority
      withCompletionBlock:(nonnull void (^)(NSError *_Nullable,
                                            FIRDatabaseReference *_Nonnull))block;
  ```

  #### 매개 변수

  | `*priority*` | 지정된 위치에 설정할 우선 순위입니다.                |
  | ------------ | ---------------------------------------------------- |
  | `*block*`    | 서버에 우선 순위가 기록 된 후 트리거되는 블록입니다. |

- `-updateChildValues:`

  

  

  사전에 지정된 경로의 값을이 위치의 다른 키를 덮어 쓰지 않고 업데이트합니다.

  #### 선언

  목표 -C

  ```
  - (void)updateChildValues:(nonnull NSDictionary *)values;
  ```

  #### 매개 변수

  | `*values*` | 변경할 키 사전 및 새 값 |
  | ---------- | ----------------------- |
  |            |                         |

- `-updateChildValues:withCompletionBlock:`

  

  

  업데이트와 동일 : 업데이트가 Firebase 데이터베이스 서버에 커밋 된 블록이 호출됩니다.

  #### 선언

  목표 -C

  ```
  - (void)updateChildValues:(nonnull NSDictionary *)values
        withCompletionBlock:
            (nonnull void (^)(NSError *_Nullable,
                              FIRDatabaseReference *_Nonnull))block;
  ```

  #### 매개 변수

  | `*values*` | 변경할 키 사전 및 새 값                                      |
  | ---------- | ------------------------------------------------------------ |
  | `*block*`  | 업데이트가 Firebase 데이터베이스 서버에 기록 된 후 트리거되는 블록 |

[데이터를 읽는 관찰자 첨부](https://firebase.google.com/docs/reference/ios/firebasedatabase/api/reference/Classes/FIRDatabaseReference?authuser=1#/Attaching%20observers%20to%20read%20data)

- `-observeEventType:withBlock:`

  

  

  observeEventType : withBlock : 특정 위치에서 데이터 변경 내용을 수신하는 데 사용됩니다. 이것이 Firebase 데이터베이스에서 데이터를 읽는 주요 방법입니다. 블록이 초기 데이터에 대해 트리거되고 데이터가 변경 될 때마다 다시 트리거됩니다.

  removeObserverWithHandle :을 사용하여 업데이트 수신을 중지하십시오.

  #### 선언

  목표 -C

  ```
  - (FIRDatabaseHandle)
  observeEventType:(FIRDataEventType)eventType
         withBlock:(nonnull void (^)(FIRDataSnapshot *_Nonnull))block;
  ```

  #### 매개 변수

  | `*eventType*` | 수신 대기 할 이벤트 유형입니다.                              |
  | ------------- | ------------------------------------------------------------ |
  | `*block*`     | 초기 데이터 및 업데이트와 함께 호출되어야하는 블록. FIRDataSnapshot으로 데이터가 전달됩니다. |

  #### 반환 값

  나중에 removeObserverWithHandle을 사용하여이 블록을 등록 취소하는 데 사용되는 핸들입니다.

- `-observeEventType:andPreviousSiblingKeyWithBlock:`

  

  

  observeEventType : andPreviousSiblingKeyWithBlock : 특정 위치에서 데이터 변경 내용을 수신하는 데 사용됩니다. 이것이 Firebase 데이터베이스에서 데이터를 읽는 주요 방법입니다. 블록이 초기 데이터에 대해 트리거되고 데이터가 변경 될 때마다 다시 트리거됩니다. 또한 FIRDataEventTypeChildAdded, FIRDataEventTypeChildMoved 및 FIRDataEventTypeChildChanged 이벤트의 경우 블록에 우선 순위에 따라 이전 노드의 키가 전달됩니다.

  removeObserverWithHandle :을 사용하여 업데이트 수신을 중지하십시오.

  #### 선언

  목표 -C

  ```
  - (FIRDatabaseHandle)observeEventType:(FIRDataEventType)eventType
         andPreviousSiblingKeyWithBlock:
             (nonnull void (^)(FIRDataSnapshot *_Nonnull,
                               NSString *_Nullable))block;
  ```

  #### 매개 변수

  | `*eventType*` | 수신 대기 할 이벤트 유형입니다.                              |
  | ------------- | ------------------------------------------------------------ |
  | `*block*`     | 초기 데이터 및 업데이트와 함께 호출되어야하는 블록. FIRDataSnapshot 및 이전 하위 키로 데이터가 전달됩니다. |

  #### 반환 값

  나중에 removeObserverWithHandle을 사용하여이 블록을 등록 취소하는 데 사용되는 핸들입니다.

- `-observeEventType:withBlock:withCancelBlock:`

  

  

  observeEventType : withBlock : 특정 위치에서 데이터 변경 내용을 수신하는 데 사용됩니다. 이것이 Firebase 데이터베이스에서 데이터를 읽는 주요 방법입니다. 블록이 초기 데이터에 대해 트리거되고 데이터가 변경 될 때마다 다시 트리거됩니다.

  더 이상 권한이 없기 때문에 더 이상 새 이벤트를 수신하지 않을 경우 cancelBlock이 호출됩니다.

  removeObserverWithHandle :을 사용하여 업데이트 수신을 중지하십시오.

  #### 선언

  목표 -C

  ```
  - (FIRDatabaseHandle)
  observeEventType:(FIRDataEventType)eventType
         withBlock:(nonnull void (^)(FIRDataSnapshot *_Nonnull))block
   withCancelBlock:(nullable void (^)(NSError *_Nonnull))cancelBlock;
  ```

  #### 매개 변수

  | `*eventType*`   | 수신 대기 할 이벤트 유형입니다.                              |
  | --------------- | ------------------------------------------------------------ |
  | `*block*`       | 초기 데이터 및 업데이트와 함께 호출되어야하는 블록. FIRDataSnapshot으로 데이터가 전달됩니다. |
  | `*cancelBlock*` | 이 클라이언트가 더 이상 이러한 이벤트를 수신 할 권한이없는 경우 호출해야하는 블록 |

  #### 반환 값

  나중에 removeObserverWithHandle을 사용하여이 블록을 등록 취소하는 데 사용되는 핸들입니다.

- `-observeEventType:andPreviousSiblingKeyWithBlock:withCancelBlock:`

  

  

  observeEventType : andPreviousSiblingKeyWithBlock : 특정 위치에서 데이터 변경 내용을 수신하는 데 사용됩니다. 이것이 Firebase 데이터베이스에서 데이터를 읽는 주요 방법입니다. 블록이 초기 데이터에 대해 트리거되고 데이터가 변경 될 때마다 다시 트리거됩니다. 또한 FIRDataEventTypeChildAdded, FIRDataEventTypeChildMoved 및 FIRDataEventTypeChildChanged 이벤트의 경우 블록에 우선 순위에 따라 이전 노드의 키가 전달됩니다.

  더 이상 권한이 없기 때문에 더 이상 새 이벤트를 수신하지 않을 경우 cancelBlock이 호출됩니다.

  removeObserverWithHandle :을 사용하여 업데이트 수신을 중지하십시오.

  #### 선언

  목표 -C

  ```
  - (FIRDatabaseHandle)observeEventType:(FIRDataEventType)eventType
         andPreviousSiblingKeyWithBlock:
             (nonnull void (^)(FIRDataSnapshot *_Nonnull,
                               NSString *_Nullable))block
                        withCancelBlock:
                            (nullable void (^)(NSError *_Nonnull))cancelBlock;
  ```

  #### 매개 변수

  | `*eventType*`   | 수신 대기 할 이벤트 유형입니다.                              |
  | --------------- | ------------------------------------------------------------ |
  | `*block*`       | 초기 데이터 및 업데이트와 함께 호출되어야하는 블록. FIRDataSnapshot 및 이전 하위 키로 데이터가 전달됩니다. |
  | `*cancelBlock*` | 이 클라이언트가 더 이상 이러한 이벤트를 수신 할 권한이없는 경우 호출해야하는 블록 |

  #### 반환 값

  나중에 removeObserverWithHandle을 사용하여이 블록을 등록 취소하는 데 사용되는 핸들입니다.

- `-observeSingleEventOfType:withBlock:`

  

  

  이것은 observeEventType : withBlock :와 같습니다. 단, 블록이 초기 데이터가 반환 된 후 즉시 취소된다는 점이 다릅니다.

  #### 선언

  목표 -C

  ```
  - (void)observeSingleEventOfType:(FIRDataEventType)eventType
                         withBlock:
                             (nonnull void (^)(FIRDataSnapshot *_Nonnull))block;
  ```

  #### 매개 변수

  | `*eventType*` | 수신 대기 할 이벤트 유형입니다.                             |
  | ------------- | ----------------------------------------------------------- |
  | `*block*`     | 호출해야하는 블록. FIRDataSnapshot으로 데이터가 전달됩니다. |

- `-observeSingleEventOfType:andPreviousSiblingKeyWithBlock:`

  

  

  이것은 observeEventType : withBlock :와 같습니다. 단, 블록이 초기 데이터가 반환 된 후 즉시 취소된다는 점이 다릅니다. 또한 FIRDataEventTypeChildAdded, FIRDataEventTypeChildMoved 및 FIRDataEventTypeChildChanged 이벤트의 경우 블록에 우선 순위에 따라 이전 노드의 키가 전달됩니다.

  #### 선언

  목표 -C

  ```
  - (void)observeSingleEventOfType:(FIRDataEventType)eventType
      andPreviousSiblingKeyWithBlock:
          (nonnull void (^)(FIRDataSnapshot *_Nonnull, NSString *_Nullable))block;
  ```

  #### 매개 변수

  | `*eventType*` | 수신 대기 할 이벤트 유형입니다.                              |
  | ------------- | ------------------------------------------------------------ |
  | `*block*`     | 호출해야하는 블록. FIRDataSnapshot 및 이전 하위 키로 데이터가 전달됩니다. |

- `-observeSingleEventOfType:withBlock:withCancelBlock:`

  

  

  이것은 observeEventType : withBlock :와 같습니다. 단, 블록이 초기 데이터가 반환 된 후 즉시 취소된다는 점이 다릅니다.

  이 위치에서 데이터를 읽을 수있는 권한이 없으면 cancelBlock이 호출됩니다.

  #### 선언

  목표 -C

  ```
  - (void)
  observeSingleEventOfType:(FIRDataEventType)eventType
                 withBlock:(nonnull void (^)(FIRDataSnapshot *_Nonnull))block
           withCancelBlock:(nullable void (^)(NSError *_Nonnull))cancelBlock;
  ```

  #### 매개 변수

  | `*eventType*`   | 수신 대기 할 이벤트 유형입니다.                             |
  | --------------- | ----------------------------------------------------------- |
  | `*block*`       | 호출해야하는 블록. FIRDataSnapshot으로 데이터가 전달됩니다. |
  | `*cancelBlock*` | 이 데이터에 액세스 할 수있는 권한이없는 경우 호출 될 블록   |

- `-observeSingleEventOfType:andPreviousSiblingKeyWithBlock:withCancelBlock:`

  

  

  이것은 observeEventType : withBlock :와 같습니다. 단, 블록이 초기 데이터가 반환 된 후 즉시 취소된다는 점이 다릅니다. 또한 FIRDataEventTypeChildAdded, FIRDataEventTypeChildMoved 및 FIRDataEventTypeChildChanged 이벤트의 경우 블록에 우선 순위에 따라 이전 노드의 키가 전달됩니다.

  이 위치에서 데이터를 읽을 수있는 권한이 없으면 cancelBlock이 호출됩니다.

  #### 선언

  목표 -C

  ```
  - (void)observeSingleEventOfType:(FIRDataEventType)eventType
      andPreviousSiblingKeyWithBlock:(nonnull void (^)(FIRDataSnapshot *_Nonnull,
                                                       NSString *_Nullable))block
                     withCancelBlock:
                         (nullable void (^)(NSError *_Nonnull))cancelBlock;
  ```

  #### 매개 변수

  | `*eventType*`   | 수신 대기 할 이벤트 유형입니다.                              |
  | --------------- | ------------------------------------------------------------ |
  | `*block*`       | 호출해야하는 블록. FIRDataSnapshot 및 이전 하위 키로 데이터가 전달됩니다. |
  | `*cancelBlock*` | 이 데이터에 액세스 할 수있는 권한이없는 경우 호출 될 블록    |

[옵저버 분리](https://firebase.google.com/docs/reference/ios/firebasedatabase/api/reference/Classes/FIRDatabaseReference?authuser=1#/Detaching%20observers)

- `-removeObserverWithHandle:`

  

  

  이전에 observeEventType : withBlock :과 연결된 블록을 분리합니다.

  #### 선언

  목표 -C

  ```
  - (void)removeObserverWithHandle:(FIRDatabaseHandle)handle;
  ```

  #### 매개 변수

  | `*handle*` | observeEventType : withBlock :을 호출하여 반환 된 핸들입니다. |
  | ---------- | ------------------------------------------------------------ |
  |            |                                                              |

- `-keepSynced:`

  

  

  `keepSynced:YES`위치 를 호출 하면 해당 위치의 데이터가 자동으로 다운로드되고 해당 위치에 리스너가 연결되지 않은 경우에도 동기화됩니다. 또한 위치 동기화가 유지되는 동안 영구 디스크 캐시에서 제거되지 않습니다.

  #### 선언

  목표 -C

  ```
  - (void)keepSynced:(BOOL)keepSynced;
  ```

  #### 매개 변수

  | `*keepSynced*` | 이 위치를 동기화하려면 YES를 전달하고 동기화를 중지하려면 NO를 전달하십시오. |
  | -------------- | ------------------------------------------------------------ |
  |                |                                                              |

- `-removeAllObservers`

  

  

  현재 참조에서 모든 관찰자를 제거하지만 하위 참조에서 관찰자를 제거하지 않습니다. 관찰자를 제거하기 위해 리스너가 설정된 각 하위 참조에 대해 removeAllObservers를 다시 호출해야합니다.

  #### 선언

  목표 -C

  ```
  - (void)removeAllObservers;
  ```

[쿼리 및 제한](https://firebase.google.com/docs/reference/ios/firebasedatabase/api/reference/Classes/FIRDatabaseReference?authuser=1#/Querying%20and%20limiting)

- `-queryLimitedToFirst:`

  

  

  queryLimitedToFirst :이 위치에서 데이터의 제한된보기에 대한 참조를 생성하는 데 사용됩니다. queryLimitedToFirst에 의해 반환되는 FIRDatabaseQuery 인스턴스 : 가장 첫 번째 제한 자식 노드에 응답합니다.

  #### 선언

  목표 -C

  ```
  - (nonnull FIRDatabaseQuery *)queryLimitedToFirst:(NSUInteger)limit;
  ```

  #### 매개 변수

  | `*limit*` | 이벤트를 수신하는 자식 노드의 수에 대한 상한 |
  | --------- | -------------------------------------------- |
  |           |                                              |

  #### 반환 값

  FIRDatabaseQuery 인스턴스이며 최대 자식 노드 수로 제한됩니다.

- `-queryLimitedToLast:`

  

  

  queryLimitedToLast :이 위치에서 데이터의 제한된보기에 대한 참조를 생성하는 데 사용됩니다. queryLimitedToLast에 의해 반환되는 FIRDatabaseQuery 인스턴스 : 가장 마지막 제한 자식 노드에 응답합니다.

  #### 선언

  목표 -C

  ```
  - (nonnull FIRDatabaseQuery *)queryLimitedToLast:(NSUInteger)limit;
  ```

  #### 매개 변수

  | `*limit*` | 이벤트를 수신하는 자식 노드의 수에 대한 상한 |
  | --------- | -------------------------------------------- |
  |           |                                              |

  #### 반환 값

  FIRDatabaseQuery 인스턴스이며 최대 자식 노드 수로 제한됩니다.

- `-queryOrderedByChild:`

  

  

  queryOrderBy : 특정 하위 키 값으로 정렬 된 데이터 뷰에 대한 참조를 생성하는 데 사용됩니다. 이 메소드는 queryStartingAtValue :, queryEndingAtValue : 또는 queryEqualToValue :와 함께 사용하기위한 것입니다.

  #### 선언

  목표 -C

  ```
  - (nonnull FIRDatabaseQuery *)queryOrderedByChild:(nonnull NSString *)key;
  ```

  #### 매개 변수

  | `*key*` | 반환 된 FIRDatabaseQuery에 표시되는 데이터를 정렬하는 데 사용할 자식 키 |
  | ------- | ------------------------------------------------------------ |
  |         |                                                              |

  #### 반환 값

  지정된 자식 키의 값으로 정렬 된 FIRDatabaseQuery 인스턴스입니다.

- `-queryOrderedByKey`

  

  

  queryOrderedByKey : 하위 키순으로 정렬 된 데이터보기에 대한 참조를 생성하는 데 사용됩니다. 이 메소드는 queryStartingAtValue :, queryEndingAtValue : 또는 queryEqualToValue :와 함께 사용하기위한 것입니다.

  #### 선언

  목표 -C

  ```
  - (nonnull FIRDatabaseQuery *)queryOrderedByKey;
  ```

  #### 반환 값

  FIRDatabaseQuery 인스턴스이며, 하위 키순으로 정렬됩니다.

- `-queryOrderedByPriority`

  

  

  queryOrderedByPriority : 하위 우선 순위에 따라 정렬 된 데이터 뷰에 대한 참조를 생성하는 데 사용됩니다. 이 메소드는 queryStartingAtValue :, queryEndingAtValue : 또는 queryEqualToValue :와 함께 사용하기위한 것입니다.

  #### 선언

  목표 -C

  ```
  - (nonnull FIRDatabaseQuery *)queryOrderedByPriority;
  ```

  #### 반환 값

  자식 우선 순위에 따라 정렬 된 FIRDatabaseQuery 인스턴스입니다.

- `-queryStartingAtValue:`

  

  

  queryStartingAtValue :이 위치에서 데이터의 제한된보기에 대한 참조를 생성하는 데 사용됩니다. queryStartingAtValue :에 의해 반환 된 FIRDatabaseQuery 인스턴스는 노드의 이벤트에 startValue보다 크거나 같은 값으로 응답합니다.

  #### 선언

  목표 -C

  ```
  - (nonnull FIRDatabaseQuery *)queryStartingAtValue:(nullable id)startValue;
  ```

  #### 매개 변수

  | `*startValue*` | 반환 된 FIRDatabaseQuery에 표시되는 데이터의 값에 대한 하한 |
  | -------------- | ----------------------------------------------------------- |
  |                |                                                             |

  #### 반환 값

  startValue보다 크거나 같은 값을 갖는 데이터로 제한되는 FIRDatabaseQuery 인스턴스

- `-queryStartingAtValue:childKey:`

  

  

  queryStartingAtValue : childKey :이 위치에서 데이터의 제한된보기에 대한 참조를 생성하는 데 사용됩니다. queryStartingAtValue : childKey가 리턴 한 FIRDatabaseQuery 인스턴스는 startValue보다 큰 값 또는 startValue와 같고 키가 childKey보다 크거나 같은 노드의 이벤트에 응답합니다.

  #### 선언

  목표 -C

  ```
  - (nonnull FIRDatabaseQuery *)queryStartingAtValue:(nullable id)startValue
                                            childKey:
                                                (nullable NSString *)childKey;
  ```

  #### 매개 변수

  | `*startValue*` | 반환 된 FIRDatabaseQuery에 표시되는 데이터의 값에 대한 하한  |
  | -------------- | ------------------------------------------------------------ |
  | `*childKey*`   | startValue와 같은 값을 가지는 노드의 키에 대한 하한 (하한을 포함한다). |

  #### 반환 값

  startValue보다 크거나 같은 값을 갖는 데이터로 제한되는 FIRDatabaseQuery 인스턴스

- `-queryEndingAtValue:`

  

  

  queryEndingAtValue :이 위치에서 데이터의 제한된보기에 대한 참조를 생성하는 데 사용됩니다. queryEndingAtValue :에 의해 반환 된 FIRDatabaseQuery 인스턴스는 endValue보다 작거나 같은 값을 가진 노드의 이벤트에 응답합니다.

  #### 선언

  목표 -C

  ```
  - (nonnull FIRDatabaseQuery *)queryEndingAtValue:(nullable id)endValue;
  ```

  #### 매개 변수

  | `*endValue*` | 반환 된 FIRDatabaseQuery에 표시되는 데이터 값의 상한 (경계 포함)입니다. |
  | ------------ | ------------------------------------------------------------ |
  |              |                                                              |

  #### 반환 값

  endValue보다 작거나 같은 값을 가진 데이터로 제한되는 FIRDatabaseQuery 인스턴스

- `-queryEndingAtValue:childKey:`

  

  

  queryEndingAtValue : childKey :이 위치에서 데이터의 제한된보기에 대한 참조를 생성하는 데 사용됩니다. queryEndingAtValue : childKey에 의해 반환 된 FIRDatabaseQuery 인스턴스는 endValue보다 작은 값 또는 endValue와 같고 childKey와 같거나 작은 키를 가진 노드의 이벤트에 응답합니다.

  #### 선언

  목표 -C

  ```
  - (nonnull FIRDatabaseQuery *)queryEndingAtValue:(nullable id)endValue
                                          childKey:(nullable NSString *)childKey;
  ```

  #### 매개 변수

  | `*endValue*` | 반환 된 FIRDatabaseQuery에 표시되는 데이터 값의 상한 (경계 포함)입니다. |
  | ------------ | ------------------------------------------------------------ |
  | `*childKey*` | endValue와 동일한 값을 가지는 노드의 키에 대한 상한입니다 (상한 포함). |

  #### 반환 값

  endValue보다 작거나 같은 값을 가진 데이터로 제한되는 FIRDatabaseQuery 인스턴스

- `-queryEqualToValue:`

  

  

  queryEqualToValue :이 위치에서 데이터의 제한된보기에 대한 참조를 생성하는 데 사용됩니다. queryEqualToValue :에 의해 반환 된 FIRDatabaseQuery 인스턴스는 제공된 인수와 동일한 값을 가진 노드의 이벤트에 응답합니다.

  #### 선언

  목표 -C

  ```
  - (nonnull FIRDatabaseQuery *)queryEqualToValue:(nullable id)value;
  ```

  #### 매개 변수

  | `*value*` | 이 FIRDatabaseQuery에 의해 반환 된 데이터의 값 |
  | --------- | ---------------------------------------------- |
  |           |                                                |

  #### 반환 값

  제공된 값을 가진 데이터로 제한되는 FIRDatabaseQuery 인스턴스입니다.

- `-queryEqualToValue:childKey:`

  

  

  queryEqualToValue : childKey :이 위치에서 데이터의 제한된보기에 대한 참조를 생성하는 데 사용됩니다. queryEqualToValue : childKey에 의해 반환 된 FIRDatabaseQuery 인스턴스는 childKey와 동일한 키를 가진 제공된 인수와 동일한 값을 갖는 노드의 이벤트에 응답합니다. 자식 키가 고유하기 때문에 최대 하나의 노드가 일치합니다.

  #### 선언

  목표 -C

  ```
  - (nonnull FIRDatabaseQuery *)queryEqualToValue:(nullable id)value
                                         childKey:(nullable NSString *)childKey;
  ```

  #### 매개 변수

  | `*value*`    | 이 FIRDatabaseQuery에 의해 반환 된 데이터의 값 |
  | ------------ | ---------------------------------------------- |
  | `*childKey*` | 올바른 값을 가진 노드의 키                     |

  #### 반환 값

  제공된 값과 키가있는 데이터로 제한되는 FIRDatabaseQuery 인스턴스입니다.

[현재 상태 관리](https://firebase.google.com/docs/reference/ios/firebasedatabase/api/reference/Classes/FIRDatabaseReference?authuser=1#/Managing%20presence)

- `-onDisconnectSetValue:`

  

  

  브라우저가 닫히거나 새 페이지로 이동하거나 네트워크 문제로 인해 클라이언트 연결이 끊어졌을 때이 위치의 데이터가 지정된 값으로 설정되어 있는지 확인하십시오.

  onDisconnectSetValue : 사용자가 연결을 끊을 때 값을 변경하거나 지워야 다른 사용자에게 오프라인으로 표시되는 프레즌스 시스템 을 구현하는 데 특히 유용 합니다.

  #### 선언

  목표 -C

  ```
  - (void)onDisconnectSetValue:(nullable id)value;
  ```

  #### 매개 변수

  | `*value*` | 연결이 끊어진 후에 설정할 값입니다. |
  | --------- | ----------------------------------- |
  |           |                                     |

- `-onDisconnectSetValue:withCompletionBlock:`

  

  

  브라우저가 닫히거나 새 페이지로 이동하거나 네트워크 문제로 인해 클라이언트 연결이 끊어졌을 때이 위치의 데이터가 지정된 값으로 설정되어 있는지 확인하십시오.

  완료 블록은 작업이 Firebase 데이터베이스 서버에 성공적으로 대기열에 올랐을 때 트리거됩니다

  #### 선언

  목표 -C

  ```
  - (void)onDisconnectSetValue:(nullable id)value
           withCompletionBlock:
               (nonnull void (^)(NSError *_Nullable,
                                 FIRDatabaseReference *_Nonnull))block;
  ```

  #### 매개 변수

  | `*value*` | 연결이 끊어진 후에 설정할 값입니다.                          |
  | --------- | ------------------------------------------------------------ |
  | `*block*` | 작업이 Firebase 데이터베이스 서버에서 대기열에 들어갔을 때 실행 차단 |

- `-onDisconnectSetValue:andPriority:`

  

  

  브라우저를 닫거나 새 페이지로 이동하거나 네트워크 문제로 인해 클라이언트 연결이 끊어지면이 위치의 데이터가 지정된 값과 우선 순위로 설정되었는지 확인하십시오.

  #### 선언

  목표 -C

  ```
  - (void)onDisconnectSetValue:(nullable id)value
                   andPriority:(nonnull id)priority;
  ```

  #### 매개 변수

  | `*value*`    | 연결이 끊어진 후에 설정할 값입니다.        |
  | ------------ | ------------------------------------------ |
  | `*priority*` | 연결이 끊어진 후에 설정할 우선 순위입니다. |

- `-onDisconnectSetValue:andPriority:withCompletionBlock:`

  

  

  브라우저를 닫거나 새 페이지로 이동하거나 네트워크 문제로 인해 클라이언트 연결이 끊어지면이 위치의 데이터가 지정된 값과 우선 순위로 설정되었는지 확인하십시오.

  완료 블록은 작업이 Firebase 데이터베이스 서버에 성공적으로 대기열에 올랐을 때 트리거됩니다

  #### 선언

  목표 -C

  ```
  - (void)onDisconnectSetValue:(nullable id)value
                   andPriority:(nullable id)priority
           withCompletionBlock:
               (nonnull void (^)(NSError *_Nullable,
                                 FIRDatabaseReference *_Nonnull))block;
  ```

  #### 매개 변수

  | `*value*`    | 연결이 끊어진 후에 설정할 값입니다.                          |
  | ------------ | ------------------------------------------------------------ |
  | `*priority*` | 연결이 끊어진 후에 설정할 우선 순위입니다.                   |
  | `*block*`    | 작업이 Firebase 데이터베이스 서버에서 대기열에 들어갔을 때 실행 차단 |

- `-onDisconnectRemoveValue`

  

  

  클라이언트 연결이 끊어졌을 때이 위치의 데이터가 제거되었는지 확인하십시오 (앱 닫기, 새 페이지로 이동 또는 네트워크 문제로 인해).

  onDisconnectRemoveValue는 특히 현재 상태 시스템 을 구현하는 데 유용 합니다.

  #### 선언

  목표 -C

  ```
  - (void)onDisconnectRemoveValue;
  ```

- `-onDisconnectRemoveValueWithCompletionBlock:`

  

  

  클라이언트 연결이 끊어졌을 때이 위치의 데이터가 제거되었는지 확인하십시오 (앱 닫기, 새 페이지로 이동 또는 네트워크 문제로 인해).

  onDisconnectRemoveValueWithCompletionBlock : 특히 현재 상태 시스템 을 구현하는 데 유용 합니다.

  #### 선언

  목표 -C

  ```
  - (void)onDisconnectRemoveValueWithCompletionBlock:
      (nonnull void (^)(NSError *_Nullable, FIRDatabaseReference *_Nonnull))block;
  ```

  #### 매개 변수

  | `*block*` | 작업이 Firebase 데이터베이스 서버에서 대기열에 들어갔을 때 실행 차단 |
  | --------- | ------------------------------------------------------------ |
  |           |                                                              |

- `-onDisconnectUpdateChildValues:`

  

  

  브라우저가 닫히거나 새 페이지로 이동하거나 네트워크 문제로 인해 클라이언트 연결이 끊어졌을 때 데이터에 지정된 하위 값이 업데이트되었는지 확인하십시오.

  #### 선언

  목표 -C

  ```
  - (void)onDisconnectUpdateChildValues:(nonnull NSDictionary *)values;
  ```

  #### 매개 변수

  | `*values*` | 자식 노드 키 사전 및 연결을 설정 한 후 값을 잃어 버리는 값. |
  | ---------- | ----------------------------------------------------------- |
  |            |                                                             |

- `-onDisconnectUpdateChildValues:withCompletionBlock:`

  

  

  브라우저가 닫히거나 새 페이지로 이동하거나 네트워크 문제로 인해 클라이언트 연결이 끊어졌을 때 데이터에 지정된 하위 값이 업데이트되었는지 확인하십시오.

  #### 선언

  목표 -C

  ```
  - (void)onDisconnectUpdateChildValues:(nonnull NSDictionary *)values
                    withCompletionBlock:
                        (nonnull void (^)(NSError *_Nullable,
                                          FIRDatabaseReference *_Nonnull))block;
  ```

  #### 매개 변수

  | `*values*` | 자식 노드 키 사전 및 연결을 설정 한 후 값을 잃어 버리는 값.  |
  | ---------- | ------------------------------------------------------------ |
  | `*block*`  | 작업이 Firebase 데이터베이스 서버에 대기 상태가되면 호출 될 블록 |

- `-cancelDisconnectOperations`

  

  

  연결 해제시 실행되도록 설정된 모든 작업을 취소하십시오. 이전에 onDisconnectSetValue :, onDisconnectRemoveValue : 또는 onDisconnectUpdateChildValues :를 호출했고 연결이 끊어졌을 때 더 이상 값을 업데이트하지 않으려면 cancelDisconnectOperations를 호출하십시오.

  #### 선언

  목표 -C

  ```
  - (void)cancelDisconnectOperations;
  ```

- `-cancelDisconnectOperationsWithCompletionBlock:`

  

  

  연결 해제시 실행되도록 설정된 모든 작업을 취소하십시오. 이전에 onDisconnectSetValue :, onDisconnectRemoveValue : 또는 onDisconnectUpdateChildValues :를 호출했고 연결이 끊어졌을 때 더 이상 값을 업데이트하지 않으려면 cancelDisconnectOperations를 호출하십시오.

  #### 선언

  목표 -C

  ```
  - (void)cancelDisconnectOperationsWithCompletionBlock:
      (nullable void (^)(NSError *_Nullable,
                         FIRDatabaseReference *_Nonnull))block;
  ```

  #### 매개 변수

  | `*block*` | Firebase 데이터베이스 서버가 취소 요청을 확인하면 트리거 될 블록. |
  | --------- | ------------------------------------------------------------ |
  |           |                                                              |

[수동 연결 관리](https://firebase.google.com/docs/reference/ios/firebasedatabase/api/reference/Classes/FIRDatabaseReference?authuser=1#/Manual%20Connection%20Management)

- `+goOffline`

  

  

  Firebase 데이터베이스 클라이언트를 서버에서 수동으로 연결 해제하고 자동 재 연결을 비활성화하십시오.

  Firebase 데이터베이스 클라이언트는 Firebase 데이터베이스 서버에 대한 영구 연결을 자동으로 유지하며, 연결이 끊어지면 다시 연결됩니다. 그러나 지속적인 연결이 바람직하지 않은 경우에는 goOffline () 및 goOnline () 메서드를 사용하여 클라이언트 연결을 수동으로 제어 할 수 있습니다.

  오프라인 상태에서 Firebase 데이터베이스 클라이언트는 더 이상 서버로부터 데이터 업데이트를받지 않습니다. 그러나 로컬에서 수행되는 모든 데이터베이스 작업은 이벤트를 즉시 시작하여 응용 프로그램이 정상적으로 작동 할 수있게합니다. 또한 로컬에서 수행되는 각 작업은 Firebase 데이터베이스 서버에 재 연결될 때 자동으로 대기열에 넣어지고 재 시도됩니다.

  Firebase 데이터베이스 서버에 다시 연결하고 원격 이벤트 수신을 시작하려면 goOnline ()을 참조하십시오. 연결이 다시 설정되면 Firebase 데이터베이스 클라이언트는 적절한 데이터를 전송하고 클라이언트 가자동으로 캐치 하도록 적절한 이벤트 를 실행합니다.

  참고 :이 방법을 호출하면 모든 Firebase 데이터베이스 연결에 영향을 미칩니다.

  #### 선언

  목표 -C

  ```
  + (void)goOffline;
  ```

- `+goOnline`

  

  

  수동으로 Firebase 데이터베이스 서버에 대한 연결을 재설정하고 자동 재 연결을 활성화하십시오.

  Firebase 데이터베이스 클라이언트는 Firebase 데이터베이스 서버에 대한 영구 연결을 자동으로 유지하며, 연결이 끊어지면 다시 연결됩니다. 그러나 지속적인 연결이 바람직하지 않은 경우에는 goOffline () 및 goOnline () 메서드를 사용하여 클라이언트 연결을 수동으로 제어 할 수 있습니다.

  이 메소드는 활성 연결을 사용하지 않으려면 goOffline ()을 호출 한 후에 사용해야합니다. 다시 연결되면 Firebase 데이터베이스 클라이언트는 자동으로 적절한 데이터를 전송하고 클라이언트가 자동으로 캐치하도록 적절한 이벤트 를 실행합니다.

  Firebase 데이터베이스 서버와의 연결을 끊으려면 goOffline ()을 참조하십시오.

  참고 :이 방법을 호출하면 모든 Firebase 데이터베이스 연결에 영향을 미칩니다.

  #### 선언

  목표 -C

  ```
  + (void)goOnline;
  ```

[업무](https://firebase.google.com/docs/reference/ios/firebasedatabase/api/reference/Classes/FIRDatabaseReference?authuser=1#/Transactions)

- `-runTransactionBlock:`

  

  

  이 위치에서 데이터에 대한 낙관적 동시성 트랜잭션 업데이트를 수행합니다. 블록은이 위치에 현재 데이터가 들어있는 FIRMutableData 인스턴스로 호출됩니다. 블록은이 데이터를이 위치에 쓸 값으로 업데이트 한 다음 FIRTransactionResult의 인스턴스를 새 데이터로 반환해야합니다.

  작업이 서버에 도달하면이 클라이언트에 오래된 데이터가있는 것으로 판명되면 서버의 최신 데이터로 블록이 다시 실행됩니다.

  블록이 실행되면 [FIRTransactionResult abort]를 반환하여 트랜잭션을 중단 할 수 있습니다.

  #### 선언

  목표 -C

  ```
  - (void)runTransactionBlock:
      (nonnull FIRTransactionResult *_Nonnull (^)(FIRMutableData *_Nonnull))block;
  ```

  #### 매개 변수

  | `*block*` | 이 블록은이 위치에서 현재 데이터를 받고 FIRTransactionResult의 인스턴스를 반환해야합니다. |
  | --------- | ------------------------------------------------------------ |
  |           |                                                              |

- `-runTransactionBlock:andCompletionBlock:`

  

  

  이 위치에서 데이터에 대한 낙관적 동시성 트랜잭션 업데이트를 수행합니다. 블록은이 위치에 현재 데이터가 들어있는 FIRMutableData 인스턴스로 호출됩니다. 블록은이 데이터를이 위치에 쓸 값으로 업데이트 한 다음 FIRTransactionResult의 인스턴스를 새 데이터로 반환해야합니다.

  작업이 서버에 도달하면이 클라이언트에 오래된 데이터가있는 것으로 판명되면 서버의 최신 데이터로 블록이 다시 실행됩니다.

  블록이 실행되면 [FIRTransactionResult abort]를 반환하여 트랜잭션을 중단 할 수 있습니다.

  #### 선언

  목표 -C

  ```
  - (void)runTransactionBlock:(nonnull FIRTransactionResult *_Nonnull (^)(
                                  FIRMutableData *_Nonnull))block
           andCompletionBlock:
               (nonnull void (^)(NSError *_Nullable, BOOL,
                                 FIRDataSnapshot *_Nullable))completionBlock;
  ```

  #### 매개 변수

  | `*block*`           | 이 블록은이 위치에서 현재 데이터를 받고 FIRTransactionResult의 인스턴스를 반환해야합니다. |
  | ------------------- | ------------------------------------------------------------ |
  | `*completionBlock*` | 성공 또는 실패 여부에 관계없이 트랜잭션이 완료되면이 블록이 트리거됩니다. 오류가 있었는지 여부, 데이터가 커밋되었는지 여부 및이 위치의 데이터의 현재 값이 표시됩니다. |

- `-runTransactionBlock:andCompletionBlock:withLocalEvents:`

  

  

  이 위치에서 데이터에 대한 낙관적 동시성 트랜잭션 업데이트를 수행합니다. 블록은이 위치에 현재 데이터가 들어있는 FIRMutableData 인스턴스로 호출됩니다. 블록은이 데이터를이 위치에 쓸 값으로 업데이트 한 다음 FIRTransactionResult의 인스턴스를 새 데이터로 반환해야합니다.

  작업이 서버에 도달하면이 클라이언트에 오래된 데이터가있는 것으로 판명되면 서버의 최신 데이터로 블록이 다시 실행됩니다.

  블록이 실행되면 [FIRTransactionResult abort]를 반환하여 트랜잭션을 중단 할 수 있습니다.

  블록이 여러 번 실행될 수 있으므로이 클라이언트는 서버에 존재하지 않는 여러 즉각적인 상태를 볼 수 있습니다. 서버가 트랜잭션의 최종 상태를 확인할 때까지 즉시 상태를 억제 할 수 있습니다.

  #### 선언

  목표 -C

  ```
  - (void)runTransactionBlock:(nonnull FIRTransactionResult *_Nonnull (^)(
                                  FIRMutableData *_Nonnull))block
           andCompletionBlock:
               (nullable void (^)(NSError *_Nullable, BOOL,
                                  FIRDataSnapshot *_Nullable))completionBlock
              withLocalEvents:(BOOL)localEvents;
  ```

  #### 매개 변수

  | `*block*`           | 이 블록은이 위치에서 현재 데이터를 받고 FIRTransactionResult의 인스턴스를 반환해야합니다. |
  | ------------------- | ------------------------------------------------------------ |
  | `*completionBlock*` | 성공 또는 실패 여부에 관계없이 트랜잭션이 완료되면이 블록이 트리거됩니다. 오류가 있었는지 여부, 데이터가 커밋되었는지 여부 및이 위치의 데이터의 현재 값이 표시됩니다. |
  | `*localEvents*`     | 중간 상태에 대해 발생 된 이벤트를 억제하고 트랜잭션의 최종 상태를 기반으로하는 이벤트 만 얻으려면 NO로 설정하십시오. |

[문자열 표현 검색](https://firebase.google.com/docs/reference/ios/firebasedatabase/api/reference/Classes/FIRDatabaseReference?authuser=1#/Retrieving%20String%20Representation)

- `-description`

  

  

  이 Firebase 데이터베이스 위치의 절대 URL을 가져옵니다.

  #### 선언

  목표 -C

  ```
  - (nonnull NSString *)description;
  ```

  #### 반환 값

  참조 된 Firebase 데이터베이스 위치의 절대 URL.

[속성](https://firebase.google.com/docs/reference/ios/firebasedatabase/api/reference/Classes/FIRDatabaseReference?authuser=1#/Properties)

- `parent`

  

  

  부모 위치에 대한 FIRDatabaseReference를 가져옵니다. 이 인스턴스가 Firebase 데이터베이스의 루트를 참조하는 경우 부모가 없으므로 parent ()가 null을 반환합니다.

  #### 선언

  목표 -C

  ```
  @property (readonly, strong, nonatomic, nullable) FIRDatabaseReference *parent;
  ```

  #### 반환 값

  부모 위치에 대한 FIRDatabaseReference입니다.

- `root`

  

  

  루트 위치에 대한 FIRDatabaseReference를 가져옵니다.

  #### 선언

  목표 -C

  ```
  @property (readonly, strong, nonatomic) FIRDatabaseReference *_Nonnull root;
  ```

  #### 반환 값

  루트 위치에 대한 새로운 FIRDatabaseReference입니다.

- `key`

  

  

  Firebase 데이터베이스 위치의 마지막 토큰을 가져옵니다 (예 : https://SampleChat.firebaseIO-demo.com/users/fred의 'fred').

  #### 선언

  목표 -C

  ```
  @property (readonly, strong, nonatomic) NSString *_Nonnull key;
  ```

  #### 반환 값

  이 참조가 가리키는 위치의 키입니다.

- `URL`

  

  

  이 FIRDatabaseReference가 참조하는 Firebase 데이터베이스 위치의 URL을 가져옵니다.

  #### 선언

  목표 -C

  ```
  @property (readonly, strong, nonatomic) NSString *_Nonnull URL;
  ```

  #### 반환 값

  이 참조가 가리키는 위치의 URL입니다.

- `database`

  

  

  이 참조와 관련된 FIRDatabase 인스턴스를 가져옵니다.

  #### 선언

  목표 -C

  ```
  @property (readonly, strong, nonatomic) FIRDatabase *_Nonnull database;
  ```

  #### 반환 값

  이 참조에 대한 FIRDatabase 개체입니다.

