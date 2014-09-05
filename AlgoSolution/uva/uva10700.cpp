/*
    ID: problem6
    PROG : Camel trading
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int maxn = 100;
char data[maxn];

int main(){
    int T;
    scanf("%d", &T);
    while(T --){
        scanf("%s", data);
        int len = strlen(data);
        double mmax, mmin;
        stack<double> s;
        while(!s.empty()) s.pop();
        for(int i = 0; i < len; i ++){
            if(data[i] >= '0' && data[i] <= '9'){
                int temp = 0;
                while((data[i] >= '0' && data[i] <= '9')){
                    temp = temp*10 + data[i]-'0';
                    i ++;
                }
                s.push((double)temp);
                i --;
            }
            else if(data[i] == '+'){
                i ++;
                int temp = 0;
                while((data[i] >= '0' && data[i] <= '9')){
                    temp = temp*10 + data[i]-'0';
                    i ++;
                }
                double tempa = s.top();
                s.pop();
                s.push(double(tempa + temp));
                i --;
            }
        }
        mmax = 1;
        while(!s.empty()) { mmax *= s.top(); s.pop(); }
        for(int i = 0; i < len; i ++){
            if(data[i] >= '0' && data[i] <= '9'){
                int temp = 0;
                while((data[i] >= '0' && data[i] <= '9')){
                    temp = temp*10 + data[i]-'0';
                    i ++;
                }
                s.push((double)temp);
                i --;
            }
            else if(data[i] == '*'){
                i ++;
                int temp = 0;
                while((data[i] >= '0' && data[i] <= '9')){
                    temp = temp*10 + data[i]-'0';
                    i ++;
                }
                double tempa = s.top();
                s.pop();
                s.push((double)(tempa * temp));
                i --;
            }
        }
        mmin = 0;
        while(!s.empty()) {  mmin += s.top(); s.pop(); }
        printf("The maximum and minimum are %.0lf and %.0lf.\n", mmax, mmin);

    }
    return 0;
}
/*
conclusion :
13816300 	10700 	Camel trading 	Accepted
C++11 	0.018 	2014-07-01 07:05:27

*/
