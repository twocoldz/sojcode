#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int nxt,v;
}edge[6005];
int head[6005];
int p[6005];
int a[6005];
int dp[6005][2];
int n,e;

void Init()
{
    e=0;
    memset(head,-1,sizeof(head));
    memset(p,0,sizeof(p));
    memset(dp,0,sizeof(dp));
    memset(edge,-1,sizeof(edge));
}

void AddEdge(int a,int b)
{
    edge[e].v=b;
    edge[e].nxt=head[a];
    head[a]=e++;
}

void Dfs(int v)
{
    dp[v][0]=0;
    dp[v][1]=a[v];
    for(int i=head[v];~i;i=edge[i].nxt)
    {
        int t=edge[i].v;
        if(t==p[v])
            continue;
        Dfs(t);
        dp[v][0]+=max(dp[t][0],dp[t][1]);
        dp[v][1]+=dp[t][0];
    }
}

int main()
{
    while(scanf("%d",&n)==1&&n)
    {
        Init();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
        }
        int a,b;
        while(scanf("%d%d",&a,&b)&&(a+b))
        {
            if(!p[a])
                p[a]=b;
            AddEdge(b,a);
        }
        for(int i=1;i<=n;i++)
        {
            if(!p[i])
            {
                Dfs(i);
                printf("%d\n",max(dp[i][0],dp[i][1]));
                break;
            }
        }
    }
    return 0;
}
