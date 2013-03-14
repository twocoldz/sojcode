/*
#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
int map[255][255];
int pre[255],f[255];
int c[255][255];
int q[255],h,rear;
int mk[505];
bool vis[505];
int n,n1,m,e;

struct node
{
    int v,nxt,w;
}edge[100005];
int head[255];

void AddEdge(int u,int v,int w)
{
    edge[e].v=v;
    edge[e].w=w;
    edge[e].nxt=head[u];
    head[u]=e++;
    edge[e].v=u;
    edge[e].w=0;
    edge[e].nxt=head[v];
    head[v]=e++;
}

bool Bfs(int s,int t,int mid)
{
    memset(pre,0xff,sizeof(pre));
    memset(f,inf,sizeof(f));
    h=rear=0;
    q[++rear]=s;
    pre[s]=s;
    while(rear>h)
    {
        int u=q[++h];
        for(int i=0;i<=t;i++)
        {
            if(pre[i]==-1&&c[u][i]>0)
            {
                pre[i]=u;
                q[++rear]=i;
                f[i]=min(f[u],c[u][i]);
                if(i==t)
                    return true;
            }
        }
    }
    return 0;
}

bool Judge(int s,int t,int mid)
{
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++)
    {
        c[0][i]=m;
        for(int j=n+1;j<=n+n1;j++)
            if(map[i][j]<=mid)
                c[i][j]=1;
    }
    for(int i=n+1;i<=n+n1;i++)
    {
            c[i][n+n1+1]=1;
    }
    int ans=0;
    while(Bfs(s,t,mid))
    {
        ans+=f[t];
        int i=t;
        while(i!=s)
        {
            int v=pre[i];
            c[v][i]-=f[t];
            c[i][v]+=f[t];
            i=v;
        }
    }
    return (ans>=n1);
}*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
const int MAXN=255;
const int MAXM=100005;
struct node
{
    int u,v,nxt,f;
}edge[MAXM];
int map[255][255];
int head[MAXN];
int q[MAXN],h,r;
int dis[MAXN];
int n,e,m,n1;

void Init()
{
    e=0;
    memset(head,-1,sizeof(head));
}

void AddEdge(int u,int v,int w)
{
    edge[e].u=u;
    edge[e].v=v;
    edge[e].f=w;
    edge[e].nxt=head[u];
    head[u]=e++;

    edge[e].u=v;
    edge[e].v=u;
    edge[e].f=0; //Notion
    edge[e].nxt=head[v];
    head[v]=e++;
}

int Dinic(int s,int t)
{
    int ans=0;
    while(true)
    {
        int id,i;
        h=r=0;
        memset(dis,0xff,sizeof(dis));
        q[r++]=s;
        dis[s]=0;
        while(h<r)
        {
            id=q[h++];
            //printf("id=%d\n",id);
            for(i=head[id];~i;i=edge[i].nxt)
            {
                int v=edge[i].v;
                if(edge[i].f>0&&dis[v]==-1)
                {
                    dis[v]=dis[edge[i].u]+1;
                    q[r++]=v;
                    //printf("%d ",v);
                    if(v==t)
                    {
                        h=r;
                        break;
                    }
                }
            }
        }
        if(dis[t]==-1)
            break;
        id=s,r=0;
        while(true)
        {
            if(id==t)
            {
                int flow=inf,bkn; //break node record the path where will be break
                for(i=0;i<r;i++)
                {
                    if(edge[q[i]].f<flow)
                    {
                        bkn=i;
                        flow=edge[q[i]].f;
                    }
                }
                for(i=0;i<r;i++)
                {
                    edge[q[i]].f-=flow;
                    edge[q[i]^1].f+=flow;
                }
                ans+=flow;
                r=bkn;
                id=edge[q[bkn]].u;
            }
            for(i=head[id];~i;i=edge[i].nxt)
            {
                int v=edge[i].v;
                if(edge[i].f>0&&dis[v]==dis[edge[i].u]+1)
                    break;
            }
            if(i!=-1)
            {
                q[r++]=i;
                id=edge[i].v;
            }
            else
            {
                if(r==0)
                    break;
                dis[edge[q[r-1]].v]=-1;
                id=edge[q[--r]].u;
            }
        }
    }
    return ans;
}

bool Judge(int s,int t,int mid)
{
    Init();
    for(int i=1;i<=n;i++)
        AddEdge(0,i,m);
    for(int i=n+1;i<=n+n1;i++)
        AddEdge(i,t,1);
    for(int i=1;i<=n;i++)
        for(int j=n+1;j<=n1+n;j++)
            if(map[i][j]<=mid)
                AddEdge(i,j,1);

    int ans=Dinic(s,t);
    return ans>=n1;
}


int main()
{
    while(scanf("%d%d%d",&n,&n1,&m)==3)
    {
        memset(map,0,sizeof(map));
        for(int i=1;i<=n+n1;i++)
            for(int j=1;j<=n+n1;j++)
            {
                scanf("%d",map[i]+j);
                if(i!=j&&map[i][j]==0)
                    map[i][j]=inf;
            }
        for(int k=1;k<=n+n1;k++)
            for(int i=1;i<=n+n1;i++)
                for(int j=1;j<=n+n1;j++)
                    if(map[i][j]>map[i][k]+map[k][j])
                        map[i][j]=map[i][k]+map[k][j];

        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=n+1;j<=n+n1;j++)
                if(map[i][j]>ans)
                    ans=map[i][j];
        int l=1,r=ans;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(Judge(0,n+n1+1,mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
