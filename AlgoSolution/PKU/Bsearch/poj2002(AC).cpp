// 简单哈希查找
// 枚举两个点往左下和右上延伸可以够成正方形
// 每个正方形因为abcd有会被枚举ab,bc,cd,da
// 时都枚举过一遍，所以num要除以4
// 哈希既然为了省空间就用指针
// Wrong Answer  哈希函数有问题，测试之后很多错啊
// 用平方取余法设计哈希函数 余数使用小于或等于最大长度*2的素数
/*
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int magnitude = 20000;

struct point{
  int x, y;
};

struct hashp{
  hashp() {
  data = -(magnitude+2);
  next = NULL;
 }
 hashp(int data, hashp* next) {
  this->data = data;
  this->next = next;
 }
  int data;
  hashp *next;
};

hashp Hash[40005];
// 全局变量需要每次都清零
int Find(int x, int y) {
  hashp *p = &Hash[x+magnitude];
  if(p->data == -(magnitude+2)) return 0;
  else {
    while(p != NULL) {
      if(p->data == y) return 1;
      p = p->next;
    }
  }
  return 0;
}

int main()
{
  int n;
  point p[1005];
  freopen("in.txt", "r", stdin);
  while(scanf("%d", &n) != EOF){
    if(n == 0) break;
    memset(Hash, 0, sizeof(Hash));
    int x, y;
    for(int i = 0; i < n; i ++){
      scanf("%d%d", &x, &y);
      p[i].x = x; p[i].y = y;
      if(Hash[x+magnitude].data == -(2+magnitude))
        Hash[x+magnitude].data = y;
      else {
        hashp *p = &Hash[x+magnitude];
        while(p->next != NULL) p = p->next;
        p->next = new hashp(y, NULL);
      }
    }
    // 如何判断能否组陈三角形
    int num = 0;
    for(int i = 0; i < n; i ++){
      for(int j = i+1; j < n; j ++){
        int cx = p[i].x + p[i].y - p[j].y;
        int cy = p[i].y + p[j].x - p[i].x;
        int dx = p[j].x + p[i].y - p[j].y;
        int dy = p[j].y + p[j].x - p[i].x;
        if(Find(cx, cy) && Find(dx, dy)) num ++;
        cx = p[i].x - (p[i].y - p[j].y);
        cy = p[i].y - (p[j].x - p[i].x);
        dx = p[j].x - (p[i].y - p[j].y);
        dy = p[j].y - (p[j].x - p[i].x);
        if(Find(cx, cy) && Find(dx, dy)) num ++;
      }
    }
    printf("%d\n", num/4);
  }
  return 0;
}
*/
/*
// Accepted 560K 1735MS
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int modu = 1999;

struct point{
  int x, y;
};

struct HashTable{
  HashTable() {
  this->x = this->y = -1;
  next = NULL;
 }
 HashTable(int x, int y, HashTable* next) {
  this->x = x;
  this->y = y;
  this->next = next;
 }
 // 对于有指针的加上构造函数可以减少代码
 // 养成好习惯
  int x, y;
  HashTable *next;
};

HashTable Hash[2005];
// 哈希节点的数组
// 或者开一个指针数组

int hash(int x, int y) {
  return (x*x + y*y) % modu;
}

void Insert(int x, int y) {
  int key = hash(x, y);
  HashTable* p = &Hash[key];
  if(p == NULL) p = new HashTable(x, y, NULL);
  else {
    while(p->next != NULL) p = p->next;
    p->next = new HashTable(x, y, NULL);
  }
}

int Find(int x, int y) {
  int key = hash(x, y);
  HashTable *p = &Hash[key];
  if(p == NULL) return 0;
  else {
    while(p != NULL) {
      if(p->x == x && p->y == y) return 1;
      p = p->next;
    }
  }
  return 0;
}

int main()
{
  int n;
  point p[1005];
  freopen("in.txt", "r", stdin);
  while(scanf("%d", &n) != EOF){
    if(n == 0) break;
    memset(Hash, 0, sizeof(Hash));
    int x, y;
    for(int i = 0; i < n; i ++){
      scanf("%d%d", &x, &y);
      p[i].x = x; p[i].y = y;
      Insert(x, y);
    }
    // 如何判断能否组陈三角形
    int num = 0;
    for(int i = 0; i < n; i ++){
      for(int j = i+1; j < n; j ++){
        int cx = p[i].x + p[i].y - p[j].y;
        int cy = p[i].y + p[j].x - p[i].x;
        int dx = p[j].x + p[i].y - p[j].y;
        int dy = p[j].y + p[j].x - p[i].x;
        if(Find(cx, cy) && Find(dx, dy)) num ++;
        cx = p[i].x - (p[i].y - p[j].y);
        cy = p[i].y - (p[j].x - p[i].x);
        dx = p[j].x - (p[i].y - p[j].y);
        dy = p[j].y - (p[j].x - p[i].x);
        if(Find(cx, cy) && Find(dx, dy)) num ++;
      }
    }
    printf("%d\n", num/4);
  }
  return 0;
}
*/
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int modu = 1999;

