// Accepted 3112K 594MS
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct entry{
  char a[15];
  char b[15];
};
entry e[100005];

int cmp(entry x, entry y) {
  return strcmp(x.b, y.b) < 0;
}

int Bsearch(entry *e, int left, int right, char *key) {
  int l = left;
  int r = right;
  while(l <= r) {
    int mid = (l+r)/2;
    if(strcmp(e[mid].b, key) == 0) return mid;
    else if(strcmp(e[mid].b, key) > 0) r = mid -1;
    else l = mid + 1;
  }
  return -1;
}

int main()
{
  char data[50];
  int num  = 0;
  while(gets(data)){
    if(data[0] == '\0') break;
    sscanf(data, "%s %s", e[num].a, e[num].b);
    num ++;
  }
  sort(e, e+num, cmp);
  while(scanf("%s", data) != EOF) {
    int ans = Bsearch(e, 0, num-1, data);
    if(ans != -1)
      printf("%s\n", e[ans].a);
    else printf("eh\n");
  }
  return 0;
}
