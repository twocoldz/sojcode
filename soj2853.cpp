#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
const int N=20005;
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
char g[105][205];
int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        Init();
        scanf("%d%d",&n,&m);
        getchar();
        int nm=n*m;
        for(int i=0;i<n;i++)
            gets(g[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(g[i][j*2]=='1')
                {
                    //printf("%d %d %d\n",i,j,i*m+j+1);
                    AddEdge(0,i*m+j+1,1,0);
                    AddEdge(i*m+j+1+nm,nm+nm+1,1,0);
                    int x,y;
                    for(int k=0;k<4;k++)
                    {
                        x=i+dx[k],y=j+dy[k];
                        if(x<0||x>=n||y<0||y>=m||g[x][y*2]=='0')
                            continue;
                        AddEdge(i*m+j+1,x*m+y+1+nm,1,0);
                        //printf("%d %d %d\n",x,y,x*m+y+1);
                    }
                }
            }
        }
        printf("%d\n",Dinic(0,nm+nm+1));
    }
    return 0;
}
