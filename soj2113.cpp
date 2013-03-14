#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int a[105];
int dpma[55][12];
int dpmi[55][12];
int n,m;
int sum[55][55];

void getsum(int k)
{
    for(int i=1;i<=n;i++)
    {
        sum[i][i]=(a[i+k]+10010)%10;

    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            sum[i][j]=(sum[i][j-1]+sum[j][j])%10;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i&&j<=m;j++)
        {
            dpma[i][j]=0;
            dpmi[i][j]=0x3f3f3f3f;
        }
    }
    for(int i=1;i<=n;i++)
    {
        dpma[i][1]=dpmi[i][1]=sum[1][i];
    }
}

int main()
{

    while(scanf("%d%d",&n,&m)!=EOF&&n)
    {
        int total=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            total+=(a[i]+10010)%10;
            a[i+n]=a[i];
        }
        int ma=0,mi=0x7fffffff;
        if(m==1)
        {
            printf("%d\n",total%10);
            printf("%d\n",total%10);
            continue;
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                getsum(i);
                for(int j=2;j<=n;j++)
                {
                    for(int k=2;k<=j&&k<=m;k++)
                    {
                        for(int l=j-1;l>=k-1;l--)
                        {
                            dpma[j][k]= max( dpma[j][k] , dpma[l][k-1] * sum[l+1][j]);
                            dpmi[j][k]= min( dpmi[j][k] , dpmi[l][k-1] * sum[l+1][j]);
                        }
                    }
                }
                ma=max(ma,dpma[n][m]);
                mi=min(mi,dpmi[n][m]);
            }
        }
        printf("%d\n",mi);
        printf("%d\n",ma);
    }
    return 0;
}
