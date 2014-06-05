// Accepted 556K 16MS
#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

void Init(char *R, char *x, int& len){
  int pos = 0; // С����λ��
  int l = strlen(R); // r����Ч����
  while(R[pos] != '.') pos ++;
  // printf("%d\n", pos);
  len = l-pos-1;
  int st = 0;
  while(st <= pos && R[st] == '0') st ++;
  // ȥ��ǰ����,ע���ַ�Ҫ���ַ��Ƚ�
  // printf("%d\n", temp);
  int len1 = 0; // ʵ��������λ��
  for(int i = st; i < pos; i ++)
    x[len1++] = R[i];
  for(int i = pos+1; i < strlen(R); i ++){
    x[len1++]  = R[i];
  }
  // ��R��Ч���ָ��Ƶ�x��
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
  int k = 0; //�͵�λ��
  int carry = 0; // ��λ��
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
  int carry = 0;// ��λ
  int k = 0; // �˷����λ��
  for(int i = len-1; i >= 0; i --){
    int x = (a[i]-'0')*num + carry;
    temp[k++] = x%10 + '0';
    carry = x/10;
  }
  if(carry > 0) temp[k++] = carry + '0';
  // ���Ӻ������
  temp[k] = '\0';
  Reverse(temp); // �ظ������ı�﷽ʽ
}

void bign_multi(char *a, char *b, char *ans){
    int len1 = strlen(a);
    int len2 = strlen(b);
    //printf("%s %s\n", a, b);
    char temp[100000];
    char addtemp[100000];
    memset(addtemp, 0, sizeof(addtemp));
    for(int i = len2-1; i >= 0; i --){
      // Ҳ��������λ��ʼ����
      bign_multi_int(a, b[i]-'0', temp);
     // printf("%s\n", temp);
      int pos = strlen(temp);
      for(int j = 0; j < len2-1-i; j ++)
        temp[pos++] = '0';
      temp[pos] = '\0';
      // �ƶ�iλ
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
      // �ǵ�Ҫ���ԭ����ans
      bign_multi(x, temp, ans);
    //   printf("~%s\n", ans);
      strcpy(temp, ans);
      // ���֮���и�ֵ
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
    // ȥ���������
    if(pos < l) printf(".");
  }
  else {
    printf(".");
    while(pos < 0) { printf("0"); pos ++; }
  }
  // �����Ǵ���С������ǰ�ģ�����ȥ���������
  for(int i = pos; i < l; i ++)
      printf("%c", ans[i]);
    printf("\n");
}

void power(char* R, int n, char *ans) {
  char x[20];
  int len = 0; // С����λ��
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
