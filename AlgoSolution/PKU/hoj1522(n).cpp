#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int data[100005];
int sum[100005];
int que[100005];
int dp[100005];
int maxn(int a, int b) { return a > b ? a : b; }

int main()
{
  int n, m;
  //freopen("in.txt", "r", stdin);
  while(scanf("%d%d", &n, &m) != EOF){
    sum[0] = 0;
    for(int i = 1; i <= n; i ++){
      scanf("%d", &data[i]);
      sum[i] = sum[i-1] + data[i];
    }
    memset(que, 0, sizeof(que));
    memset(dp, 0, sizeof(dp));
/*
    int front , rear;
    front = 0, rear = -1;
    // ͷָ���βָ��
    dp[0] = -0x3f3f3f3f;
    for(int i = 1; i <= n; i ++){
      while(front <= rear && que[front] < i-m)
        // i-m���Ƴ���Ϊm
        front ++;
        // ������
      while(front <= rear && sum[i-1] < sum[que[rear]])
        // �����ֵӦ�ñȶ�β��Ԫ�ش�
        rear --;

      que[++rear] = i-1;
      dp[i] = maxn(dp[i-1], sum[i]-sum[que[front]]);
      cout << front << " " << rear << endl;
      for(int i = front; i <= rear; i ++)
      cout << sum[que[i]] << endl;
    }
    cout << dp[n] << endl;
*/

  int front ,rear;
  front = 0;
  rear = -1;
  dp[0] = -0x3f3f3f3f;
  for(int i = 1; i <= n; i ++){
    while(front <= rear && que[front] < i-m)
      front ++;

    while(front <= rear && sum[i-1] < sum[que[rear]])
      rear --;
    //�����ֵҪ�ȶ�β��
    que[++rear] = i-1;

    dp[i] = maxn(dp[i-1], sum[i]-sum[que[front]]);
  }
    cout << dp[n] << endl;
  }
  return 0;
}
