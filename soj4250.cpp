#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool dp[50005];
int a[205];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int L,R,n,sum=0;
        scanf("%d",&n);
        scanf("%d",&L);
        for(int i=1;i<=n;i++)
            scanf("%d",a+i),a[i]=-a[i],sum+=a[i];
        scanf("%d",&R);
        if(R+L<sum)
        {
            printf("Lazy Power\n");
            continue;
        }
        if(R>=sum)
        {
            printf("%d\n",n+1);
            continue;
        }
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        int Mi=0;
        int k,f=1;
        for(int i=1;f&&i<=n;i++)
        {
            for(int j=Mi;f&&j>=0;j--)
            {
                if(dp[j]&&j+a[i]<=L)
                {
                    dp[j+a[i]]=1;
                    Mi=max(Mi,j+a[i]);
                    if(sum-j-a[i]<=R)
                    {
                        f=0;
                        k=i;
                        //printf("i=%d j+a[i]=%d\n",i,j+a[i]);
                    }
                }
            }
        }
        if(!f)
            printf("%d\n",k*2+n+1);
        else
            printf("Lazy Power\n");
    }
    return 0;
}
