// �򵥹�ϣ����
// ö�������������º�����������Թ���������
// ÿ����������Ϊabcd�лᱻö��ab,bc,cd,da
// ʱ��ö�ٹ�һ�飬����numҪ����4
// ��ϣ��ȻΪ��ʡ�ռ����ָ��
// Wrong Answer  ��ϣ���������⣬����֮��ܶ��
// ��ƽ��ȡ�෨��ƹ�ϣ���� ����ʹ��С�ڻ������󳤶�*2������
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
// ȫ�ֱ�����Ҫÿ�ζ�����
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
    // ����ж��ܷ����������
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
 // ������ָ��ļ��Ϲ��캯�����Լ��ٴ���
 // ���ɺ�ϰ��
  int x, y;
  HashTable *next;
};

HashTable Hash[2005];
// ��ϣ�ڵ������
// ���߿�һ��ָ������

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
    // ����ж��ܷ����������
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
// ��ϣ�ڵ������
// ���߿�һ��ָ������

int hash(int x, int y) {
  return (x*x + y*y) % modu;
}

void Insert(int x, int y) {
  int key = hash(x, y);
  HashTable* p = Hash[key];
  // Hash[key] ���׵�ַ��ַ
  HashTable* newNode = new HashTable();
  // newNode Ϊ�ṹ��ָ��
  newNode->x = x; newNode->y = y;
  newNode->next = NULL;

  //if(Hash[key] == NULL) Hash[key] = newNode;
  if(p == NULL) Hash[key] = newNode;
  // why
  // ע���׸�Ԫ����Ϊ�������ĸ���p��ʵ��һ���׵�ַ�ĵ�ַ
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
    // ����ж��ܷ����������
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


