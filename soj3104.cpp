#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

////此题需要用大数处理 暂为完成

using namespace std;
int a[81];
int d[81][81];
int n,m;

void dp()
{
    memset(d,0,sizeof(d));
    for(int i=m;i>=1;i--)
    {
        d[i][i]=a[i]*pow(2,m);
        for(int j=1+i;j<=m;j++)
        {
            d[i][j]=max(d[i][j-1]+a[j]*pow(2,m-j+i),d[i+1][j]+a[i]*pow(2,m-j+i));
        }
    }
}

int main()
{
    printf("%lld\n",pow(2,80));
    for(int i=1;i<=80;i++)
    {
        printf("%lf\n",pow(2,i));
    }
    while(scanf("%d%d",&n,&m)==2)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",a+j);
            }
            dp();
            ans+=d[1][m];
        }
        printf("%d\n",ans);
    }
    return 0;
}
