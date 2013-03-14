#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,tt;
unsigned s[100],suit[60];  //suit[i]表示对于单行来说 所有可能的状态
int dp[2][60][60],count[60]; //count为对应的suit[i]状态各放置了多少个炮台

inline bool Cleck(int x)
{
    if((x&(x<<1))||(x&(x<<2)))  //3个之内不存在1
        return false;
    return true;
}

inline int max(int a,int b)
{
    return a>b?a:b;
}

void Init()
{
    tt=0;
    int i,j;
    for(i=0;i<1024;i++)
         if(Cleck(i))
         {
             suit[tt++]=i;
             //printf("suit[%d]=%d\n",tt-1,i);
         }

     for(i=0;i<tt;i++)
     {
         count[i]=0;
         for(j=0;j<10;j++)
             if(suit[i]&(1<<j))
             {
                 count[i]++;
             }
          //printf("count[%d]=%d\n",i,count[i]);
     }

}

int main()
{
    Init();
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        int i,j,k,l,r;
        char str[11];
        for(i=0;i<n;i++)
        {
            s[i]=0;
            scanf("%s",str);
            for(j=0;j<m;j++)
            {
                if(str[j]=='P')
                    s[i]|=(1<<j);
            }
            //printf("%d\n",s[i]);
        }
        memset(dp,-1,sizeof(dp));
        for(i=0;i<tt;i++)
        {
            if((s[0]&suit[i])==suit[i])
            {
                for(j=0;j<tt;j++)
                {
                    dp[0][i][j]=count[i];
                    //printf("dp[0][%d][%d]=%d\n",i,j,dp[0][i][j]);
                }
            }
        }
        r=0;
        for(i=1;i<n;i++)
        {
            r^=1;
            for(j=0;j<tt;j++)
            {
                if((s[i]&suit[j])==suit[j])
                {
                    for(k=0;k<tt;k++)
                    {
                        if((s[i-1]&suit[k])==suit[k]&&(suit[j]&suit[k])==0)
                        {
                            for(l=0;l<tt;l++)
                            {
                                if((dp[r^1][k][l]!=-1)&&((suit[j]&suit[l])==0))
                                {
                                    dp[r][j][k]=max(dp[r][j][k],dp[r^1][k][l]+count[j]);
                                    //printf("dp[%d][%d][%d]=%d\n",r,j,k,dp[r][j][k]);
                                }
                            }
                        }
                    }
                }
            }
        }

        int ans=0;
        for(i=0;i<tt;i++)
        {
            for(j=0;j<tt;j++)
            {
                ans=max(ans,dp[r][i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
