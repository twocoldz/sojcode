#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node
{
    int c,k,p;
}pro[5];

int fi[1000],a[6],k[6],t[6];
int dp[6][6][6][6][6];

int main()
{
    int n,m;
    a[0]=1;
    for(int i=1;i<=5;i++)
    {
        a[i]=a[i-1]*6;
    }
    while(scanf("%d",&n)!=EOF)
    {
        memset(pro,0,sizeof(pro));
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&pro[i].c,&pro[i].k,&pro[i].p);
            fi[pro[i].c]=i;
        }

        dp[0][0][0][0][0]=0;
        int x0,x1,x2,x3,x4;
        for(x0=0;x0<=pro[0].k;x0++)
        {
            for(x1=0;x1<=pro[1].k;x1++)
            {
                for(x2=0;x2<=pro[2].k;x2++)
                {
                    for(x3=0;x3<=pro[3].k;x3++)
                    {
                        for(x4=0;x4<=pro[4].k;x4++)
                        {
                            dp[x0][x1][x2][x3][x4]=x0*pro[0].p+x1*pro[1].p+x2*pro[2].p+x3*pro[3].p+x4*pro[4].p;
                        }
                    }
                }
            }
        }

        scanf("%d",&m);
        int t0,t1,t2,t3,t4;
        for(int i=0;i<m;i++)
        {
            int num;
            scanf("%d",&num);
            memset(k,0,sizeof(k));
            for(int j=0;j<num;j++)
            {
                scanf("%d%d",&x0,&x1);
                k[fi[x0]]=x1;
            }
            int disc;
            scanf("%d",&disc);
            for(x0=0;x0<=pro[0].k;x0++)
            {
                if((t0=x0-k[0])>=0)
                {
                    for(x1=0;x1<=pro[1].k;x1++)
                    {
                        if((t1=x1-k[1])>=0)
                        {
                            for(x2=0;x2<=pro[2].k;x2++)
                            {
                                if((t2=x2-k[2])>=0)
                                {
                                    for(x3=0;x3<=pro[3].k;x3++)
                                    {
                                        if((t3=x3-k[3])>=0)
                                        {
                                            for(x4=0;x4<=pro[4].k;x4++)
                                            {
                                                if((t4=x4-k[4])>=0)
                                                {
                                                    if(dp[x0][x1][x2][x3][x4]>dp[t0][t1][t2][t3][t4]+disc)
                                                        dp[x0][x1][x2][x3][x4]=dp[t0][t1][t2][t3][t4]+disc;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

            }
        }
        printf("%d\n",dp[pro[0].k][pro[1].k][pro[2].k][pro[3].k][pro[4].k]);
    }
    return 0;
}
