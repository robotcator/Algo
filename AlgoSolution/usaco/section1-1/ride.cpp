/*
    ID: problem6
    PROG : ride
    LANG : C++
*/

#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    char a[10], b[10];
    ifstream fin("ride.in");
    ofstream fout("ride.out");
    fin >> a >> b ;
    //freopen("ride.in", "r", stdin);
    //freopen("ride.out", "w", stdout);
    //scanf("%s%s", a, b);
    int na, nb;
    na = nb = 1;
    for(int i = 0; i < strlen(a); i ++){
        na *= (a[i]-'A'+1);
    }
    for(int i = 0; i < strlen(b); i ++){
        nb *= (b[i]-'A'+1);
    }
    if(na%47 == nb%47){
        fout << "GO" << endl;
    }else{
        fout << "STAY" << endl;
    }
    return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    char a[10], b[10];
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    scanf("%s%s", a, b);
    int na, nb;
    na = nb = 1;
    for(int i = 0; i < strlen(a); i ++){
        na *= (a[i]-'A'+1);
    }
    for(int i = 0; i < strlen(b); i ++){
        nb *= (b[i]-'A'+1);
    }
    if(na%47 == nb%47){
        printf("GO\n");
    }else{
        printf("STAY\n");
    }
    return 0;
}
*/
