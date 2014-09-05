#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <assert.h>

using namespace std;

int exp2[32];

int main(void)
{
	int c = 0;
	exp2[0] = 1;
	for(int i = 1;i < 32;i++)
	{
		exp2[i] = exp2[i-1] * 2;
	}
	while(scanf("%d",&c) == 1)
	{
		puts("61 90");

		for(int i = 0;i < 30;i++)
		{
			printf("%d %d %d\n",1+i*2,1+i*2+1,0);
			printf("%d %d %d\n",1+i*2+1,1+i*2+2, -exp2[30-i]);
			printf("%d %d %d\n",1+i*2,1+i*2+2, -exp2[29-i]);
		}
	}
	assert(scanf("%*s") == EOF);
	return 0;
}
