#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int st, ed;
    long long sum;
}st1[2500000], st2[2500000];

int a[100005];
long long res;

void build(int root, int l, int r)
{
    st1[root].st = l;
    st1[root].ed = r;
    if(l == r) {
        st1[root].sum = a[l];
        return ;
    }
    int mid = (l+r)>>1 ;
    build(root<<1, l, mid);
    build((root<<1)+1, mid+1, r);
    st1[root].sum = st1[root<<1].sum + st1[(root<<1)+1].sum;
}

void query(int u,int l,int r)
{
    if(st1[u].st>=l && st1[u].ed<=r) {res+=st1[u].sum;return;}
    int mid = (st1[u].st+st1[u].ed) >> 1;
    if(r <= mid) query(u<<1,l,r);
    else if(l > mid) query((u<<1)+1,l,r);
    else{
        query(u<<1, l, mid);
        query((u<<1)+1, mid+1, r);
    }
}

void build1(int root, int l, int r)
{
    st2[root].st = l;
    st2[root].ed = r;
    if(l == r) {
        st2[root].sum = a[l];
        return ;
    }
    int mid = (l+r)>>1 ;
    build1(root<<1, l, mid);
    build1((root<<1)+1, mid+1, r);
    st2[root].sum = st2[root<<1].sum + st2[(root<<1)+1].sum;
}

void query1(int u,int l,int r)
{
    if(st2[u].st>=l && st2[u].ed<=r) {res+=st2[u].sum;return;}
    int mid = (st2[u].st+st2[u].ed) >> 1;
    if(r <= mid) query1(u<<1,l,r);
    else if(l > mid) query1((u<<1)+1,l,r);
    else{
        query1(u<<1, l, mid);
        query1((u<<1)+1, mid+1, r);
    }
}


int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    for(int i = 1; i <= n; i ++){
      scanf("%d", &a[i]);
    }
    build(1, 1, n);
    sort(a+1, a+n+1);
    build1(1, 1, n);
    int m, q, l, r  ;
    scanf("%d", &m);
    for(int i = 0; i < m; i ++){
      scanf("%d%d%d", &q, &l, &r);
      if(q == 1){
        res = 0;
        query(1, l, r);
        cout << res << endl;
      }
      else {
        res = 0;
        query1(1, l, r);
        cout << res << endl;
      }
    }
  }
  return 0;
}
