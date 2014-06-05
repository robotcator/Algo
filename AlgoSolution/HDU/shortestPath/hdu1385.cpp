/*
// 第一版
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

const int Max = 500;
const int inf = 0x3f3f3f3f;
int graph[Max][Max];
int v[Max];
int path[Max][Max];
// 前驱矩阵

void intial(int n)
{
	int i, j;  
    for(i = 0; i < n; i++)  
        for(j = 0; j < n; j++)  
            if(i == j) graph[i][j] = 0;  
            else graph[i][j] = inf;  

}
// refer to introduction to algorithm 

void Floyd(int n)
{
	int i, j, k;
	for(i = 0; i < n; i ++)
		for(j = 0; j < n; j ++)
			path[i][j] = j;

	int len;
	for(k = 0; k < n; k ++){
		for(i = 0; i < n; i ++){
			for(j = 0; j < n; j ++){
				len = graph[i][k] + graph[k][j] + v[k];  
               if(graph[i][j] > len)  
                {  
                    graph[i][j] = len;  
                    path[i][j] = path[i][k];    //标记到该点的前一个点  
                }  
                else if(len == graph[i][j])   //若距离相同  
                {  
                    if(path[i][j] > path[i][k]) //判断是否为字典顺序  
                        path[i][j] = path[i][k];  
                }  

			}
		}
	}
}

void print_path(int i, int j)
{
	
	 int k = i;  
	 printf("%d", k+1);
	 while(k != j)   //输出路径从起点直至终点  
	 {  
          printf("-->%d", path[k][j]+1);  
		  k = path[k][j];  
     }  
}

int main()
{
	int n;
	int i, j;
	while(scanf("%d", &n) != EOF){
		if(n == 0) break;
		intial(n);
		for(i = 0; i < n; i ++)
			for(j = 0; j < n; j ++){
				int temp = 0;
				scanf("%d", &temp);
				if(temp != -1) graph[i][j] = temp;
			}
		for(i = 0; i < n; i ++)
			scanf("%d", &v[i]);
		
		Floyd(n);
		int x, y;
		while(scanf("%d %d", &x, &y) != EOF){ 
			if(x == -1 && y == -1) break;
			printf("From %d to %d :\n", x, y);
			printf("Path: ");
			print_path(x-1, y-1);
			printf("\nTotal cost : %d\n\n", graph[x-1][y-1]);
		}
		for(i = 0; i < n; i ++){
			for(j = 0; j < n; j ++)
				printf("%d ", path[i][j]);
				printf("\n");
		}
	}
	return 0;
}
*/

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

const int Max = 500;
const int inf = 0x3f3f3f3f;
int graph[Max][Max];
int v[Max];
int path[Max][Max];
// 前驱矩阵

void intial(int n)
{
	int i, j;  
    for(i = 0; i < n; i++)  
        for(j = 0; j < n; j++)  
            if(i == j) graph[i][j] = 0;  
            else graph[i][j] = inf;  

}
// refer to introduction to algorithm 

void Floyd(int n)
{
	int len;
	int i, j, k;
	for(k = 0; k < n; k ++){
		for(i = 0; i < n; i ++){
			for(j = 0; j < n; j ++){
				len =  graph[i][k] + graph[k][j] + v[k];
				if(len < graph[i][j]){
					graph[i][j] = len;
					path[i][j] = path[k][j];
				}
				else if(len == graph[i][j]){
					if(path[i][j] > path[k][j]) 
						//判断是否为字典顺序  
                       path[i][j] = path[k][j];  	
				}
			}
		}
	}
}

void print_path(int i, int j)
{
	
	if(i == j) printf("%d", i+1);
	else if(path[i][j] == -1) printf("no path\n");
	else {
		print_path(i, path[i][j]);
		printf("-->%d", j+1);
	}
}

int main()
{
	int n;
	int i, j;
	while(scanf("%d", &n) != EOF){
		if(n == 0) break;
		intial(n);
		for(i = 0; i < n; i ++)
			for(j = 0; j < n; j ++){
				int temp = 0;
				scanf("%d", &temp);
				if(temp != -1) graph[i][j] = temp;
			}

		for(i = 0; i < n; i ++){
			for(j = 0; j < n; j ++){
				if(i == j || graph[i][j] == inf) path[i][j] = 0;
				if(i != j && graph[i][j] < inf) path[i][j] = i;
			}	
		}

		for(i = 0; i < n; i ++)
			scanf("%d", &v[i]);
		
		Floyd(n);
		int x, y;
		while(scanf("%d %d", &x, &y) != EOF){ 
			if(x == -1 && y == -1) break;
			printf("From %d to %d :\n", x, y);
			printf("Path: ");
			print_path(x-1, y-1);
			printf("\nTotal cost : %d\n\n", graph[x-1][y-1]);
		}
			for(i = 0; i < n; i ++){
			for(j = 0; j < n; j ++)
				printf("%d ", path[i][j]);
				printf("\n");
		}
	}
	return 0;
}
