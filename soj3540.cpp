#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;
int dp[2005][2005];
int bp[2005],sp[2005],bl[2005],sl[2005];
int q[2005],val[2005];

int main()
{
    int n,Lim,W;
    memset(dp,-inf,sizeof(dp));
	while(scanf("%d", &n)==1)
    {
        scanf("%d%d",&Lim,&W);
        int ans = 0;
        int ap,bp,as,bs;
        for (int i = 1; i < n + 1; ++i)
        {
            scanf("%d%d%d%d", &ap, &bp, &as, &bs);
            for (int j = 0; j < as + 1; ++j)
                dp[i][j] = -ap * j;
            for( int j=as+1;j<= Lim;j++)
                dp[i][j] = -inf;
            for (int j = 0; j < Lim + 1; ++j)
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            int t = i - W - 1;
            if (t >= 0)
            {
                int head=0;
                int rear=0;
                for (int j = 0; j < Lim + 1; ++j)
                {
                    while (head < rear && q[head] < j - as)
                        ++head;
                    while (head < rear && dp[t][j] + j * ap >= val[rear - 1])
                        --rear;
                    val[rear] = dp[t][j] + j * ap;
                    q[rear++] = j;
                    if (head < rear)
                        dp[i][j] = max(dp[i][j], val[head] - j * ap);
                }
                head=rear=0;
                for (int j = Lim; j > -1; --j)
                {
                    while (head < rear && q[head] > j + bs)
                        ++head;
                    while (head < rear && dp[t][j] + j * bp >= val[rear - 1])
                        --rear;
                    val[rear] = dp[t][j] + j * bp;
                    q[rear++] = j;
                    if (head < rear)
                        dp[i][j] = max(dp[i][j], val[head] - j * bp);
                }
            }
            ans = max(dp[i][0], ans);
        }
        printf("%d\n", ans);
    }
	return 0;
}
