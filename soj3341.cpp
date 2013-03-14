#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

#define inf 0x3f3f3f3f
using namespace std;

int N,S,T;
struct Les
{
    int b,l,a;
}les[10005];
int Mi[105];
int dp[10005][105];

bool cmp(Les x,Les y)
{
    if(x.b==y.b)
        return x.l<y.l;
    return x.b<y.b;
}

int main()
{
    while(scanf("%d%d%d",&T,&S,&N)==3)
    {
        int x,y;
        memset(Mi,inf,sizeof(Mi));
        for(int i=0;i<S;i++)
            scanf("%d%d%d",&les[i].b,&les[i].l,&les[i].a);
        for(int i=0;i<N;i++)
        {
            scanf("%d%d",&x,&y);
            Mi[x]=min(Mi[x],y);
        }
        for(int i=1;i<=100;i++)
            Mi[i]=min(Mi[i-1],Mi[i]);
        sort(les,les+S,cmp);
        memset(dp,-1,sizeof(dp));
        dp[0][1]=0;
        int c=0,ans=0;
        for(int i=0;i<=T;i++)
        {
            while(c<S&&les[c].b<i)
                c++;
            for(int j=1;j<=100;j++)
            {
                if(dp[i][j]==-1)
                    continue;
                ans=max(ans,dp[i][j]);
                if(i<T)
                    dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
                if(c<S&&les[c].b==i&&i+les[c].l<=T)
                    dp[i+les[c].l][les[c].a]=max(dp[i+les[c].l][les[c].a],dp[i][j]);
                if(Mi[j]<inf&&i+Mi[j]<=T)
                    dp[i+Mi[j]][j]=max(dp[i+Mi[j]][j],dp[i][j]+1);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
