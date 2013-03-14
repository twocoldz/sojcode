#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 1000000000

using namespace std;
int N,L,B;

struct node
{
    int x,w,c,f;
}a[10003];

bool cmp(node a,node b)
{
    return a.x<b.x;
}

int dp[1005][1005],m[1005];

void Init()
{
    for(int i=0;i<=B;i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<=L;i++)
    {
        for(int j=1;j<=B;j++)
        {
            dp[i][j]=-inf;
        }
    }
}

int main()
{
    while(scanf("%d%d%d",&L,&N,&B)!=EOF)
    {
        for(int i=1;i<=N;i++)
        {
            scanf("%d%d%d%d",&a[i].x,&a[i].w,&a[i].f,&a[i].c);
        }
        sort(a+1,a+1+N,cmp);
        Init();
        for(int i=1;i<=N;i++)
        {
            int t=a[i].x+a[i].w;
            for(int j=B;j>=a[i].c;j--)
            {
                if(dp[t][j]<dp[t-a[i].w][j-a[i].c]+a[i].f)
                {
                    dp[t][j]=dp[t-a[i].w][j-a[i].c]+a[i].f;
                }
            }
        }
        if(dp[L][B]>0)
            printf("%d\n",dp[L][B]);
        else
            printf("-1\n");
    }
    return 0;
}
