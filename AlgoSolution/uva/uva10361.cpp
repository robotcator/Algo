#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100+10;

/*
input :
3
ein kind haelt seinen <schn>abel <n>ur
wenn es haengt an der ...
weil wir zu spaet zur <>oma <k>amen
verpassten wir das ...
<d>u <b>ist
...

*/

int main(){
    int n;
    char l1[maxn], l2[maxn];
    scanf("%d%\n", &n);
    while(n --){
        gets(l1);
        gets(l2);
        int len = strlen(l1);
        int pos[3][3];
        int i1 ,i2;
        i1 = i2 = 0;
        for(int i = 0; i < len; i ++){
            if(l1[i] == '>' || l1[i] == '<') {
                if(l1[i] == '<') {pos[0][i1++] = i;}
                else pos[1][i2++] = i;
            }
            else printf("%c", l1[i]);
        }
        printf("\n");
        // ���l1 ���� �ҵ�<> λ��
        //cout << pos[0][0] << pos[0][1] << endl;
        //cout << pos[1][0] << pos[1][1] << endl;
        char s2[maxn], s3[maxn], s4[maxn], s5[maxn];
        len = 0;
        for(int i = pos[0][0]+1; i < pos[1][0]; i ++){
            s2[len++] = l1[i];
        }
        s2[len++] = '\0';
        // �ҵ�s2
        len = 0;
        for(int i = pos[1][0]+1; i < pos[0][1]; i ++){
            s3[len++] = l1[i];
        }
        s3[len++] = '\0';
        // �ҵ� s3
        len = 0;
        for(int i = pos[0][1]+1; i < pos[1][1]; i ++){
            s4[len++] = l1[i];
        }
        s4[len++] = '\0';
        // �ҵ� s4
        len = 0;
        for(int i = pos[1][1]+1; l1[i] != '\0'; i ++){
            s5[len++] = l1[i];
        }
        s5[len++] = '\0';
        // �ҵ� s5
        for(int i = 0; l2[i] != '.' ; i ++)
            printf("%c", l2[i]);
        printf("%s%s%s%s", s4, s3, s2, s5);
        printf("\n");
    }
    return 0;
}


/*
conclusion:
13775628 	10361 	Automatic Poetry
Accepted 	C++11 	0.009 	2014-06-21 12:56:00

1: ���ַ����Һ��滻
2: ע�� \0  ��  \n ����

\0 ���ַ��������ı�־
\n ֻ�ǻس����У���scanf�����Ὣ�� �� �� \n ת��Ϊ \0

*/