struct point{
  int x, y;
};

struct HashTable{
  HashTable(){
    this->next = NULL;
  }
  HashTable(int x, int y, HashTable* next){
    this->x = x;
    this->y = y;
    this->next = next;
  }
  int x, y;
  HashTable *next;
};

HashTable *Hash[2005];
// 哈希节点的数组
// 或者开一个指针数组

int hash(int x, int y) {
  return (x*x + y*y) % modu;
}

void Insert(int x, int y) {
  int key = hash(x, y);
  HashTable* p = Hash[key];
  // Hash[key] 的首地址地址
  HashTable* newNode = new HashTable();
  // newNode 为结构体指针
  newNode->x = x; newNode->y = y;
  newNode->next = NULL;

  //if(Hash[key] == NULL) Hash[key] = newNode;
  if(p == NULL) Hash[key] = newNode;
  // why
  // 注意首个元素因为用上述的复制p其实是一个首地址的地址
  else {
    while(p->next != NULL) p = p->next;
     p->next = newNode;
    //p->next = new HashTable();
    //p->next->x = x;
    //p->next->y = y;
    //p->next->next = NULL;
  }
}

int Find(int x, int y) {
  int key = hash(x, y);
  HashTable *p = Hash[key];
  if(p == NULL) return 0;
  else {
    while(p != NULL) {
      if(p->x == x && p->y == y) return 1;
      p = p->next;
    }
  }
  return 0;
}

int main()
{
  int n;
  point p[1005];
  freopen("in.txt", "r", stdin);
  while(scanf("%d", &n) != EOF){
    if(n == 0) break;
    memset(Hash, 0, sizeof(Hash));
    int x, y;
    for(int i = 0; i < n; i ++){
      scanf("%d%d", &x, &y);
      p[i].x = x; p[i].y = y;
      Insert(x, y);
    }
    // 如何判断能否组陈三角形
    int num = 0;
    for(int i = 0; i < n; i ++){
      for(int j = i+1; j < n; j ++){
        int cx = p[i].x + p[i].y - p[j].y;
        int cy = p[i].y + p[j].x - p[i].x;
        int dx = p[j].x + p[i].y - p[j].y;
        int dy = p[j].y + p[j].x - p[i].x;
        if(Find(cx, cy) && Find(dx, dy)) num ++;
        cx = p[i].x - (p[i].y - p[j].y);
        cy = p[i].y - (p[j].x - p[i].x);
        dx = p[j].x - (p[i].y - p[j].y);
        dy = p[j].y - (p[j].x - p[i].x);
        if(Find(cx, cy) && Find(dx, dy)) num ++;
      }
    }
    printf("%d\n", num/4);
  }
  return 0;
}


