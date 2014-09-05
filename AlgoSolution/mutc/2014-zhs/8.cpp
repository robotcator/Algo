/*
    ID: problem6
    PROG : ride
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct point{
    int pos;
    int x , y;
    bool operator<(const point a)const{
        return pos < a.pos;
    }
};

int main(){
    int n, m;
    set<point> s;
    while(scanf("%d%d", &n, &m) != EOF){
        point temp;
        for(int i = 1; i <= n; i ++){
            scanf("%d%d", &temp.x, &temp.y);
            temp.pos = i;
            s.insert(temp);
        }
        char ch;
        int x, d, t;
        scanf("%d", &t);
        while(t--){
            scanf("%c %d", &ch, &x);
            if(ch == 'Q'){
                for(int i = 1; i <= n; i ++){
                    point temp = s.find(i);
                }
            }else{

            }
        }
    }
    return 0;
}
