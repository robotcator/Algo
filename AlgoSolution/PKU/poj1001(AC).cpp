// Accepted 556K 16MS
#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

void Init(char *R, char *x, int& len){
  int pos = 0; // 小数点位置
  int l = strlen(R); // r的有效长度
  while(R[pos] != '.') pos ++;
  // printf("%d\n", pos);
  len = l-pos-1;
  int st = 0;
  while(st <= pos && R[st] == '0') st ++;
  // 去除前导零,注意字符要跟字符比较
  // printf("%d\n", temp);
  int len1 = 0; // 实际整数的位数
  for(int i = st; i < pos; i ++)
    x[len1++] = R[i];
  for(int i = pos+1; i < strlen(R); i ++){
    x[len1++]  = R[i];
  }
  // 将R有效数字复制到x中
  x[len1] = '\0';
}

void Reverse(char *a){
  int len = strlen(a);
  for(int i = 0; i < len/2; i ++){
    char temp = a[i];
    a[i] = a[len-1-i];
    a[len-1-i] = temp;
  }
}

void bign_add(char *a, char *b, char *c){
  int len1 = strlen(a)-1;
  int len2 = strlen(b)-1;
  // printf("%d %d\n", len1, len2);
  int k = 0; //和的位数
  int carry = 0; // 进位端
  while(len1 >= 0 || len2 >= 0) {
    int x = len1 >= 0 ? a[len1]-'0' : 0;
    int y = len2 >= 0 ? b[len2]-'0' : 0;
    int z = x+y+carry;
    c[k++] = z%10 + '0';
    carry = z/10;
    len1 --; len2 --;
  }
  if(carry > 0) c[k++] = carry + '0';
  c[k] = '\0';
  Reverse(c);
}

void bign_multi_int(char *a, int num, char *temp){
  int len = strlen(a);
  int carry = 0;// 进位
  int k = 0; // 乘法后的位数
  for(int i = len-1; i >= 0; i --){
    int x = (a[i]-'0')*num + carry;
    temp[k++] = x%10 + '0';
    carry = x/10;
  }
  if(carry > 0) temp[k++] = carry + '0';
  // 增加后面的零
  temp[k] = '\0';
  Reverse(temp); // 回复正常的表达方式
}

void bign_multi(char *a, char *b, char *ans){
    int len1 = strlen(a);
    int len2 = strlen(b);
    //printf("%s %s\n", a, b);
    char temp[100000];
    char addtemp[100000];
    memset(addtemp, 0, sizeof(addtemp));
    for(int i = len2-1; i >= 0; i --){
      // 也必须从最低位开始计算
      bign_multi_int(a, b[i]-'0', temp);
     // printf("%s\n", temp);
      int pos = strlen(temp);
      for(int j = 0; j < len2-1-i; j ++)
        temp[pos++] = '0';
      temp[pos] = '\0';
      // 移动i位
      // printf("%s\n", temp);
      strcpy(addtemp, ans);
      // printf("%s %s\n", addtemp, temp);
      bign_add(addtemp, temp, ans);
      //printf("%s\n", ans);
    }
}

void bign_power(char *x, int n, char *ans){
  if(n >= 2){
    char temp[100000];
    strcpy(temp, x);
    for(int i = 2; i <= n; i ++){
     //  printf("x %s\ny %s\n", x, temp);
      memset(ans, 0, sizeof(ans));
      // 记得要清楚原来的ans
      bign_multi(x, temp, ans);
    //   printf("~%s\n", ans);
      strcpy(temp, ans);
      // 相乘之后还有赋值
      //printf("%s\n", ans);
    }
  }
  else if(n == 1){
    strcpy(ans, x);
  }
}

void print_ans(char *ans, int len) {
  int l = strlen(ans);
  int pos = l-len;
  // printf("ans~%s\n", ans);

  // printf("%d %d %d\n", pos, l, len);
  if(pos > 0){
    for(int i = 0; i < pos; i ++)
      printf("%c", ans[i]);
    for(int i = strlen(ans)-1; i >= pos && ans[i] == '0'; i --) l --;
    // 去除后面的零
    if(pos < l) printf(".");
  }
  else {
    printf(".");
    while(pos < 0) { printf("0"); pos ++; }
  }
  // 上面是处理小数点以前的，下面去除后面的零
  for(int i = pos; i < l; i ++)
      printf("%c", ans[i]);
    printf("\n");
}

void power(char* R, int n, char *ans) {
  char x[20];
  int len = 0; // 小数的位数
  Init(R, x, len);
  //printf("%d %s\n", len, x);
  bign_power(x, n, ans);
  len = len*n;
  //printf("%d\n", len);
  print_ans(ans, len);
}

int main()
{
  char R[2000];
  int n;
  while(scanf("%s %d", R, &n) != EOF){
    char ans[100000];
    power(R, n, ans);
   // printf("%s\n", ans);
  }
  return 0;
}
