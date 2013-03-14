#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define inf 0x3f3f3f3f

using namespace std;
struct node
{
    int v,nxt;
}edge[50000];
int head[205],dis[205];
bool vis[205];
int n,e;
int ans;

void Init()
{
    e=0;
    memset(head,-1,sizeof(head));
}

void AddEdge(int u,int v)
{
    edge[e].v=v;
    edge[e].nxt=head[u];
    head[u]=e++;
}

char dir[205][12];
char st[15],en[15];

bool Judge(char a[],char b[])
{
    int k=0;
    for(int i=0;a[i];i++)
    {
        if(a[i]!=b[i])
        {
            k++;
            if(k>1)
                return false;
        }
    }
    return k==1;
}

int GetPos(char s[])
{
    int lens=strlen(s);
    for(int i=0;i<=n;i++)
    {
        if(strlen(dir[i])==lens)
        {
            int j;
            for(j=0;s[j];j++)
            {
                if(s[j]!=dir[i][j])
                    break;
            }
            if(j==lens)
                return i;
        }
    }
}

bool Spfa()
{
    int S=GetPos(st);
    int E=GetPos(en);
    //printf("poss=%d pose=%d\n",S,E);
    for(int i=0;i<=n;i++)
        dis[i]=inf,vis[i]=0;;
    dis[S]=0;
    queue<int> q;
    q.push(S);
    vis[S]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];~i;i=edge[i].nxt)
        {
            int v=edge[i].v;
            if(dis[u]+1<dis[v])
            {
                dis[v]=dis[u]+1;
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    if(dis[E]==inf)
        return false;
    else
    {
        ans=dis[E];
        return true;
    }
}

int main()
{
    int i=0;
    Init();
    while(scanf("%s",dir[i]))
    {
        if(dir[i][0]=='*')
            break;
        i++;
    }
    n=i;
    for(i=0;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int lena=strlen(dir[i]);
            int lenb=strlen(dir[j]);
            if(lena==lenb&&Judge(dir[i],dir[j]))
            {
                //printf("%d <--> %d\n",i,j);
                AddEdge(i,j);
                AddEdge(j,i);
            }
        }
    }
    while(scanf("%s%s",st,en)!=EOF)
    {
        int lena=strlen(st);
        int lenb=strlen(en);
        if(lena==lenb&&Spfa())
            printf("%s %s %d\n",st,en,ans);
        else
            printf("Impossible\n");
    }
    return 0;
}
