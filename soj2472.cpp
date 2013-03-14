#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct E
{
    int v,nxt;
}edge[250010];
int head[505];
struct node
{
    int h;
    char sex;
    char mu[105],hi[105];
}g[505],b[505];
int mk[505];
int fit[505][505];
bool vis[505];
int n,e;

void Init()
{
    e=0;
    memset(head,-1,sizeof(head));
}

inline void AddEdge(int u,int v)
{
    edge[e].v=v;
    edge[e].nxt=head[u];
    head[u]=e++;
}

bool Hungary(int u)
{
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(!vis[v])
        {
            vis[v]=1;
            if(mk[v]==-1||Hungary(mk[v]))
            {
                mk[v]=u;
                return true;
            }
        }
    }
    return false;
}

inline bool Judge(int i,int j)
{
    if(abs(g[i].h-b[j].h)>40)
        return 0;
    //if(p[i].sex==p[j].sex)
    //    return 0;
    if(strcmp(g[i].mu,b[j].mu))
        return 0;
    if(strcmp(g[i].hi,b[j].hi)==0)
        return 0;
    return 1;
}


int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d",&n);
        Init();
        //memset(fit,0,sizeof(fit));
        int h;
        char sex;
        int numg=0,numb=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d %c",&h,&sex);
            if(sex=='F')
            {
                numg++;
                g[numg].h=h;
                g[numg].sex=sex;
                scanf("%s %s",g[numg].mu,g[numg].hi);
            }
            else
            {
                numb++;
                b[numb].h=h;
                b[numb].sex=sex;
                scanf("%s %s",b[numb].mu,b[numb].hi);
            }
        }
        for(int i=1;i<=numg;i++)
        {
            for(int j=1;j<=numb;j++)
            {
                if(Judge(i,j))
                {
                    AddEdge(i,j);
                }
            }
        }
        /*for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                if(Judge(i,j))
                {
                    //fit[i][j]=fit[j][i]=1;
                    AddEdge(i,j);
                    AddEdge(j,i);
                }
            }
            */
        memset(mk,-1,sizeof(mk));
        int ans=0;
        for(int i=1;i<=numg;i++)
        {
            memset(vis,0,sizeof(vis));
            if(Hungary(i))
                ans++;
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
