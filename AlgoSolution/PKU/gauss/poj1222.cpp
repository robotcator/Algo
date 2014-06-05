#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int matrix[10][10];

int main(){
  int n;
  scanf("%d", &n);
  for(int test = 1; test <= n; test ++){
      memset(matrix, 0, sizeof(matrix));
      for(int i = 0; i < 5; i ++){
        for(int j = 0; j < 6; j ++){
          scanf("%d", &matrix[i][j]);
        }
      }
      for(int i = 0; i < 5; i ++){
        for(int j = 0; j < 6; j ++){
          if(matrix[i][j] == 0)
        }
      }
  }
  return 0;
}
