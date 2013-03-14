#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f
using namespace std;
int dis[505][505];
int a[505];

int main()
{
    int n,m,p;
    while(scanf("%d%d%d",&n,&p,&m)==3)
    {
        for(int i=0;i<p;i++)
        {
            scanf("%d",a+i);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                dis[i][j]=inf;
            dis[i][i]=0;
        }

        int s,e,w;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&s,&e,&w);
            dis[s][e]=w;
            dis[e][s]=w;
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(dis[i][j]>dis[i][k]+dis[k][j])
                        dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
        int ans=inf;
        int pos;
        int t;
        for(int i=1;i<=n;i++)
        {
            t=0;
            for(int j=0;j<p;j++)
            {
                t+=dis[i][a[j]];
            }
            if(t<ans)
            {
                ans=t;
                pos=i;
            }
        }
        printf("%d\n",pos);
    }
    return 0;
}
