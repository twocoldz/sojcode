#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define  max(a,b) (a>b?a:b)
int n,m,E,head[105],vis[105],dp[105][105];
struct node
 {
   int v,next,w;
 }edge[105];
inline void add(int u, int v, int w)
 {
   edge[E].v=v;
   edge[E].w=w;
   edge[E].next=head[u];
   head[u]=E++;
 }
void dfs(int u)
 {
     int i,k,ans=0,s[2],vv[2];
     vis[u]=1;
     for(i=head[u];~i;i=edge[i].next)
     {
         int v=edge[i].v;
         if(!vis[v])
         {
             s[ans]=v;
             vv[ans]=edge[i].w;
             vis[v]=1;
             ans++;
             dfs(v);
         }
     }
    if(ans==2)
     {
      dp[u][1]=max(vv[0],vv[1]);
      for(k=2;k<=m;k++)
      {
        dp[u][k]=max(dp[u][k],vv[0]+dp[s[0]][k-1]);
        dp[u][k]=max(dp[u][k],vv[1]+dp[s[1]][k-1]);
        for(i=0;i<=k-2;i++)
         dp[u][k]=max(dp[u][k],vv[0]+dp[s[0]][i]+dp[s[1]][k-i-2]+vv[1]);

      }
     }
 }
int main()
 {
     int i;
     while(scanf("%d%d",&n,&m)==2)
     {
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        E=0;
        int u,v,w;
        for(i=1;i<n;i++)
        {
         scanf("%d%d%d",&u,&v,&w);
         add(u,v,w);
         add(v,u,w);
        }
         dfs(1);
         printf("%d\n",dp[1][m]);
     }
    return 0;
 }
