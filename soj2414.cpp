#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
const int dx[]={0, 0, -1, 1, 0, 0, -1, -1, 1, 1, -2, 2, 0, 0, -1, -1, -2, -2, -3, 1, 1, 2, 2, 3,
           0, 0, -1, -1, -2, -2, -3, -3, -4, 1, 1, 2, 2, 3, 3, 4};
const int dy[]={1, -1, 0, 0, -2, 2, -1, 1, -1, 1, 0, 0, -3, 3, -2, 2, -1, 1, 0, -2, 2, -1, 1, 0,
           -4, 4, -3, 3, -2, 2, -1, 1, 0, 3, -3, 2, -2, 1, -1, 0};
const int N=1005;
struct node
{
    int v,f,nxt;
}edge[2000005];
int head[N],q[N],dis[N],h,r;
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
    q[++r]=s;
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

int g[22][22];
int num[22][22];
char f[22][22];
char str[22];
int main()
{
    int cases;
    scanf("%d",&cases);
    for(int id=1;id<=cases;id++)
    {
        Init();
        int d,k,cnt=0;
        scanf("%d %d",&n,&d);
        if(d == 0)  k = -1;
        else if(d == 1) k = 3;
        else if(d == 2) k = 11;
        else if(d == 3) k = 23;
        else    k = 39;
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            for(int j=0;str[j];j++)
            {
                g[i][j]=str[j]-'0';
                if(g[i][j])
                    num[i][j]=++cnt;
            }
        }
        m=strlen(str);
        int s=0,t=cnt*2+1;
        int num_L=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            for(int j=0;str[j];j++)
            {
                if(str[j]=='L')
                    AddEdge(s,num[i][j],1,0),num_L++;
                if(g[i][j])
                {
                    if(i<d||i+d>=n||j<d||j+d>=m)
                        AddEdge(num[i][j]+cnt,t,inf,0);
                    AddEdge(num[i][j],num[i][j]+cnt,g[i][j],0);
                    for(int l=0;l<=k;l++)
                    {
                        int x=i+dx[l];
                        int y=j+dy[l];
                        if(x<0||x>=n||y<0||y>=m||g[x][y]==0)
                            continue;
                        AddEdge(num[i][j]+cnt,num[x][y],inf,0);
                    }
                }
            }
        }
        int ans=num_L-Dinic(s,t);
        printf("Case #%d: ",id);
        if(ans == 0)
            printf("no lizard was left behind.\n");
        else if(ans == 1)
            printf("1 lizard was left behind.\n");
        else
            printf("%d lizards were left behind.\n", ans);
    }
    return 0;
}
