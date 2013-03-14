#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;
int w[21],pos[1<<20];
int ord[21];
int dp[1<<20];
int cnt[1<<20];

inline void Init()
{
    for(int i=0;i<(1<<20);i++)
    {
        cnt[i]=0;
        int ii=i;
        while(ii)
        {
            cnt[i]+=ii%2;
            ii/=2;
        }
    }
}

int main()
{
    int t;
    Init();
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",w+i);
        }
        int x;
        for(int i=0;i<n;i++)
        {
            ord[i]=0;
            for(int j=0;j<n;j++)
            {
                scanf("%d",&x);
                if(x)
                {
                    //printf("%d\n",(1<<j));
                    ord[i]^=(1<<j);
                    //printf("%d\n",ord[i]);
                }
            }
        }
        memset(dp,inf,sizeof(dp));
        dp[0]=0;
        for(int i=0;i<(1<<n);i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!(i&(1<<j)))
                {
                    if((i&(ord[j]))==0)
                    {
                        int tt=i|(1<<j);
                        if(dp[tt]>dp[i]+w[j]*(n-cnt[i]-1))
                        {
                            dp[tt]=dp[i]+w[j]*(n-cnt[i]-1);
                            pos[tt]=j;
                            //printf("pos[%d]=%d\n",tt,pos[tt]);
                            continue;
                        }
                        else if(dp[tt]==dp[i]+w[j]*(n-cnt[i]-1)&&j<pos[tt])
                        {
                            pos[tt]=j;
                            //printf("pos[%d]=%d\n",tt,pos[tt]);
                        }
                    }
                }
            }
        }
        if(dp[(1<<n)-1]==inf)
        {
            printf("-1\n-1\n");
        }
        else
        {
            printf("%d\n",dp[(1<<n)-1]);
            int i=(1<<n)-1;
            printf("%d",pos[i]);
            while((i^=(1<<pos[i]))>0)
            {
                printf(" %d",pos[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
