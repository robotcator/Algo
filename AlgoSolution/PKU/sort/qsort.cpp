/*
#include <stdio.h>
#include <string.h>

using namespace std;

int partition(int a[], int st, int ed)
{
  int key = a[st];
  while(st < ed){
      while(st < ed && a[ed] <= key)
        ed --;
      a[st++] = a[ed];
      while(st < ed && a[st] >= key)
        st ++;
      a[ed--] = a[st];
  }
  a[st] = key;
  return st;
}

void quicksort(int a[], int st, int ed)
{
  if(st < ed){
    int pos = partition(a, st, ed);
    quicksort(a, st, pos-1);
    quicksort(a, pos+1, ed);
  }
}

int main()
{

  int a[] = {49, 38, 65, 97, 76, 13, 27, 49};
  quicksort(a, 0, 7);

  for(int i = 0; i < 8; i ++){
    printf("%d\n", a[i]);
  }
  return 0;
}
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int main()
{
    string  st;
    cin>>st;
    reverse(st.begin(),st.end());
    cout<<st<<endl;
    return 0;
}
