#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dis[105][105];
int r[10005];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0;i<m;i++)
            scanf("%d",r+i);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",dis[i]+j);
            }
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(dis[i][k]+dis[k][j]<dis[i][j])
                        dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
        long long ans=0;
        for(int i=1;i<m;i++)
            ans+=dis[r[i-1]][r[i]];
        printf("%lld\n",ans);
    }
    return 0;
}
