#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f
using namespace std;
const int N=5005;
struct node
{
    int u,v,nxt;
}edge[100005];
int head[N];
int dfn[N],low[N],indeg[N];
int stack[N],fa[N],wh[N],c[N];
int w[N];
bool ins[N];
int top,n,e,m,cnt,num;

void Init()
{
    e=0;
    memset(head,-1,(n+1)*sizeof(head[0]));
}

void AddEdge(int u,int v)
{
    edge[e].u=u;
    edge[e].v=v;
    edge[e].nxt=head[u];
    head[u]=e++;
}

void tarjan(int u)
 {
     int i,j;
     dfn[u]=low[u]=++num;
     stack[++top]=u;
     ins[u]=1;
     for(i=head[u];~i;i=edge[i].nxt)
     {
         int v=edge[i].v;
         //printf("u=%d v=%d\n",u,v);
         if(!dfn[v])
         {
             tarjan(v);
             low[u]=min(low[u],low[v]);
         }
         else if(ins[v])
             low[u]=min(dfn[v],low[u]);
     }
     //printf("u=%d dfn[u]=%d low[u]=%d\n",u,dfn[u],low[u]);
     if(dfn[u]==low[u])
     {
         cnt++;
         do
         {
             j=stack[top--];
             wh[j]=cnt;
             ins[j]=0;
             c[cnt]=min(c[cnt],w[j]);
         } while(j!=u);
     }

 }

void Cal()
{
    num=cnt=top=0;
    for(int i=1;i<=n;i++)
        c[i]=inf;
    memset(dfn,0,(n+1)*sizeof(dfn[0]));
    memset(low,0,(n+1)*sizeof(low[0]));
    memset(ins,0,(n+1)*sizeof(ins[0]));
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])
            tarjan(i);
    }
}

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        Init();
        int a,b;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            w[a]=b;
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            AddEdge(a,b);
        }
        Cal();
        int ans=0;
        //for(int i=1;i<=n;i++)
        //{
        //    printf("i=%d dfn[i]=%d low[i]=%d wh[i]=%d\n",i,dfn[i],low[i],wh[i]);
        //}
        for(int i=1;i<=cnt;i++)
        {
            indeg[i]=0;
        }
        for(int i=0;i<m;i++)
        {
            a=edge[i].u;
            b=edge[i].v;
            if(wh[a]!=wh[b])
            {
                indeg[wh[b]]++;
            }
        }
        for(int i=1;i<=cnt;i++)
        {
            if(!indeg[i])
                ans+=c[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
