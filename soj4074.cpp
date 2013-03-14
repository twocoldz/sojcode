#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int u,v,nxt;
}edge[10005];
int head[105],dfn[105],low[105];
int stack[105],wh[105];
int indeg[105],outdeg[105];
bool ins[105];
int n,e,m,cnt,num,top;

void Init()
{
    e=0;
    memset(head,-1,sizeof(head));
}

void AddEdge(int u,int v)
{
    edge[e].v=v;
    edge[e].u=u;
    edge[e].nxt=head[u];
    head[u]=e++;
}

void tarjan(int u)
{
    dfn[u]=low[u]=++num;
    stack[++top]=u;
    ins[u]=1;
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(!dfn[v])
        {
            tarjan(v);
            if(low[v]<low[u])
                low[u]=low[v];
        }
        else if(ins[v]&&dfn[v]<low[u])
        {
            low[u]=dfn[v];
        }
    }
    if(low[u]==dfn[u])
    {
        int j;
        cnt++;
        do
        {
            j=stack[top--];
            wh[j]=cnt;
            ins[j]=0;
        }while(j!=u);
    }
}

void Cal()
{
    memset(dfn,0,(n+1)*sizeof(dfn[0]));
    memset(low,0,(n+1)*sizeof(low[0]));
    memset(ins,0,(n+1)*sizeof(ins[0]));
    top=cnt=num=0;
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
}

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        Init();
        int a,b;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            AddEdge(a,b);
        }
        Cal();
        //for(int i=1;i<=n;i++)
        //    printf("i=%d dfn[i]=%d low[i]=%d wh[i]=%d\n",i,dfn[i],low[i],wh[i]);
        memset(indeg,0,(cnt+1)*sizeof(indeg[0]));
        memset(outdeg,0,(cnt+1)*sizeof(outdeg[0]));
        for(int i=0;i<e;i++)
        {
            int u=edge[i].u;
            int v=edge[i].v;
            if(wh[u]!=wh[v])
            {
                indeg[wh[v]]++;
                outdeg[wh[u]]++;
            }
        }
        int ans1=0,ans2=0;
        for(int i=1;i<=cnt;i++)
        {
            if(!indeg[i])
                ans1++;
            if(!outdeg[i])
                ans2++;
        }
        printf("%d\n",max(ans1,ans2));
    }
    return 0;
}
