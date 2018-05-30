#include <iostream> 

using namespace std;

int n, l; // l은 경사로의 길이
int map[101][101], temp[101];
int visited[101]; //경사로가 겹칠경우를 위해 
int cnt; //flag가 1이면 cnt ++해줌
int num; //temp배열 작은 값을 넣어줄 변수
int flag; // flag가 1이면 경사로가능 0이면 불가능
int a; //절대값 구하기 abs 로 안됨

void find() {

	for (int i = 0; i < n - 1; i++) {  //n의 길이만큼 돌림

	//====
		if (temp[i] > temp[i + 1])    
			a = (temp[i] - temp[i + 1]);
		else
			a = (temp[i + 1] - temp[i]);
	//====절대값 구하기

		 if (a == 1) // i와 i 옆자리의수의 차가 1일 경우 
		 {
			
			 if (temp[i] > temp[i + 1] ) // i +1이 더작으면
			 {	
				
				num = temp[i + 1]; //작은값을 num에 넣어준다
				for (int j = 0; j < l; j++) // l의 길이만큼 경사로를 놓을 수 있는가?
				{ //결국 i+1의 값이 L의 길이를 지날때 만큼 같은가?
					
					
					if (visited[i + 1 + j] != 1) { //방문 안했나? ==0으로하면 visited[-1]인경우가 안되기때문에 !=1 로해줌
						
						if (num != temp[i + 1 + j]) // 경사로가 놓일 길이(L)만큼의 크기값이 num과 같지않으면
						{
				
							flag = 0; // flag 0으로해주고
							break; //for문 빠져나감

						}

						   flag = 1; //아니면flag 1로 만들어라
					
						   visited[i +1 + j] = 1; //방문표시하기
						
					}
					else //방문 했으면 
					flag = 0; // 0표시
				}
			//	cout << "flag-" << flag << '\n';
			
				if (flag == 0) //  flag가 0이 하나라도 나오면 for문 빠져나감 cf) flag가 1 0 or 0 1일경우 불가능하기 때문 무조건 1만 있어야한다.
					break;
				
			 }

			
			else if (temp[i] < temp[i + 1] )  //i가 더 작으면?
			{
				num = temp[i];
			
				for (int j = 0; j < l; j++)
				{

					if (visited[i - j] !=1) {
					;
						if (num != temp[i - j])
						{
						
							flag = 0;
							break;

						}
				
						flag = 1; //값이 num과 같으면 1
								
					}
					else 
						flag = 0; //visited 1이면 0이다.
				}

		//		cout << "flag/" << flag << '\n';
				if (flag == 0)
					break;
				
			}

		 }

		 else if (temp[i+1] != temp[i]) { //값이 1차이가 나지않으면 ?
			
			 flag = 0;
			 break;
		 }

		 else 

		flag = 1; //모든 i가 같은 수 일 경우 ex>33333 일경우?
		
	}
}


void solve() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			temp[j] = map[i][j]; // -> 방향으로 1줄씩 뽑아내 temp일차원 배열에 넣는다.

		flag = 0; 

		for (int i = 0; i < n; i++) {
			visited[i] = 0;
		}
		//초기화 

		find();

		if (flag == 1) {
			cnt++;
		}



	}


	for (int j = 0; j < n; j++) 
	{
		for (int i = 0; i < n; i++) 
			temp[i] = map[i][j];
		
		flag = 0;
		for (int i = 0; i < n; i++) {
			visited[i] = 0;
		}

		find();

		 if (flag == 1) {
			 cnt++;
		 }
	}


}



int main() {
	cin >> n >> l;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
		cin >> map[i][j];
		
//	cnt = 0;
	solve();
	cout << cnt << endl;

	
}