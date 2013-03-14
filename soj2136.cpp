#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int n,m;
int son[205],bro[205],app[205];
int dp[205][205];

void Dfs(int t)
{
    dp[t][0]=0;
    dp[t][1]=app[t];
    //printf("t=%d son[t]=%d\n",t,son[t]);
    for(int i=son[t];i!=-1;i=bro[i])
    {
        int v=i;
        //system("PAUSE");
        Dfs(v);
        for(int j=m;j>=2;j--)
        {
            for(int k=j-1;k>=0;k--)
            {
                dp[t][j]=max(dp[t][j],dp[t][j-k]+dp[v][k]);
                //printf("dp[%d][%d]=%d\n",t,j,dp[t][j]);
            }
        }
        //printf("bro[%d]=%d\n",i,bro[i]);
    }
}

int  main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        int x,y;
        m++;
        memset(son,-1,sizeof(son));
        memset(bro,-1,sizeof(bro));
        memset(dp,0,sizeof(dp));
        app[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            app[i]=x;
            bro[i]=son[y];
            son[y]=i;
        }

        /*for(int i=0;i<=n;i++)
        {
            printf("son[%d]=%d\n",i,son[i]);
            printf("bro[%d]=%d\n",i,bro[i]);
        }
        printf("========\n");*/
        Dfs(0);
        printf("%d\n",dp[0][m]);
    }
    return 0;
}
