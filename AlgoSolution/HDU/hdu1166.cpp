
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

struct node{
    int st, ed;
    int sum;
}st[150000];

int a[50005];
int res;
/*
void build(int root, int l, int r)
{
    st[root].st = l;
    st[root].ed = r;
    for(int i = l; i <= r; i ++){
        st[root].sum += a[i];
    }
    if(r - l > 1){
        int mid = (l+r)/2;
        if(l < mid) build(root*2, l, mid);
        if(r > mid) build(root*2+1, mid, r);
    }

}
*/
void build(int root, int l, int r)
{
    st[root].st = l;
    st[root].ed = r;
    if(l == r) {
        st[root].sum = a[l];
        return ;
    }
    int mid = (l+r)>>1 ;
    build(root<<1, l, mid);
    build((root<<1)+1, mid+1, r);
    st[root].sum = st[root<<1].sum + st[(root<<1)+1].sum;
}

void Add(int p, int v, int root, int l, int r)
{
    int mid = (l+r)/2;
    if(l == r) st[root].sum += v;
    else{
        if(p <= mid) Add(p, v, root<<1, l, mid);
        else Add(p, v, (root<<1)+1, mid+1, r);
        st[root].sum = st[root<<1].sum + st[root*2+1].sum;
    }
}

void Sub(int p, int v, int root, int l, int r)
{
    int mid = (l+r)>>1;
    if(l == r) st[root].sum -= v;       // 找到该点
    else{
        if(p <= mid) Sub(p, v, root<<1, l, mid);     // 二叉查找
        else Sub(p, v, (root<<1)+1, mid+1, r);
        st[root].sum = st[root<<1].sum + st[(root<<1)+1].sum;   // 区间横跨两段
    }
}
/*

int query(int root, int Std, int End)
{
    int Lans = 0;
    int Rans = 0;
    int mid = (st[root].st+st[root].ed)>>1;
    if(Std <= st[root].st && st[root].ed <= End)
        return st[root].sum;
    else if(End < Mid) query(root<<1, Std, End);
        {

        if(Std <= mid) Lans = query(root*2, Std, End);
        if(mid < End) Rans = query(root*2+1, Std, End);
        return Lans+Rans;
    }
}
*/


void query(int u,int l,int r)
{
    if(st[u].st>=l && st[u].ed<=r) {res+=st[u].sum;return;}
    int mid = (st[u].st+st[u].ed) >> 1;
    if(r <= mid) query(u<<1,l,r);
    else if(l > mid) query((u<<1)+1,l,r);
    else{
        query(u<<1, l, mid);
        query((u<<1)+1, mid+1, r);
    }
}


int main()
{
    int t, n;
    string comm;
    int x, y;
    int flag = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++){
            scanf("%d", &a[i]);
        }
        build(1, 1, n);
        printf("Case %d:\n", flag ++);
        while(1){
            cin >> comm;
            if(comm == "End") break;
            else if(comm == "Query"){
                scanf("%d%d", &x, &y);
               // int ans = query(1, x, y);
               // cout << ans << endl;
                res = 0;
                query(1, x, y);
                cout << res << endl;

            }
            else if(comm == "Sub"){
                scanf("%d%d", &x, &y);
                Sub(x, y, 1, 1, n);
            }
            else if(comm == "Add"){
                scanf("%d%d", &x, &y);
                Add(x, y, 1, 1, n);
            }
        }
    }
    return 0;
}
