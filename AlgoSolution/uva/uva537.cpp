#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 10000;
int main(){
    int t;
    char data[maxn];
    scanf("%d%*c", &t);
    for(int test = 1; test <= t; test ++){
        memset(data, 0, sizeof(data));
        gets(data);
        printf("Problem #%d\n", test);
        int p1, p2, p3;
        p1 = p2 = p3 = -1;
        for(int i = 0; i < strlen(data); i ++){
            if(data[i] == 'P' && data[i+1] == '=') p1 = i;
            if(data[i] == 'U' && data[i+1] == '=') p2 = i;
            if(data[i] == 'I' && data[i+1] == '=') p3 = i;
        }
        //cout << p1 << p2 << p3 << endl;
        char d1[maxn], d2[maxn];
        memset(d1, 0, sizeof(d1));
        memset(d2, 0, sizeof(d2));
        double x, y;
        x = y = 0;
        if(p1 == -1){
            int len = 0;
            char flag = 0;
            for(int i = p2+2; data[i] != 'V'; i ++){
                if(data[i] == 'm' || data[i] == 'k' || data[i] == 'M'){
                    flag = data[i];
                }
                else d1[len++] = data[i];
            }
            d1[len++] = '\0';
            x = atof(d1);
            if(flag == 'm') x *= 0.001;
            if(flag == 'k') x *= 1000;
            if(flag == 'M') x *= 1000000;
            flag = len = 0;
            // 主要要清零
            for(int i = p3+2; data[i] != 'A'; i ++){
                if(data[i] == 'm' || data[i] == 'k' || data[i] == 'M'){
                    flag = data[i];
                }
                else d2[len++] = data[i];
            }
            d2[len++] = '\0';
            y = atof(d2);
            if(flag == 'm') y *= 0.001;
            if(flag == 'k') y *= 1000;
            if(flag == 'M') y *= 1000000;
            printf("P=%.2lfW\n", x*y);
        }
        else if(p2 == -1){
            int len = 0;
            char flag = 0;
            for(int i = p1+2; data[i] != 'W'; i ++){
                if(data[i] == 'm' || data[i] == 'k' || data[i] == 'M'){
                    flag = data[i];
                }
                else d1[len++] = data[i];
            }
                d1[len++] = '\0';
            x = atof(d1);
            if(flag == 'm') x *= 0.001;
            if(flag == 'k') x *= 1000;
            if(flag == 'M') x *= 1000000;
            flag = len = 0;
            for(int i = p3+2; data[i] != 'A'; i ++){
                if(data[i] == 'm' || data[i] == 'k' || data[i] == 'M'){
                    flag = data[i];
                }
                else d2[len++] = data[i];
            }
            d2[len++] = '\0';
            y = atof(d2);
            if(flag == 'm') y *= 0.001;
            if(flag == 'k') y *= 1000;
            if(flag == 'M') y *= 1000000;
            printf("U=%.2lfV\n", x/y);
        }
        else if(p3 == -1){
            int len = 0;
            char flag = 0;
            for(int i = p1+2; data[i] != 'W'; i ++){
                if(data[i] == 'm' || data[i] == 'k' || data[i] == 'M'){
                    flag = data[i];
                }
                else d1[len++] = data[i];
            }
            d1[len++] = '\0';
            x = atof(d1);
            if(flag == 'm') x *= 0.001;
            if(flag == 'k') x *= 1000;
            if(flag == 'M') x *= 1000000;
            flag = len = 0;
            for(int i = p2+2; data[i] != 'V'; i ++){
                if(data[i] == 'm' || data[i] == 'k' || data[i] == 'M'){
                    flag = data[i];
                }
                else d2[len++] = data[i];
            }
            d2[len++] = '\0';
            y = atof(d2);
            if(flag == 'm') y *= 0.001;
            if(flag == 'k') y *= 1000;
            if(flag == 'M') y *= 1000000;
            printf("I=%.2lfA\n", x/y);
        }
        printf("\n");
    }
    return 0;
}
/*
conclusion:
13777800 	537 	Artificial Intelligence?
Accepted 	C++11 	0.012 	2014-06-22 06:00:59
wa: 8times  time: 2hours plus
1: 局部变量要清零，第二次使用同一变量要清除上一次的值
2：仔细读题目要求
3：atof函数可以将字符转换为浮点数
useage : 从字符一个为数字或者正负号开始，直到非数字或
‘\0’结束，中间可以有小数点或科学计数法
*/
