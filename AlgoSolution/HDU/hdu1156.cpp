#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct v{
    char label[20];
};
struct G{
    v *n;
};

int main()
{
    G a;
    a.n = (v *)malloc(5*sizeof(v));

    scanf("%s", a.n[0].label);
    char d[20] = "aadd";
    printf("%s\n", a.n[0].label);
    printf("%s\n", a.n[0].label);

    printf("%d\n",strcmp(a.n[0].label, d));
    printf("%s", a.n[0].label);

    return 0;
}
