/*
    ID : problem6
    PROG : ride
    LANG : C++
    Quote : ��ѧ�뾲Ҳ ����ѧҲ ��ѧ���Թ�� ��־���Գ�ѧ
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 1000+10;
const int inf = 0x3f3f3f3f;
const long long uinf = 0x7fffffffffffffffL;

int rank[maxn], temp[maxn];
int n, k;
bool compare_sa(int i, int j){
  if(rank[i] != rank[j]) return rank[i] < rank[j];
  else {
    int ri = i+k <= n ? rank[i+k] : -1;
    int rj = j+k <= n ? rank[j+k] : -1;
    return ri < rj;
  }
}
void construct_sa(string s, int *sa){
  n = s.length();
  for(int i = 0; i <= n; i ++){
    sa[i] = i;
    rank[i] = i < n ? s[i] : -1;
  }
  for(k = 1; k <= n; k *= 2){
    // k��ȫ�ֱ�������ϵ����
    sort(sa, sa+n+1, compare_sa);
    temp[sa[0]] = 0;
    for(int i = 1; i <= n; i ++){
      temp[sa[i]] = temp[sa[i-1]] + (compare_sa(sa[i-1], sa[i]) ? 1 : 0);
    }
    for(int i = 0; i <= n; i ++)
      rank[i] = temp[i];
  }
}

int main(){
  int sa[maxn];
  string a = "abracadabra";
  //string a = "aabaaaab";
  construct_sa(a, sa);
  return 0;
}
