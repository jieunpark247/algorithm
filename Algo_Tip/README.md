## 1. if return 사용법

if(..)  
  {  
  ...
  return;  
  ...  
   }

-> return의미는 조건에 해당된다면 함수를 끝낸다라는 의미

## 2. 재귀

재귀를 쓸 때 안끝난 채로 재귀에 들어가기 때문에 조건에 부합하지 않아 함수가 끝난다면 다른 경우의 수를 수행하게끔 **백트래킹**을 하여 경우의 수가 끝날 때 까지 수행한다.

## 3. 순열과 조합 

```

	vector<int> ind;

	int k = 3;

	for (int i = 0; i < k; i++) {
		ind.push_back(1);
	}
	for (int i = 0; i < vzero.size() - k; i++) {
		ind.push_back(0);
	}
	sort(ind.begin(), ind.end()); //오름차순 정

	do { //조합 돌리기

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				temp[i][j] = map[i][j]; //임시 map만들기

		for (int i = 0; i < ind.size(); i++) {
			if (ind[i] == 1) {

				temp[vzero[i].first][vzero[i].second] = 1;

			}
		}	
	} 

	while (next_permutation(ind.begin(), ind.end())); 


```  
: 조합 만들기 

```
next_permutation;
```  
:  순열 모두 만들기

```
sort();
```  
:  오름차순 정렬

