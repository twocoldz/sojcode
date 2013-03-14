#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
int num[17];
long long dp[(1<<16)][16];  //dp[i][j]状态为i 对m取摸为j的状态
bool vis[10];
int n,m;

long long   Dp(int state,int mod)
{
    if(dp[state][mod]!=-1)
        return dp[state][mod];
     dp[state][mod]=0;
    int  i,j,k;
    for(i=0;i<n;i++)
     {
        int f=1;
        if(state&(1<<i))
         {
            for(j=i-1;j>=0&&f;j--)
             {
                if(((state&(1<<j)))&&num[i]==num[j])
                 {
                     f=0;

                 }
             }

            if(f)
             {
                for(k=0;k<m;k++)
                 {
                    if((k*10+num[i])%m==mod)
                     {
                        int temp_state=state^(1<<i);
                         dp[state][mod]+=Dp(temp_state,k);
                     }
                 }
             }


         }
     }
    return dp[state][mod];
}

int main()
{
    int t;
    scanf("%d",&t);
    char c[20];
    while(t--)
    {
        scanf("%s %d",c,&m);
        for(int i=0;c[i];i++)
        {
            num[i]=c[i]-'0';
            //printf("%d ",num[i]);
        }
        //puts("");
        n=strlen(c);
        sort(num,num+n);
        memset(dp,0xff,sizeof(dp));
        dp[0][0]=1;
        Dp((1<<n)-1,0);
        printf("%lld\n",dp[(1<<n)-1][0]);
    }
    return 0;
}

/*
for(int i=0;i<(1<<n);i++)
        {
            for(int j=0;j<m;j++)
            {
                memset(vis,false,sizeof(vis));
                for(int k=0;k<n;k++)
                {
                    int tt=i^(1<<k);
                    if((tt&i)==i&&!vis[num[k]])
                    {
                        vis[num[k]]=true;
                        dp[tt][((j*10)+num[k])%m]+=dp[i][j];
                    }
                }
            }
        }
*/
