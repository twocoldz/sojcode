#include <cstdio>
#include <cstring>
#include <cstdio>

#define min(a,b) a<b?a:b

using namespace std;

int f[2005];
int dp[2005];
char str[2005];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        int ans=0,j=1;
        int m=n*2-1;
        for(int i=0;i<=(m+1);i++)
        {
            f[i]=0;     //标记最基础的三角形是正还是倒
            f[i+1]=1;
        }
        while(n--)
        {
            scanf("%s",&str[j]);
            for(int i=j;i<=m;i+=2)
            {
                if(str[i]=='O')
                {
                    if(f[i]==1)
                        dp[i]=min(f[i-1],f[i+1])+1;
                    else
                        dp[i]=1;
                }
                else
                {
                    dp[i]=0;
                }
                if(dp[i]>ans)
                    ans=dp[i];
                if(str[i+1]=='O')
                    dp[i+1]=1;
                else
                    dp[i+1]=0;
            }

            for(int i=j;i<=m;i++)
            {
                f[i]=dp[i];
                printf("%d ",f[i]);
            }
            printf("\n");
            j++;
            m--;
        }
        printf("%d\n",ans*ans);
    }
    return 0;
}
