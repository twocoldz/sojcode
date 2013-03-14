#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int x[3005],y[3005],s[3005];
vector<int> map[3005];
int n,T,m;

inline int Sqr(int x)
{
    return x*x;
}

bool IsReach(int k)
{
    return Sqr(x[k]-x[0])+Sqr(y[k]-y[0])<=Sqr(T*s[k]);
}

int dx[3005],dy[3005];
int mx[3005],my[3005];
int q[3005*2];
bool HK_Bfs(int n,int m)
{
    bool f=0;
    int head=0,rear=0;
    for(int i=1;i<=m;i++)
        dy[i]=0;
    for(int i=1;i<=n;i++)
    {
        dx[i]=0;
        if(mx[i]==-1)
            q[rear++]=i;
    }

    while(head!=rear)
    {
        int u=q[head++];
        for(int i=0;i<map[u].size();i++)
        {
            int v=map[u][i];

            if(!dy[v])
            {
                dy[v]=dx[u]+1;
                if(my[v]==-1)
                    f=1;
                else
                {
                    dx[my[v]]=dy[v]+1;
                    q[rear++]=my[v];
                }
            }
        }
    }
    return f;
}

bool HK_Dfs(int u)
{
    for(int i=0;i<map[u].size();i++)
    {
        int v=map[u][i];
        if(dy[v]==dx[u]+1)
        {
            dy[v]=0;
            if(my[v]==-1||HK_Dfs(my[v]))
            {
                my[v]=u;
                mx[u]=v;
                return true;
            }
        }
    }
    return false;
}

int H_K(int n,int m)
{
    int ans=0;
    for(int i=1;i<=n;i++)
        mx[i]=-1;
    for(int i=1;i<=m;i++)
        my[i]=-1;
    while(HK_Bfs(n,m))
    {
        for(int i=1;i<=n;i++)
            if(mx[i]==-1&&HK_Dfs(i))
                ans++;
    }
    return ans;
}

int main()
{
    int cases;
    scanf("%d",&cases);
    for(int id=1;id<=cases;id++)
    {
        scanf("%d",&T);
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",x+i,y+i,s+i),map[i].clear();
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",x,y);
            for(int j=1;j<=n;j++)
            {
                if(IsReach(j))
                    map[j].push_back(i);
            }
        }
        printf("Scenario #%d:\n%d\n\n",id,H_K(n,m));

    }
}


/*
    H_KËã·¨Ä£°å
    author£º twocoldz
    Date£º 2013/2/1

    dx[],dy[],mx[],my[];
    vector map[][];

    bool HK_Bfs(int n,int m)
    {
        bool f=0;
        int head=0,rear=0;
        for(int i=1;i<=m;i++)
            dy[i]=0;
        for(int i=1;i<=n;i++)
        {
            dx[i]=0;
            if(mx[i]==-1)
                q[rear++]=i;
        }

        while(head!=rear)
        {
            int u=q[head++];
            for(int i=0;i<map[u].size();i++)
            {
                int v=map[u][i];

                if(!dy[v])
                {
                    dy[v]=dx[u]+1;
                    if(my[v]==-1)
                        f=1;
                    else
                    {
                        dx[my[v]]=dy[v]+1;
                        q[rear++]=my[v];
                    }
                }
            }
        }
        return f;
    }

    bool HK_Dfs(int u)
    {
        for(int i=0;i<map[u].size();i++)
        {
            int v=map[u][i];
            if(dy[v]==dx[u]+1)
            {
                dy[v]=0;
                if(my[v]==-1||HK_Dfs(my[v]))
                {
                    my[v]=u;
                    mx[u]=v;
                    return true;
                }
            }
        }
        return false;
    }

    int H_K(int n,int m)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
            mx[i]=-1;
        for(int i=1;i<=m;i++)
            my[i]=-1;
        while(HK_Bfs(n,m))
        {
            for(int i=1;i<=n;i++)
                if(mx[i]==-1&&HK_Dfs(i))
                    ans++;
        }
        return ans;
    }

*/
