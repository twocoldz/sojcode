#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
bool pri[1005];
long long  dp[1005];

void Init()
{
    memset(pri,1,sizeof(pri));
    memset(dp,0,sizeof(dp));
    pri[2]=1,pri[1]=0;
    for(int i=2;i<=1000;i++)
    {
        if(pri[i])
        {
            for(int j=i+i;j<=1000;j+=i)
            {
                pri[j]=0;
            }
        }
    }
    dp[0]=1;
    for(int i=2;i<=1000;i++)
    {
        if(pri[i])
        {
            for(int j=i;j<=1000;j++)
            {
                dp[j]+=dp[j-i];
            }
        }
    }
    for(int i=2;i<=1000;i++)
    {
        if(pri[i])
            dp[i]--;
    }
}

int main()
{
    int n;
    Init();
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d",&n);
        printf("%lld\n",dp[n]);
    }
}
