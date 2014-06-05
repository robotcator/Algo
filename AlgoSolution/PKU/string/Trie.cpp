#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

const int maxn = 10000;
const int sigma_size = 26;

class Trie{
  int data[maxn][sigma_size];
  int val[maxn];
  int sz;

  void init() {
    memset(data[0], 0, sizeof(data[0]));
    sz = 1;
  }

  int index(char c) {
    return c -'0';
  }

  void Insert(char *s, int v) {
    int len = strlen(s);
    int u = 0; // �Ӹ��ڵ㿪ʼ
    for(int i = 0; i < len; i ++) {
      int c = index(s[i]);
      if(data[u][c] == 0) {
        memset(data[sz], 0, sizeof(data[sz]));
        val[sz] = 0; // �ڲ��ڵ�
        data[u][c] = sz ++; // ����
      }
      u = data[u][c];
    }
    val[u] = v;  //  �������ʵĽ�β
  }

  int Search(char *s) {
    // �ҵ��򷵻���val,û���ҵ��򷵻�0
    // Ҫ�޸�
    int len = strlen(s);
    int u = 0, i;
    for(i = 0; i < len; i ++){
      int c = index(s[i]);
      u = data[u][c];
      if(u == 0) break;
    }
    if(i == len && val[u] > 0) return val[u];
    else return 0;
  }

  bool Delete(char *s) {
    // �ɹ�ɾ������true��δ�ɹ���false
    int len = strlen(s);
    int u = 0;
    for(int i = 0; i < len; i ++){
      int c = index(s[i]);
      u = data[u][c];
    }
    if(val[u] > 0) {
      val[u] = 0;
      // ֻ��ɾ�������ݻ��ڣ������õݹ�Ӻ���ǰ������ɾ��
      return true;
    }
    else return false;
  }

  void traverse() {
    // �����ѽ����е������
    char temp[maxn];
    dfs(0, temp, 0);
  }

  void print_word(char *temp, int num) {
    for(int i = 0; i < num; i ++)
      printf("%c", temp[i]);
    printf("\n");
  }

  void dfs(int root, char *temp, int num) {
    if(val[root] > 0) print_word(temp, num);
    for(int i = 0; i < sigma_size; i ++){
      if(data[root][i] != 0){
        temp[num] = i + 'a';
        dfs(data[root][i], temp, num+1);
      }
    }
  }

  int longestPrefix(char *s) {
    int len = strlen(s);
    int u = 0;
    int num = 0;
    for(int i = 0; i < len; i ++){
      int c = index(s[i]);
      if(data[u][c] == 0) break;
      num ++;
      u = data[u][c];
    }
    return num;
  }
};

void showmenu()
{
  cout << "����" << endl;
  cout << "ɾ��" << endl;
  cout << "����" << endl;
  cout << "����" << endl;
  cout << "s�ǰ׺" << endl;
}

void test()
{
  showmenu();


}

int main()
{

  return 0;
}
