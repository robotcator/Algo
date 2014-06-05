#include <string.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>

using namespace std;
const int inf = 0x3f3f3f3f;

struct node{
    int freq;
    int data;
    int left, right;
};
node N[100];
char code[100][1000];
//stack<char> s;
//不支持迭代器
char s[1000];
int p ;

int select(int m, int *vis)
{
    int Min = inf;
    int pos = -1;
    for(int i = 0; i < m; i ++){
        if(N[i].freq < Min && vis[i] == 0){
            Min = N[i].freq;
            pos = i;
        }
    }
    vis[pos] = 1;
    return pos;
}

void huffman(int& n)
{
    int m = n;
    int vis[100];
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < m-1; i ++){
        int pos1 = select(n, vis);
        int pos2 = select(n, vis);
        // 选取最小的两个数字
        // cout << pos1 << " " << pos2 << endl;
        N[n].data = -1;   // 可以对数据进行其他处理
        // cout << N[pos1].freq << " " << N[pos2].freq << endl;
        N[n].freq = N[pos1].freq + N[pos2].freq;
        N[n].left = pos1;
        N[n].right = pos2;
        // 内部节点
        n ++;
       // cout << "n " << n << endl;
    }
}

void Travese(int n)
{
    // 用数组实现的二叉树的遍历
    // 小心空指针的代替，对于赋值为-1要注意数组越界
    if(n >= 0 && (N[n].data != inf)){
        //cout << N[n].freq << endl;
        cout << n << endl;
        Travese(N[n].left);
        Travese(N[n].right);
    }
}

void huffmancode(int n)
{
    if(n >= 0 && (N[n].data != inf)){
        if(N[n].left == -1 && N[n].right == -1){
           // cout << "n " << n << endl;
            for(int i = 0; i < p; i ++)
                code[n][i] = s[i];
           // cout << s << endl;
        }
        else{
            s[p++] = '0';
            huffmancode(N[n].left);
            p --;
            s[p++] = '1';
            huffmancode(N[n].right);
            p --;
        }
    }
}

int main()
{
    string data;
    int num[30];
    while(cin >> data){
        if(data == "END") break;
        memset(num, 0, sizeof(num));
        for(int i = 0; i < data.size(); i ++){
            if(data[i] == '_') num[0] ++;
            else{
                num[data[i]-'A'+1] ++;
            }
        }
        for(int i = 0; i < 100; i ++){
            N[i].data = inf;
        }
        int n = 0;
        for(int i = 0; i < 30; i ++){
            if(num[i] > 0) {
                N[n].data = i;
                N[n].freq = num[i];
                N[n].left = -1;
                N[n].right = -1;
                n ++;
            }
        }
        int tag = n;
        //for(int i = 0; i < 30; i ++)
        //    cout << N[i].data << " " << N[i].freq << endl;

        huffman(n);   //  传递叶子节点和叶子节点数
        //cout << n << endl;
        //for(int i = 0; i < 60; i ++){
        //    cout << N[i].data << " " << N[i].freq << endl;
        //    cout << "x" << N[i].left << " " << N[i].right << endl;
        //}
        //Travese(n-1);
        p = 0;
        for(int i = 0; i < 100; i ++)
            memset(code[i], 0, sizeof(code[i]));
        huffmancode(n-1);
        int ans = 0;
        for(int i = 0; i < tag; i ++){
            // cout << code[i] << endl;
            ans += strlen(code[i])*N[i].freq;
            // 还要乘以权重
        }
        if(tag == 1)
            printf("%d %d %.1lf\n", 8*data.size(), data.size(), 8.0*data.size()/data.size());
        else
            printf("%d %d %.1lf\n", 8*data.size(), ans, 8.0*data.size()/ans);
    }
    return 0;
}
