#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int f[502][502];    //前i个中选择j个需要的盒子数
int g[502][502];    //前i个中选择j个剩余的体积
int a[502];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,v;
        scanf("%d%d%d",&n,&m,&v);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
        }
        int ans=0;
        f[0][0]=g[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            f[i][0]=g[i][0]=0;
            for(int j=1;j<=i;j++)
            {
                if(g[i-1][j-1]>=a[i])
                {
                    g[i][j]=g[i-1][j-1]-a[i];
                    f[i][j]=f[i-1][j-1];
                }
                else
                {
                    g[i][j]=v-a[i];
                    f[i][j]=f[i-1][j-1]+1;
                }
            }
            if(f[i][i]<=m)
            {
                //printf("%d\n",f[i][i]);
                ans=i;
            }

            for(int j=1;j<i;j++)
            {
                if(f[i-1][j]<f[i][j])
                {
                    f[i][j]=f[i-1][j];
                    g[i][j]=g[i-1][j];
                }
                else if(f[i-1][j]==f[i][j]&&g[i-1][j]>g[i][j])
                {
                    g[i][j]=g[i-1][j];
                }
                if(f[i][j]<=m&&j>ans)
                {
                    //printf("%d\n",f[i][j]);
                    ans=j;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
