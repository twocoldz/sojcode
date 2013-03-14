#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long sum[50005];
long long mod[1000005];

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n,d;
        scanf("%d%d",&d,&n);
        memset(mod,0,d*(sizeof(mod[0])));
        sum[0]=0;
        for(int i=1;i<=n;i++)
            scanf("%lld",sum+i),sum[i]+=sum[i-1];
        for(int i=0;i<=n;i++)
            mod[sum[i]%d]++;

        long long ans=0;
        for(int i=0;i<d;i++)
        {
            if(mod[i]!=0&&mod[i]!=1)
                ans+=(mod[i]*(mod[i]-1))>>1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
