#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;
double x[10],y[10];
double dis[10][10];
double dp[8][1<<8];

inline double min(double a,double b)
{
    return a<b?a:b;
}

void Dis(int i,int j)
{
    double t=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
    dis[i][j]=dis[j][i]=sqrt(t);
}

inline void Init()
{
    for(int i=0;i<(1<<8);i++)
    {
        for(int j=0;j<8;j++)
        {
            dp[j][i]=inf;
        }
    }
    for(int i=0;i<8;i++)
    {
        dp[i][1<<i]=dis[i][9];
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf",&x[9],&y[9],&x[8],&y[8]);
        for(int i=0;i<8;i++)
        {
            scanf("%lf%lf",x+i,y+i);
        }
        for(int i=0;i<10;i++)
        {
            dis[i][i]=0;
            for(int j=i+1;j<10;j++)
            {
                Dis(i,j);
            }
        }
        Init();

        for(int i=1;i<(1<<8);i++)
        {
            for(int j=0;j<8;j++)
            {
                if(i&(1<<j))
                {
                    for(int k=0;k<8;k++)
                    {
                        if(!(i&(1<<k)))
                        {
                            dp[k][i^(1<<k)]=min(dp[j][i]+dis[j][k],dp[k][i^(1<<k)]);
                        }
                    }
                }
            }
        }

        double ans=inf;
        for(int i=0;i<8;i++)
        {
            ans=min(ans,dp[i][(1<<8)-1]+dis[i][8]);
        }
        ans+=dis[8][9];
        printf("%.3lf\n",ans);
    }
    return 0;
}
