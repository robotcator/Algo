/*
    ID: problem6
    PROG : Long Long Message
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100000+10;
char s[2*maxn];
int data[2*maxn];
int sa[2*maxn], t[2*maxn], t2[2*maxn], cnt[2*maxn];
int len;
int rank[2*maxn], height[2*maxn];

void build_sa(int m){
    int *x = t, *y = t2;
    memset(cnt, 0, sizeof(cnt));
    len ++;
    for(int i = 0; i < len; i ++)
        cnt[x[i] = data[i]] ++;
    for(int i = 1; i < m; i ++){
        cnt[i] += cnt[i-1];
    }
    for(int i = len-1; i >= 0; i --){
        sa[--cnt[x[i]]] = i;
    }
    for(int k = 1; k <= len; k <<= 1){
        int p = 0;
        for(int i = len-k; i < len; i ++) y[p++] = i;
        for(int i = 0; i < len; i ++) if(sa[i] >= k) y[p++] = sa[i]-k;
        //memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < m; i ++) cnt[i] = 0;
        for(int i = 0; i < len; i ++) cnt[x[y[i]]] ++;
        for(int i = 1; i < m; i ++) cnt[i] += cnt[i-1];
        for(int i = len-1; i >= 0; i --) sa[--cnt[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1; x[sa[0]] = 0;
        for(int i = 1; i < len; i ++)
            x[sa[i]] = y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+k] == y[sa[i]+k] ? p-1 : p++;
        if(p >= len) break;
        m = p;
    }
}

void get_height(){
    for(int i = 0; i < len; i++) rank[sa[i]] = i;
    int k = 0;
    for(int i = 0; i < len; i++) {
      if(k) k--;
      int j = sa[rank[i]-1];
      while(data[i+k] == data[j+k]) k++;
      height[rank[i]] = k;
    }
    // 注意data最后一位必须是0，前面的全不为0
}

int main(){
    while(scanf("%s", s) != EOF){
        int pos = strlen(s);
        s[pos] = 'z'+1;
        scanf("%s", s+pos+1);
        memset(data, 0, sizeof(data));
        len = strlen(s);
        for(int i = 0; i < len; i ++)
            data[i] = s[i]-'a'+1;
        build_sa(28);
        get_height();
        int ans = 0;
        for(int i = 1; i < len; i ++){
            //printf("%d ", height[i]);
            if((sa[i-1] > pos && sa[i] < pos) || (sa[i-1] < pos && sa[i] > pos))
                if(height[i] > ans) ans = height[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
conclusion:
13125321	robotcator	2774	Accepted
5760K	594MS	G++	2296B	2014-07-20 17:19:22
1:字符串处理尽量避免多次使用memset， 尽量别在循环内使用strlen
*/
