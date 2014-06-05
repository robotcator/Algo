/*
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
   int t;
   char data[300];
   scanf("%d", &t);
   while(t--){
    scanf("%s", data);
      for(int i = 0; i < strlen(data); i ++){

      }
   }
   return 0;
}
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 2000+10;

struct members{
  int Id;
  char Date[10];
  int s;
}m[maxn];

bool cmp(const int i, const int j){
  if(m[i].s != m[j].s)  return m[i].s < m[j].s;
  else if(strcmp(m[i].Date, m[j].Date) != 0)
    return strcmp(m[i].Date, m[j].Date) > 0;
  else return m[i].Id > m[j].Id;
}

void get_lvnum(int *lvn, int num, int zero, int n){
  lvn[6] = (int)floor(num*0.03);
  lvn[5] = (int)floor(num*0.07);
  lvn[4] = (int)floor(num*0.2);
  lvn[3] = (int)floor(num*0.3);
  lvn[1] = zero;
  lvn[2] = n - (lvn[1]+lvn[3]+lvn[4]+lvn[5]+lvn[6]);
  /*
  for(int i = 1; i <= 6; i ++){
    cout << lvn[i] << endl;
  }
  */
}

int main()
{
   int t, n;
   int lv[maxn];
   int lvn[7];
   scanf("%d", &t);
   while(t--){
      scanf("%d", &n);
      int num , zero;
      num = zero = 0;
      for(int i = 0; i < n; i ++){
          scanf("%d%s%d", &m[i].Id, m[i].Date, &m[i].s);
          //printf("%d %s %d\n", m[i].Id, m[i].Date, m[i].s);
          if(m[i].s > 0) num ++;
          if(m[i].s == 0) zero ++;
      }
      int mem[maxn];
      for(int i = 0; i < n; i ++) mem[i] = i;
      sort(mem, mem+n, cmp);
      get_lvnum(lvn, num, zero, n);
      /*
      for(int i = 0; i < n; i ++){
          printf("%d\n", mem[i]);
      }
      */
      int i = 0;
      int k = 1;
      while(i < n){
        //cout << "x" << endl;
        for(int j = i; j < i+lvn[k]; j ++){
          lv[mem[j]] = k;
        }
        i += lvn[k];
        k ++;
      }

      for(int i = 0; i < n; i ++){
        printf("LV%d\n", lv[i]);
      }

   }
   return 0;
}

