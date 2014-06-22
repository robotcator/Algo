#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100+10;

struct point{
    int x, y;
}p[maxn];


int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        if(n == 0) break;
        int x, y;
        // ×ø±ê·¶Î§Îª[-500, 500] µ°¸â°ë¾¶[-100£¬ 100]
        int num = 0;
        for(int i = 0; i < 2*n; i ++){
            scanf("%d%d", &x, &y);
            if(x >= -100 && x <= 100 && y >= -100 && y <= 100){
                    p[num].x = x, p[num].y = y;
                    num ++;
            }
        }
        int num1 = 0, num2 = 0;
        int flag = 0;
        for(int i = -500; i <= 500; i ++){
         for(int j = -500; j <= 500; j ++){
            num1 = num2 = 0;
            for(int k = 0; k < num; k ++){
                if(i*p[k].x + j*p[k].y > 0) num1 ++;
                else if(i*p[k].x + j*p[k].y < 0) num2 ++;
            }
            if(num2 == num1 && num1 + num2 == num) {
                printf("%d %d\n", i, j);
                flag = 1;
            }
            if(flag == 1) break;
         }
         if(flag == 1) break;
        }
    }
    return 0;
}
