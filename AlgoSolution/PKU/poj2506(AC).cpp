// 以后可以写fibonacci高精度
// Wrong Answer  n times
// Accepted 248K 0MS    f[0] = 1 我的天啊调试这么久
#include <iostream>
#include <string.h>
#include <stdio.h>
// f(n) = f(n-1) + 2*f(n-2)

using namespace std;

char f[255][300];

void Reverse(char *data)
{
  int len = strlen(data);
  for(int i = 0; i < len/2; i ++){
    char temp = data[i];
    data[i] = data[len-i-1];
    data[len-i-1] = temp;
  }
  //printf("~%s\n", data);
}

void multi(char *data, int n, char *x)
{
  int len = strlen(data);
  int temp = 0;// 进位
  int k = 0; // 乘积的位数
  for(int i = len-1; i >= 0; i --){
    int y = (data[i] - '0')*n + temp;
    x[k++] = y%10 + '0';
    temp = y/10;
  }
  if(temp > 0) x[k++] = temp + '0';
  x[k] = '\0';
  Reverse(x);
}

void add(char *add1, char *add2, char *sum)
{
  int len1 = strlen(add1)-1;
  int len2 = strlen(add2)-1;
  int k = 0; // 和的位数
  int temp = 0; // 进位
  while(len1 >= 0 || len2 >= 0){
    int x = len1 >= 0 ? add1[len1]-'0' : 0;
    int y = len2 >= 0 ? add2[len2]-'0' : 0;
    int z = x + y + temp;
    sum[k++] = z%10 + '0';
    temp = z/10;
    len1 --;
    len2 --;
  }
  if(temp > 0) sum[k++] = temp + '0';
  sum[k] = '\0';
  Reverse(sum);
 // printf("%s\n", sum);
}

void fibonacci()
{
  f[0][0] = '1';
  f[0][1] = '\0';
  f[1][0] = '1';
  f[1][1] = '\0';
  f[2][0] = '3';
  f[2][1] = '\0';
  char x[1000];
  for(int i = 3; i <= 250; i ++){
    multi(f[i-2], 2, x);
    add(f[i-1], x, f[i]);
  }
}

void print(int n)
{
  for(int i = 0; i < strlen(f[n]); i ++){
    printf("%d", f[n][i]-'0');
  }
  printf("\n");

}

int main()
{
  int n;
  fibonacci();
  for(int i = 0; i <= 250; i ++)
    printf("%s\n", f[i]);
  return 0;
  while(scanf("%d", &n) != EOF){
      print(n);
  }
  return 0;
}
