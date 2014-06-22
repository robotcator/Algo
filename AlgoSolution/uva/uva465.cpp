#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>

using namespace std;

int main(){
    char add1[100], add2[100], op[10];
    while(scanf("%s %s %s", add1, op, add2) != EOF){
     int a, b;
     a = b = 0;
     printf("%s %s %s\n", add1, op, add2);
     if(add1[0] == '-') printf("%c\n", op[-1]);
     // 貌似没有负数
     for(int i = 0; i < strlen(add1); i ++){
        a = a*10 + (add1[i]-'0');
     }
     for(int i = 0; i < strlen(add2); i ++){
        b = b*10 + (add2[i]-'0');
     }
     //cout << (long long)a*b << endl;
     int flag1, flag2;
     flag1 = flag2 = 1;
     if(a > INT_MAX || a < 0) {
            printf("first number too big\n");
            flag1 = 0;
     }
     if(b > INT_MAX || b < 0) {
            printf("second number too big\n");
            flag2 = 0;
     }
     if(strcmp(op, "+") && ( a+b < 0 ||  flag1 == 0 || flag2 == 0))
        printf("result too big\n");
     if(strcmp(op, "*") && ( a*b < 0 ||  flag1 == 0 || flag2 == 0))
        printf("result too big\n");
    }
    return 0;
}
