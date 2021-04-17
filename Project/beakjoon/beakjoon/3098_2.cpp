#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;
int M,N, A, B;
int map[51][51];
int temp[51][51];
int res; 
int total;
int flag;
int dayTotal, before;
vector <int> v;
int main() {
   scanf("%d%d", &N, &M);
   total = 0;
   for (int i = 0; i < M; i++) {
      scanf("%d%d", &A, &B);
      map[A][B] = 1;
      total++;
      map[B][A] = 1;
   }
   while (true) {
      before = total;
      for (int i = 1; i <= N; i++) {
         for (int j = 1; j <= N; j++) {
            if (map[i][j] > 0 && map[i][j] < before+1 && i!=j) {
               for (int z = 1; z <= N; z++) {
                  if (map[i][z] == 0 && map[j][z] > 0 && map[j][z] < before+1 && i!=z && j!=z) {
                     map[i][z] = map[z][i] = before + 1;
                     total = total + 1;
                  }
               }
            }
         }
      }
      dayTotal = total - before;
      v.push_back(dayTotal);
      if (total == ((N * N) - N) / 2) {
         break;
      }
   }

   printf("%d", v.size());
   printf("\n");
   for (int i = 0; i < v.size(); i++) {
      printf("%d", v[i]);
      printf("\n");
   }

   return 0;
}