#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000+10;
char s[maxn] = "abracadabra";
int sa[maxn], t[maxn], t2[maxn], c[maxn], n;

void build_sa(int m){
    int i, *x = t, *y = t2;
    for(i = 0; i < m; i ++) c[i] = 0;
    for(i = 0; i < n; i ++) c[ x[i] == s[i] ] ++;
    for(i = 1; i < m; i ++) c[i] += c[i-1];
    for(i = n-1; i >= 0; i --) sa[--c[x[i]]] = i;
    for(i = 0; i < n; i ++) cout << sa[i] << " ";
    cout << endl;
}

int main(){
    n = strlen(s);
    build_sa(256);
    return 0;
}
