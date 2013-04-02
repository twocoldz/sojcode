#include <cstdio>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f3f
using namespace std;
const int N=10005;
struct node
{
    int v,f,nxt;
}edge[1000005];
int head[N];
int dis[N],q[N],h,r;
int n,m,e;

void Init()
{
    e=0;
    memset(head,-1,sizeof(head));
}

void AddEdge(int u,int v,int w,int rw)
{
    edge[e].v=v;
    edge[e].f=w;
    edge[e].nxt=head[u];
    head[u]=e++;

    edge[e].v=u;
    edge[e].f=rw;
    edge[e].nxt=head[v];
    head[v]=e++;
}

bool Bfs(int s,int t)
{
    memset(dis,0xff,sizeof(dis));
    h=r=0;
    q[++r];
    dis[s]=0;
    while(h<r)
    {
        int u=q[++h];
        for(int i=head[u];~i;i=edge[i].nxt)
        {
            int v=edge[i].v;
            if(dis[v]==-1&&edge[i].f>0)
            {
                dis[v]=dis[u]+1;
                q[++r]=v;
                if(v==t)
                    return true;
            }
        }
    }
    return false;
}

int Dfs(int s,int t,int limit)
{
    if(s==t)
        return limit;
    int cost=0;
    for(int i=head[s];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(dis[s]+1==dis[v]&&edge[i].f>0)
        {
            int tmp=Dfs(v,t,min(limit-cost,edge[i].f));
            if(tmp>0)
            {
                cost+=tmp;
                edge[i].f-=tmp;
                edge[i^1].f+=tmp;
            }
            if(cost==limit)
                break;
        }
    }
    if(cost==0)
        dis[s]=-1;
    return cost;
}

int Dinic(int s,int t)
{
    int ans=0;
    while(Bfs(s,t))
        ans+=Dfs(s,t,inf);
    return ans;
}

int a[105][105];
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        Init();
        int s=0,t=n*m+1,sum=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",a[i]+j);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                sum+=a[i][j];
                if((i+j)%2)
                    AddEdge(i*m+j+1,t,a[i][j],0);
                else
                {
                    AddEdge(s,i*m+j+1,a[i][j],0);
                    for(int k=0;k<4;k++)
                    {
                        int x=i+dx[k],y=j+dy[k];
                        if(x<0||x>=n||y<0||y>=m)
                            continue;
                        AddEdge(i*m+j+1,x*m+y+1,inf,0);
                    }
                }
            }
        printf("%d\n",sum-Dinic(s,t));
    }
    return 0;
}
