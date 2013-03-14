#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
long long dp[102][102][21];
int xx[6]={-1,-1,0,0,1,1};
int yy[6]={-1,0,-1,1,0,1};

long long dfs(int x,int y,int k)
{
    if(dp[x][y][k]!=-1)
        return dp[x][y][k];
    dp[x][y][k]=0;
    for(int i=0;i<6;i++)
    {
        dp[x][y][k]+=dfs(x+xx[i],y+yy[i],k-1);
    }
    return dp[x][y][k];
}

inline void Init()
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            dp[i][j][0]=0;
        }
    }
}

int main()
{
    int t;
    memset(dp,-1,sizeof(dp));
    Init();
    dp[50][50][0]=1;
    scanf("%d",&t);
    while(t--)
    {
        int x;
        scanf("%d",&x);
        printf("%lld\n",dfs(50,50,x));
    }
    return 0;
}
