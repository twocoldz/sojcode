#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int v[11],w[11];
bool vis[11];
struct node
{
    int w,v;
}s[2];
int n,m,ans;

void Dfs(int used,int res,int t)
{
    if(used==n)
    {
        if(s[1].v>ans)
        {
            ans=s[1].v;
        }
        return ;
    }
    if(s[1].v+res<=ans)
        return ;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            s[t].w+=w[i];
            s[t].v+=v[i];
            if(s[t].w-s[t^1].w>m)
            {
                Dfs(used+1,res-v[i],t^1);
            }
            else
            {
                Dfs(used+1,res-v[i],t);
            }
            vis[i]=0;
            s[t].w-=w[i];
            s[t].v-=v[i];
        }
    }
}

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        int sum=0;
        ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",w+i,v+i);
            sum+=v[i];
        }
        memset(vis,0,sizeof(vis));
        Dfs(0,sum,0);
        printf("%d\n",ans);
    }
    return 0;
}
