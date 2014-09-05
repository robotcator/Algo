#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
/*
struct node{
    int x;
    int dir;
};
node p[10];
void init(int n){
    for(int i = 0; i < n; i ++){
        p[i].x = i;
        p[i].dir = 1;
    }
}
// dir = 1 向左， = -1向右
int Find(node *p, int n){
    int maxn = -1;
    for(int i = 0; i < n; i ++){
      //  printf("%d %d\n", p[i].x, p[i].dir);

    }
    printf("\n");
    for(int i = 0; i < n; i ++){
        if(p[i].dir == 1) {
            if(i-1 >= 0 && p[i].x > p[i-1].x && p[i].x > p[maxn].x) {
                maxn = i;
            }
        }
        else {
            if(i+1 < n && p[i].x > p[i+1].x && p[i].x > p[maxn].x) {
                maxn = i;
            }
        }
    }
    //cout << "m" << maxn+1 << endl;
    return maxn;
}

void permutation(node *p, int n){
    int maxn;
    while((maxn = Find(p, n)) != -1){
        int temp = p[maxn].x;
        if(p[maxn].dir == 1){
            swap(p[maxn], p[maxn-1]);
            //node temp = p[maxn];
        }
        else swap(p[maxn], p[maxn+1]);
        // 这里交换将maxn的值改变了
        for(int i = 0; i < n; i ++){
            if(p[i].x > temp) {
                p[i].dir = -p[i].dir;
            }
        }
        for(int i = 0; i < n; i ++){
            printf("%c ", p[i].x+'a');
        }
        printf("\n");
    }
}
_*/

char space[][15] = {"", "  ", "    ", "      ",
     "        ", "          ", "            ", "             "};

char buf[10];
void permutation2(int cur, int n, string s){
    if(cur == n){
        printf("%s", space[cur]);
        printf("writeln(");
        for(int i = s.size()-1; i >= 0; i --){
            printf("%c", s[i]);
            if(i != 0) printf(",");
        }
        printf(")\n");
        return ;
    }
    else {
        printf("%s", space[cur]);
        for(int i = 0; i <= s.size(); i ++){
            string temp = s;
            if(s.size() != i) printf("if %c < %c then", s[i], buf[cur]);
            if(s.size() != 0) printf("\n");
            temp.insert(i, 1, buf[cur]);
            permutation2(cur+1, n, temp);
            if(s.size() != i) printf("%selse ", space[cur]);
        }
    }
}


int main(){
    int n, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("program sort(input,output);\nvar\n");
        for(int i = 0; i < n; i ++){
            printf("%c", i+'a');
            if(i != n-1) printf(",");
        }
        printf(" : integer;\nbegin\n");
        printf("  readln(");
        for(int i = 0; i < n; i ++){
            printf("%c", i+'a');
            if(i != n-1) printf(",");
        }
        printf(");\n");
        for(int i = 0; i <= 8; i ++)
            buf[i] = i+'a';
        string s = "";
        permutation2(0, n, s);
        printf("end.\n");
        if(t != 0) printf("\n");
    }
    return 0;
}
/*
conclusion:
13790340 	110 	Meta-Loopless Sorts
Accepted 	C++11 	0.066 	2014-06-25 03:34:53
1: 排列生成算法，n插入n-1的排列中去
2：用字符串模拟较好，或者用链表list
*/
