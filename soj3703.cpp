#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int dx[4]={0,0,-1,1};
const int dy[4]={1,-1,0,0};
bool vis[105][105];
int map[105][105];
int n,m;

inline bool Is(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m)
        return false;
    return true;
}

void Dfs(int x,int y,int h)
{
    if(Is(x,y)&&!vis[x][y]&&map[x][y]<=h)
    {
        vis[x][y]=1;
        map[x][y]=0;
        for(int i=0;i<4;i++)
        {
            Dfs(x+dx[i],y+dy[i],h);
        }
    }
}

void Dfs2(int x,int y)
{
    if(Is(x,y)&&!vis[x][y]&&map[x][y])
    {
        vis[x][y]=1;
        for(int i=0;i<4;i++)
        {
            Dfs2(x+dx[i],y+dy[i]);
        }
    }
}

bool Check(int h)
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<m;i++)
        if(!vis[0][i])
            Dfs(0,i,h);
    for(int i=0;i<m;i++)
        if(!vis[n-1][i])
            Dfs(n-1,i,h);
    for(int i=0;i<n;i++)
        if(!vis[i][0])
            Dfs(i,0,h);
    for(int i=0;i<n;i++)
        if(!vis[i][m-1])
            Dfs(i,m-1,h);
    memset(vis,0,sizeof(vis));
    int t=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j]&&map[i][j])
            {
                t++;
                Dfs2(i,j);
            }
        }
    if(t>1)
        return true;
    else
        return false;
}

int main()
{
    int cases=1;
    while(scanf("%d%d",&n,&m)&&(n+m))
    {
        int M=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",map[i]+j);
                M=max(M,map[i][j]);
            }
        }
        int ans=-1;
        for(int i=1;i<=M;i++)
        {
            if(Check(i))
            {
                ans=i;
                break;
            }
        }
        if(ans==-1)
        {
            printf("Case %d: Island never splits.\n",cases++);
        }
        else
        {
            printf("Case %d: Island splits when ocean rises %d feet.\n",cases++,ans);
        }
    }
    return 0;
}
