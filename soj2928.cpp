#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;
int a[105];
int dp[10100];
bool sto[10100];

int main()
{
    int L;
    while(scanf("%d",&L)==1)
    {
        int s,l,n;
        scanf("%d%d%d",&s,&l,&n);
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        if(s==l)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
                if(a[i]%s==0)
                    ans++;
            printf("%d\n",ans);
            continue;
        }
        a[0]=0;
        sort(a+1,a+1+n);
        memset(sto,0,sizeof(sto));
        int tmp=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]-a[i-1]>20)
            {
                tmp+=20;
            }
            else
                tmp+=(a[i]-a[i-1]);
            sto[tmp]=1;
        }
        memset(dp,inf,sizeof(dp));
        dp[0]=0;
        for(int i=s;i<=tmp+l;i++)
        {
            for(int j=s;j<=l;j++)
            {
                dp[i]=min(dp[i],dp[i-j]+sto[i]);
            }
        }
        int ans=inf;
        for(int i=tmp;i<=tmp+l;i++)
            ans=min(ans,dp[i]);
        printf("%d\n",ans);
    }
    return 0;
}
