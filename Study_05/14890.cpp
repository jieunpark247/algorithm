#include <iostream> 

using namespace std;

int n, l; // l�� ������ ����
int map[101][101], temp[101];
int visited[101]; //���ΰ� ��ĥ��츦 ���� 
int cnt; //flag�� 1�̸� cnt ++����
int num; //temp�迭 ���� ���� �־��� ����
int flag; // flag�� 1�̸� ���ΰ��� 0�̸� �Ұ���
int a; //���밪 ���ϱ� abs �� �ȵ�

void find() {

	for (int i = 0; i < n - 1; i++) {  //n�� ���̸�ŭ ����

	//====
		if (temp[i] > temp[i + 1])    
			a = (temp[i] - temp[i + 1]);
		else
			a = (temp[i + 1] - temp[i]);
	//====���밪 ���ϱ�

		 if (a == 1) // i�� i ���ڸ��Ǽ��� ���� 1�� ��� 
		 {
			
			 if (temp[i] > temp[i + 1] ) // i +1�� ��������
			 {	
				
				num = temp[i + 1]; //�������� num�� �־��ش�
				for (int j = 0; j < l; j++) // l�� ���̸�ŭ ���θ� ���� �� �ִ°�?
				{ //�ᱹ i+1�� ���� L�� ���̸� ������ ��ŭ ������?
					
					
					if (visited[i + 1 + j] != 1) { //�湮 ���߳�? ==0�����ϸ� visited[-1]�ΰ�찡 �ȵǱ⶧���� !=1 ������
						
						if (num != temp[i + 1 + j]) // ���ΰ� ���� ����(L)��ŭ�� ũ�Ⱚ�� num�� ����������
						{
				
							flag = 0; // flag 0�������ְ�
							break; //for�� ��������

						}

						   flag = 1; //�ƴϸ�flag 1�� ������
					
						   visited[i +1 + j] = 1; //�湮ǥ���ϱ�
						
					}
					else //�湮 ������ 
					flag = 0; // 0ǥ��
				}
			//	cout << "flag-" << flag << '\n';
			
				if (flag == 0) //  flag�� 0�� �ϳ��� ������ for�� �������� cf) flag�� 1 0 or 0 1�ϰ�� �Ұ����ϱ� ���� ������ 1�� �־���Ѵ�.
					break;
				
			 }

			
			else if (temp[i] < temp[i + 1] )  //i�� �� ������?
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
				
						flag = 1; //���� num�� ������ 1
								
					}
					else 
						flag = 0; //visited 1�̸� 0�̴�.
				}

		//		cout << "flag/" << flag << '\n';
				if (flag == 0)
					break;
				
			}

		 }

		 else if (temp[i+1] != temp[i]) { //���� 1���̰� ���������� ?
			
			 flag = 0;
			 break;
		 }

		 else 

		flag = 1; //��� i�� ���� �� �� ��� ex>33333 �ϰ��?
		
	}
}


void solve() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			temp[j] = map[i][j]; // -> �������� 1�پ� �̾Ƴ� temp������ �迭�� �ִ´�.

		flag = 0; 

		for (int i = 0; i < n; i++) {
			visited[i] = 0;
		}
		//�ʱ�ȭ 

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