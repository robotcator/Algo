#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

/*
void permutation1(int cur, int n, int *a){
    if(cur == n){
        for(int i = 0; i < n; i ++){
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    else {
        for(int i = cur; i < n; i ++){
            swap(a[i], a[cur]);
            permutation1(cur+1, n, a);
            swap(a[i], a[cur]);
        }
    }
}

void permutation2(int cur, int n, int *a){
    if(cur == n){
        for(int i = 0; i < n; i ++){
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    else {
        for(int i = 0; i < n; i ++){
            int ok = 1;
            for(int j = 0; j < cur; j ++){
                if(a[j] == i) ok = 0;
            }
            if(ok != 0){
                a[cur] = i;
                permutation2(cur+1, n, a);
            }

        }
    }
}

void permutation3(int cur, int n, list<int> l, int *a){
        if(cur == n) {
            for(list<int> :: iterator it = l.begin(); it != l.end(); it ++){
                printf("%c ", *it+'a');
            }
            printf("\n");
            return ;
        }else{
            for(int i = 0; i <= l.size(); i ++){
                list<int> temp = l;
                list<int>::iterator it = temp.begin();
                for(int j = 0; j < i; j ++) it ++;
                cout << "cur" << cur << endl;
                cout << "pos" << *it << endl;
                for(list<int>:: iterator it = l.begin(); it != l.end(); it ++){
                    cout << (char)(*it + 'a');
                }
                cout << endl;
                temp.insert(it, a[cur]);

                permutation3(cur+1, n, temp, a);
                cout << "y" << endl;
            }
        }
}
*/
void permutation4(int cur, int n, list<int> l, int *a){
        // 生成a的全排列
        if(cur == n) {
            printf("writenln(");
            for(list<int> :: reverse_iterator it = l.rbegin(); it != l.rend(); it ++){
                printf("%c", *it+'a');
            }
            printf(")\n");
        }else{
            for(int i = 0; i <= l.size(); i ++){
                list<int>::iterator it = l.begin();
                for(int j = 0; j < i; j ++) it ++;
                l.insert(it, a[cur]);
                // 在 i 的位置前插入a[cur]
                permutation4(cur+1, n, l, a);
                l.remove(a[cur]);
            }
        }
}

void Init(int *a, int n){
    for(int i = 0; i < n; i ++)
        a[i] = i;
}

int main(){
    int t, n;
    int a[10];
    scanf("%d\n", &t);
    while(t--){
        scanf("%d", &n);
        Init(a, n);
        list<int> l;
        l.clear();
        printf("program sort(input,output);\nvar\n");
        for(int i = 0; i < n; i ++){
            printf("%c", i+'a');
            if(i != n-1) printf(",");
        }
        printf(" : integer;\nbegin\n");
        printf("readline(");
        for(int i = 0; i < n; i ++){
            printf("%c", i+'a');
            if(i != n-1) printf(",");
        }
        printf(");\n");
        permutation4(0, n, l, a);
        printf("end.\n");
    }
    return 0;
}
