// 1092K 250MS
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
// 首先要注意到a吃b,b吃c，那么c一定吃a
// 其实真心觉得很巧妙
/*
因为并查集中的元素均是有联系的，否则也不会被合并到当前集合中。那么我们

就把这2个元素之间的关系量转化为一个偏移量，以食物链的关系而言，不妨假设

a->b 偏移量0时 a和b同类

a->b 偏移量1时 a吃b

a->b 偏移量2时 a被b吃，也就是b吃a

有了这些基础，我们就可以在并查集中完成任意两个元素之间的关系转换了。

不妨继续假设，a的当前集合根节点aa，b的当前集合根节点bb，a->b的偏移值为d-1（题中给出的询问已知条件）

(1)如果aa和bb不相同，那么我们把bb合并到aa上，并且更新delta[bb]值（delta[i]表示i的当前集合根节点到i的偏移量）

    此时 aa->bb = aa->a + a->b + b->bb，可能这一步就是所谓向量思维模式吧

    上式进一步转化为：aa->bb = (delta[a]+d-1+3-delta[b])%3 = delta[bb]，（模3是保证偏移量取值始终在[0,2]间）

(2)如果aa和bb相同，那么我们就验证a->b之间的偏移量是否与题中给出的d-1一致

    此时 a->b = a->aa + aa->b = a->aa + bb->b，

    上式进一步转化为：a->b = (3-delta[a]+delta[b])%3，

    若一致则为真，否则为假。

*/

const int maxn = 50000+10;
int Set[maxn];
// 每个节点的根是谁
int Rank[maxn];
// 每个节点和其所在集合的根的关系

void init(int n){
  memset(Rank, 0, sizeof(Rank));
  for(int i = 0; i <= n; i ++){
    Set[i] = i;
  }
}

int Find(int x){
  if(x != Set[x]){
    int fa = Set[x];
    Set[x] = Find(Set[x]);
    Rank[x] = (Rank[x]+Rank[fa])%3;
  }
  // 自己跟父节点的和
  return Set[x];
}

void Union(int a, int b, int fa, int fb, int d){
  Set[fa] = b;
  Rank[fa] = (3-Rank[a] + d-1 + Rank[b]);
  // 为什么是对根
}
/*
        int a = findParent(ani[X]);
        int b = findParent(ani[Y]);
        ani[b].parent = a;
        就是把Y所在集合的根节点的父亲设置成X所在集合的根节点。
        但是，但是！！！！
        Y所在集合的根结点与X所在集合的根节点的关系！！！要怎么确定呢？
        我们设X,Y集合都是路径压缩过的，高度只有2层
        我们先给出计算的公式
        ani[b].relation = ( 3 - ani[Y].relation + ( d - 1 ) + ani[X].relation) % 3;
        这个公式，是分三部分，这么推出来的
        第一部分，好理解的一部分：
        ( d - 1 ) :这是X和Y之间的relation，X是Y的父节点时，Y的relation就是这个
        3 - ani[Y].relation = 根据Y与根节点的关系，逆推根节点与Y的关系
        这部分也是穷举法推出来的，我们举例：
        j
        子         父相对于子的relation（即假如子是父的父节点，那么父的relation应该是什么，因为父现在是根节点，所以父.relation = 0，我们只能根据父的子节点反推子跟父节点的关系）
         0             ( 3 - 0 ) % 3 = 0
         1（父吃子）   ( 3 - 1 ) % 3 = 2 //父吃子
         2（子吃父)    ( 3 - 2 ) % 3 = 1 //子吃父，一样的哦亲

*/


int main()
{
  int n, k;
  int d, a, b;
  scanf("%d%d", &n, &k);
    init(n);
    int num = 0;
    for(int i = 0; i < k; i ++){
      scanf("%d%d%d", &d, &a, &b);
      if(a > n || b > n ||(d == 2 && a == b))
        num ++;
      else{
        int fa = Find(a);
        int fb = Find(b);
        //cout << fa << fb << endl;
        if(fa != fb){
          Union(a, b, fa, fb, d);
          //cout << Rank[a] << Rank[b] << endl;
        }
        else {
           // cout << Rank[a] << " " << Rank[b]+d-1 << endl;
            if(Rank[a] != (Rank[b]+d-1)%3)
              num ++;
        }
      }
      //cout << num << endl;
    }
    cout << num << endl;
  return 0;
}
