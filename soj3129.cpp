#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

double c[10][10];    //c[i][j]表示第i位（从高到低）在第j轮取得正确取值的概率
double dp[10][1<<8];  //dp[i][j]表示在第i轮，取得正确的状态为j的情况的概率 所以最后的结果是sum{dp[1--n][1<<n-1]}
char s[11];
int len[10];
int n;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int maxlen=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            len[i]=strlen(s);
            maxlen=max(maxlen,len[i]);
        }

        for(int i=0;i<=n;i++)
        {
            int j;
            for(j=1;j<=len[i];j++)
            {
                c[i][j]=1.0/(double)(len[i]-j+1);
                //printf("c[%d][%d]=%.3lf\n",i,j,c[i][j]);
            }
            for(;j<=maxlen;j++)
            {
                c[i][j]=0.0;
            }
        }

        for(int i=1;i<(1<<n);i++)
        {
            dp[1][i]=1.0;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                    dp[1][i]*=c[j][1];
                else
                    dp[1][i]*=(1-c[j][1]);
            }
        }
        double ans=dp[1][(1<<n)-1];
        //printf("%.3lf\n",ans);
        double tmp;
        bool f;
        for(int i=2;i<=maxlen;i++)
        {
            for(int j=1;j<(1<<n);j++)              //这和之前的状态DP不太一样 不是从J状态变为其他状态 ，而是反过来
            {
                dp[i][j]=0.0;
                for(int k=1;k<(1<<n)-1;k++)
                {
                    if(((j&k)==k)&&(j^k)>0)
                    {
                        //从k状态到j状态可能不仅仅需要增加一位所以，还需要一次循环
                        f=false;
                        tmp=dp[i-1][k];
                        for(int l=0;l<n;l++)
                        {
                            if(((1<<l)&k)==0)
                            {
                                if((1<<l)&j)
                                    tmp*=c[l][i];
                                else
                                    tmp*=(1-c[l][i]);
                                //printf("i=%d j=%d\n",i,j);
                            }
                            else
                            {
                                f|=(len[l]>=i-1);           //只要j状态从k状态变过来中有一位是取上i次还有可能取到的，就需要加上这个概率
                            }
                        }
                        if(f)
                        {
                            dp[i][j]+=tmp;
                        }
                    }
                }
            }
            ans+=dp[i][(1<<n)-1];
        }
        printf("%0.3lf\n",ans);
    }
    return 0;
}
