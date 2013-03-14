#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;
const int N=10005;
struct node
{
    int v,nxt;
}edge[N*2];
int n,L,ans,e;
int head[N],size[N],facost[N];
int dp[N][105],tmp[N][105][2],longest[N][105];

void AddEdge(int u,int v)
{
    edge[e].v=v;
    edge[e].nxt=head[u];
    head[u]=e++;
}

void Dfs1(int fa,int v)
{
    size[v]=1;
    dp[v][0]=0;
    //printf("fa=%d->v=%d\n",fa,v);
    for(int i=head[v];~i;i=edge[i].nxt)
    {
        int t=edge[i].v;
        if(t==fa)
            continue;
        Dfs1(v,t);
        size[v]+=size[t];
        dp[v][0]+=dp[t][0]+size[t];
    }
}

void Dfs2(int fa,int u)
{
    if(fa!=-1)
        facost[u]=(facost[fa]+n-size[u])+(dp[fa][0]-dp[u][0]-size[u]);
    else
        facost[u]=0;
    dp[u][1]=dp[u][0];
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(v==fa)
            continue;
        Dfs2(u,v);
        int tt=dp[u][0]-dp[v][0]-size[v];

        if(tmp[u][1][0]>dp[v][1]-dp[v][0]-size[v])
        {
            tmp[u][1][1]=tmp[u][1][0];
            tmp[u][1][0]=dp[v][1]-dp[v][0]-size[v];
            longest[u][1]=v;
        }
        else if(tmp[u][1][1]>dp[v][1]-dp[v][0]-size[v])
            tmp[u][1][1]=dp[v][1]-dp[v][0]-size[v];
        for(int k=2;k<=L;k++)
        {
            dp[u][k]=min(dp[u][k],dp[v][k-1]+tt);
            if(tmp[u][k][0]>dp[v][k]-dp[v][0]-size[v])
            {
                tmp[u][k][1]=tmp[u][k][0];
                tmp[u][k][0]=dp[v][k]-dp[v][0]-size[v];
                longest[u][k]=v;
            }
            else if(tmp[u][k][1]>dp[v][k]-dp[v][0]-size[v])
                tmp[u][k][1]=dp[v][k]-dp[v][0]-size[v];
        }
    }
    for(int k=1;k<L-1;k++)
    {
        if(longest[u][k]!=longest[u][L-1-k])
            ans=min(ans,dp[u][0]+facost[u]+tmp[u][k][0]+tmp[u][L-1-k][0]);
        else
        {
            ans=min(ans,dp[u][0]+facost[u]+tmp[u][k][0]+tmp[u][L-1-k][1]);
            ans=min(ans,dp[u][0]+facost[u]+tmp[u][k][1]+tmp[u][L-1-k][0]);
        }
    }

    for(int i=2;i<=L;i++)
        dp[u][i]=min(dp[u][i],dp[u][i-1]);
    ans=min(ans,dp[u][L]+facost[u]);
    //printf("ans=%d\n",ans);
}

void Init()
{
    e=0;
    memset(dp,inf,sizeof(dp));
    memset(tmp,inf,sizeof(tmp));
    memset(head,-1,sizeof(head));
}

int main()
{
    //int cases;
    //scanf("%d",&cases);
    //while(cases--)
    while(scanf("%d%d",&n,&L)==2&&n+L)
    {

        L++;
        Init();
        int a,b;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            AddEdge(a,b);
            AddEdge(b,a);
        }
        Dfs1(-1,0);
        ans=inf;
        facost[0]=0;
        Dfs2(-1,0);
        printf("%d\n",ans);

    }
    return 0;
}
