#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

bool is_pali(char *x){
    int len = strlen(x);
    for(int i = 0; i <= len/2; i ++){
        if(x[i] != x[len-1-i]) return false;
    }
    return true;
}

bool check(int i){
        char x[15];
        int y = i;
        int m = 0;
        while(y){
            x[m ++] = y%10;
            y /= 10;
        }
        x[m++] = '\0';
        if(is_pali(x)) return true;
        else return false;
}

int main(){
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF){
        int cnt = 0;
        for(int i = a; i <= b; i ++){
            if(check(i) == 1) {
                cnt ++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}

/*
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    unsigned int a, b;
};

int dfs(unsigned int a,unsigned int b){
    if(a == 0 || b == 0) return true;
    if(a < b){
        unsigned int temp = a;
        a = b;
        b = temp;
    }
    if(dfs(a%b, b)){
        if(a/b == 1) return false;
        else return true;
    }
    else return false;
}

int main(){
    unsigned int a, b;
    while(scanf("%ud%ud", &a, &b) != EOF){
        if(dfs(a, b)) printf("%d\n", 1);
        else printf("%d\n", 2);
    }
    return 0;
}
*/
