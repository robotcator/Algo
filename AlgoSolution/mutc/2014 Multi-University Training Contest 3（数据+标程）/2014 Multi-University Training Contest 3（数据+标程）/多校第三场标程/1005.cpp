#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <assert.h>

using namespace std;

char lineBuffer[2333333];

int main(void)
{
	int n = 0;
	int totLength = 0;
	while(scanf("%d\n",&n) == 1)
	{
		assert(1 <= n && n <= 1000);

		int ans = 1;
		#define setAns(x) do{if((x) > 100000) { ans = 233333; isDoge = true; } else ans = (x);}while(0);
		bool isDoge = false;
		bool inDollar = false;
		int multiState = 0; // 0 normal, 1: wait for | or }
		int choice = 0;
		int consSpace = 0;
		for(int i = 0;i < n;i++)
		{
			gets(lineBuffer);
			int len = strlen(lineBuffer);
			totLength += len;
			for(int j = 0;j < len;j++)
			{
				if(inDollar)
				{
					if(lineBuffer[j] == ' ') consSpace++;
					else
					{
						setAns((long long)ans * (consSpace+1LL));
						consSpace = 0;
					}
				}
				if(lineBuffer[j] == '$')
				{
					consSpace = 0;
					inDollar ^= 1;
				}
				if(multiState == 0)
				{
					assert(lineBuffer[j] != '|');
					assert(lineBuffer[j] != '}');

					assert(!inDollar || lineBuffer[j] != '{'); // extra detection

					if(lineBuffer[j] == '{')
					{
						choice = 1;
						multiState = 1;
					}
				}
				else if(multiState == 1)
				{
					assert(lineBuffer[j] != '$'); // extra detection 02
					
					if(lineBuffer[j] == '|')
					{
						choice++;
					}
					else if(lineBuffer[j] == '}')
					{
						setAns(ans * (long long)choice);
						//setAns(ans * choice);
						multiState = 0;
					}
				}
			}
		}
		#undef setAns
		assert(!inDollar);
		assert(multiState == 0);

		if(isDoge) puts("doge");
		else printf("%d\n",ans);
	}
	assert(scanf("%*s") == EOF);
	assert(totLength <= 1024 * 1024);
	return 0;
}
