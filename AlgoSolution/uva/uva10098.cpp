#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        string data;
        cin >> data;
        sort(data.begin(), data.end());
        cout << data << endl;
        while(next_permutation(data.begin(), data.end())){
            cout << data << endl;
        }
        printf("\n");
    }
    return 0;
}
/*
conclusion:
13790754 	10098 	Generating Fast
Accepted 	C++11 	0.882 	2014-06-25 06:35:13
1:用库函数处理即可

*/
