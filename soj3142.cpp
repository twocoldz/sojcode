#include <stdio.h>
#include <string.h>

#define modd 1000000007
int dp[5][21][21][21][21][21];
int num[6];

int Dp(int x)
{
    int &t=dp[x][num[1]][num[2]][num[3]][num[4]][num[5]];
    if(t!=-1)
        return t;
    t=0;
    for(int i=5;i>=1;i--)
    {
        if(num[i])
        {
            int temp=num[i]--;
            num[x]++;
            t=(t+(long long)temp*(long long)(Dp(i-1)))%modd;
            num[x]--;
            num[i]++;
        }
    }
    return t;
}

int main()
{
    int n,k;
    memset(dp,-1,sizeof(dp));
    dp[0][0][0][0][0][0]=1;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(num,0,sizeof(num));
        num[k]=n;
        printf("%d\n",Dp(0));
    }
    return 0;
}
