#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;
int a[1005];
int f[2][1005],g[1005];  //f表示以第j小的数为标准
int n;

void Init()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            f[i][j]=inf;
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            g[i]=a[i];
        }
        int r=0;
        sort(g+1,g+1+n);
        int m=unique(g+1,g+1+n)-g-1;
        f[0][1]=abs(a[1]-g[1]);
        //printf("f[0][1]=%d\n",f[0][1]);
        for(int i=2;i<=m;i++)
        {
            f[0][i]=min(f[0][i-1],abs(a[1]-g[i]));
            //printf("f[0][%d]=%d\n",i,f[0][i]);
        }
        for(int i=2;i<=n;i++)
        {
            r^=1;
            f[r][1]=f[r^1][1]+abs(a[i]-g[1]);
            for(int j=2;j<=m;j++)
            {
                f[r][j]=f[r][j-1];
                f[r][j]=min(f[r][j],f[r^1][j]+abs(a[i]-g[j]));
                //printf("f[%d][%d]=%d\n",r,j,f[r][j]);
            }
        }
        printf("%d\n",f[r][m]);
    }
    return 0;

}
