#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;
int x[505],c[505],w[505];
int g[505][255];
int f[505][255];
int n,r,m;

void Init()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            g[i][j]=f[i][j]=inf;
        }
    }
}

int main()
{
    while(scanf("%d%d%d",&n,&m,&r)==3)
    {
        int i,j,k;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d%d",x+i,w+i,c+i);
        }
        Init();
        g[0][0]=f[0][0]=0;
         for(i=1;i<=n;i++)
         {
             f[i][0]=f[i-1][0]+w[i];
             if(i<=m)
             {
                 f[i][i]=f[i-1][i-1]+c[i];
                 g[i][i]=g[i-1][i-1]+c[i];
             }
             for(j=1;j<i&&j<=m;j++)
             {
                 for(k=i-1;k>=j-1&&x[i]-x[k+1]<=r;k--)
                     g[i][j]=min(f[k][j-1]+c[i],g[i][j]);
                 f[i][j]=f[i-1][j]+w[i];
                 for(k=i;k>=j&&x[i]-x[k]<=r;k--)
                     f[i][j]=min(g[k][j],f[i][j]);
             }
         }
        int ans=inf;
        for(int i=0;i<=m&&i<=n;i++)
        {
            ans=min(ans,f[n][i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
