#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
struct node
{
    int v,nxt,w;
}edge[3000];
const int N=105;
int head[N];
struct P
{
    int x,y;
}red[N],blue[N];
int mk[N];
bool vis[N];
int n,e,m,K;

void Init()
{
    e=0;
    memset(head,-1,sizeof(head));
}

void AddEdge(int u,int v,int w)
{
    edge[e].v=v;
    edge[e].w=w;
    edge[e].nxt=head[u];
    head[u]=e++;
}

inline int Dis(int i,int j)
{
    return ceil(sqrt((red[i].x-blue[j].x)*(red[i].x-blue[j].x)+(red[i].y-blue[j].y)*(red[i].y-blue[j].y)));
}

bool Hungary(int u,int len)
{
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(!vis[v]&&edge[i].w<=len)
        {
            vis[v]=1;
            if(mk[v]==-1||Hungary(mk[v],len))
            {
                mk[v]=u;
                return true;
            }
        }
    }
    return false;
}

bool Judge(int len)
{
    int ans=0;
    memset(mk,-1,sizeof(mk));
    for(int i=0;i<n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(Hungary(i,len))
            ans++;
        if(ans>=K)
            return true;
    }
    return false;
}

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        m=n=0;
        int x,y,p;
        Init();
        char str[5];
        scanf("%d%d",&p,&K);
        for(int i=0;i<p;i++)
        {
            scanf("%d %d %s",&x,&y,str);
            if(str[0]=='r')
            {
                red[n].x=x;
                red[n++].y=y;
            }
            else
            {
                blue[m].x=x;
                blue[m++].y=y;
            }
        }
        if(n<K||m<K)
        {
            printf("Impossible\n");
            continue;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                AddEdge(i,j,Dis(i,j));
            }
        }
        int l=0,r=1500;
        int ans;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(Judge(mid))
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
