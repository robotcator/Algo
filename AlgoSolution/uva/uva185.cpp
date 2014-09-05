/*
    ID: problem6
    PROG : Roman Numerals
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<char, int> ec;
char temp[50];
char add1[15], add2[15], sum[15];
int a, b, c;
int vis[200];
int rec[200];
int n;
int cnt;
//查看时存在多种可能情况成立

void init(){
    ec['I'] = 1;
    ec['X'] = 10;
    ec['C'] = 100;
    ec['M'] = 1000;
    ec['V'] = 5;
    ec['L'] = 50;
    ec['D'] = 500;
}

void seperate(){
    int i, j, k;
    i = j = k = 0;
    for(i = 0; temp[i] != '+'; i ++)
        add1[k++] = temp[i];
    add1[k++] = '\0';
    for(j = i+1, k = 0; temp[j] != '='; j ++)
        add2[k++] = temp[j];
    add2[k++] = '\0';
    strcpy(sum, temp+j+1);
}

int interpret(char *ch){
    int len = strlen(ch);
    int sum = ec[ch[0]];
    int i = 1;
    while(i < len){
        if(ec[ch[i]] > ec[ch[i-1]]){
            sum = sum - 2*ec[ch[i-1]] + ec[ch[i]];
        }else{
            sum += ec[ch[i]];
        }
        i ++;
    }
    return sum;
    //printf("%d\n", sum);
}

bool check(int *rec, int n){
    int a, b, c;
    a = b = c = 0;
    if(rec[0] == 0) return 0;
    // 前缀为0的情况
    int i, j;
    i = j  = 0;
    for(i = 0; rec[i] != -1; i ++){
        a = a*10 + rec[i];
    }
    for(j = i+1; rec[j] != -1; j ++){
        b = b*10 + rec[j];
    }
    for(i = j+1; rec[i] != -1; i ++){
        c = c*10 + rec[i];
    }
    if(a + b == c){
      //  printf("%d %d %d\n", a, b, c);
        return 1;
    }
    else return 0;
}

void dfs(int cur, int *rec, int n){
    if(cnt >= 2) return ;
    // 情况多种无需再次搜索
    if(cur == n){
        if(check(rec, n)) cnt ++;
    }else if(temp[cur] == '+' || temp[cur] == '='){
        dfs(cur+1, rec, n);
    }else{
        if(vis[temp[cur]] == -1){
            for(int i = 0; i < 10; i ++){
                vis[temp[cur]] = i;
                rec[cur] = i;
                dfs(cur+1, rec, n);
                vis[temp[cur]] = -1;
            }
        }else{
            rec[cur] = vis[temp[cur]];
            dfs(cur+1, rec, n);
        }
    }
}

int main(){
    init();
    while(scanf("%s", temp) != EOF){
        if(strcmp(temp, "#") == 0) break;
        seperate();
        //printf("%s %s %s\n", add1, add2, sum);
        a = interpret(add1);
        b = interpret(add2);
        c = interpret(sum);
        if(a + b == c) printf("Correct ");
        else printf("Incorrect ");
        n = strlen(temp);
        cnt = 0;
        memset(vis, -1, sizeof(vis));
        memset(rec, -1, sizeof(rec));
        dfs(0, rec, n);
        if(cnt == 0) printf("impossible\n");
        else if(cnt == 1) printf("valid\n");
        else printf("ambiguous\n");
    }
    return 0;
}

/*
conclusion:
13915632 	185 	Roman Numerals 	Accepted
C++11 	0.756 	2014-07-21 02:33:46
*/
