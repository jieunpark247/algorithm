#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
int N, K, map[15][15][15],color[15][15];
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };
int chess[15][4];
int flag = 0;

void solve(int x, int y, int dir,int num) {
    int blueflag = 0;

    //�� ���� ���� �� >> ���� �ٲ��־�� �Ѵ�. 
    if (x + dx[dir] <= 0 || y + dy[dir] <= 0 || x + dx[dir] > N || y + dy[dir] > N) {
        if (dir == 1 || dir == 3)  dir = dir + 1;
        else if (dir == 2 || dir == 4)  dir = dir - 1;
        chess[num][2] = dir;
        blueflag = 1;
    }
    
    int nextColor = color[x + dx[dir]][y + dy[dir]];
    //���� ���� ��� ���� 

    if (nextColor == 0) { //W
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        //�� ���� �ִ� ü���� �Բ� ������ (map[x][y][���� ������ ü�� ��ġ] ~~[�� ����'��(���� ���� �ִ�) ü����ġ ])
        int mapsize = map[x][y][0];
        int mapstart = chess[num][3];
        for (int i = mapstart; i <= mapsize; i++) {
            ++map[nx][ny][0]; // �̵� 
            --map[x][y][0]; //���� �ִ� �ڸ� ���� ����
            chess[map[x][y][i]][3] = map[nx][ny][0];    //������ �ڸ��� ü���� �ִٸ� �� ���� �ö� 
            chess[map[x][y][i]][0] = nx; chess[map[x][y][i]][1] = ny; //x,y�� ���� 
            map[nx][ny][map[nx][ny][0]] = map[x][y][i]; //�̵��� ü�� �����ִ��� ���� �ø���
            map[x][y][i] = 0; // �����ִ� ü�� �ʱ�ȭ

            if (map[nx][ny][0] >= 4) flag = 1;
        }

    }
    else if (nextColor == 1) { //R
        int nx = x + dx[dir];
        int ny = y + dy[dir];


        //�� ���� �ִ� ü���� �Բ� ������ (map[x][y][���� ������ ü�� ��ġ] ~~[�� ������(���� ���� �ִ�) ü����ġ ])
        int mapsize = map[x][y][0];
        int mapstart = chess[num][3];
        for (int i = mapsize; i >= mapstart; i--) {
            ++map[nx][ny][0]; // �̵� 
            --map[x][y][0]; //���� �ִ� �ڸ� ���� ����
            chess[map[x][y][i]][3] = map[nx][ny][0];    //������ �ڸ��� ü���� �ִٸ� �� ���� �ö󰡴� ��°  
            chess[map[x][y][i]][0] = nx; chess[map[x][y][i]][1] = ny; //x,y�� ���� 
            map[nx][ny][map[nx][ny][0]] = map[x][y][i]; //�̵��� ü�� �����ִ��� ���� �ø���
            map[x][y][i] = 0; // �����ִ� ü�� �ʱ�ȭ

            if (map[nx][ny][0] >= 4) flag = 1;
        }


    }
    else if (nextColor == 2 && blueflag == 0) { //B
        if (dir == 1 || dir == 3)  dir = dir + 1;
        else if (dir == 2 || dir == 4)  dir = dir - 1;
      
        chess[num][2] = dir; // blue > ���� �ٲ� 
       
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        //���� �ٲ㼭�� �Ķ����̸� >> ����ٲ�ä�� ������ ���� ���� 
        if (color[nx][ny] == 0 && nx > 0 && ny > 0 && nx <= N && ny <= N) {
            //�� ���� �ִ� ü���� �Բ� ������ (map[x][y][���� ������ ü�� ��ġ] ~~[�� ������(���� ���� �ִ�) ü����ġ ])
            int mapsize = map[x][y][0];
            int mapstart = chess[num][3];
            for (int i = mapstart; i <= mapsize; i++) {
                ++map[nx][ny][0]; // �̵� 
                --map[x][y][0]; //���� �ִ� �ڸ� ���� ����
                chess[map[x][y][i]][3] = map[nx][ny][0];    //������ �ڸ��� ü���� �ִٸ� �� ���� �ö� 
                chess[map[x][y][i]][0] = nx; chess[map[x][y][i]][1] = ny; //x,y�� ���� 
                map[nx][ny][map[nx][ny][0]] = map[x][y][i]; //�̵��� ü�� �����ִ��� ���� �ø���
                map[x][y][i] = 0; // �����ִ� ü�� �ʱ�ȭ

                if (map[nx][ny][0] >= 4) flag = 1;
            }
        }
        else if (color[nx][ny] == 1 && nx > 0 && ny > 0 && nx <= N && ny <= N) {
            //�� ���� �ִ� ü���� �Բ� ������ (map[x][y][���� ������ ü�� ��ġ] ~~[�� ������(���� ���� �ִ�) ü����ġ ])
            int mapsize = map[x][y][0];
            int mapstart = chess[num][3];
            for (int i = mapsize; i >= mapstart; i--) {
                ++map[nx][ny][0]; // �̵� 
                --map[x][y][0]; //���� �ִ� �ڸ� ���� ����
                chess[map[x][y][i]][3] = map[nx][ny][0];    //������ �ڸ��� ü���� �ִٸ� �� ���� �ö󰡴� ��°  
                chess[map[x][y][i]][0] = nx; chess[map[x][y][i]][1] = ny; //x,y�� ���� 
                map[nx][ny][map[nx][ny][0]] = map[x][y][i]; //�̵��� ü�� �����ִ��� ���� �ø���
                map[x][y][i] = 0; // �����ִ� ü�� �ʱ�ȭ

                if (map[nx][ny][0] >= 4) flag = 1;
            }

        }


    }
}
int main() {
	scanf("%d%d", &N, &K);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &color[i][j]);
		}
	}

	for (int i = 1; i <= K; i++) {
		scanf("%d%d%d", &chess[i][0], &chess[i][1], &chess[i][2]);
		map[chess[i][0]][chess[i][1]][1] = i;
		chess[i][3] = 1; // ���° ��ġ�ϴ���  
		map[chess[i][0]][chess[i][1]][0] = 1; //���� ĭ�� ���� �� �� �̻� �ִ� ���� �Է����� �־����� �ʴ´�.
	}


    int res = 1;

    while (1) {

  
        for (int i = 1; i <= K; i++) {
            solve(chess[i][0], chess[i][1], chess[i][2], i);
            if (flag == 1) {
                break;
            }
        }
        
        if (flag == 1) {
            printf("%d", res);
            break;
        }else if (res > 1000) {
            printf("-1");
            break;
        }
        res++;
    }

}
