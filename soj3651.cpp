#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int dx[8]={-1,-1,0,1,1,1,0,-1};
const int dy[8]={0,1,1,1,0,-1,-1,-1};
struct node
{
    int x, y;
};
queue<node> q;
char map[755][755];
//ool vis[755][755];
int n,m,tmp;

bool Check(node a)
{
    if(a.x<0||a.x>=m||a.y<0||a.y>=n)
        return false;
    return true;
}

void Bfs(node h)
{
    q.push(h);
    node t,tt;
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        for(int i=0;i<8;i++)
        {
            tt.x=t.x+dx[i],tt.y=t.y+dy[i];
            if(Check(tt)&&map[tt.x][tt.y]=='.')
            {
                map[tt.x][tt.y]='*';
                q.push(tt);
                tmp++;
            }
        }
    }
}

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0;i<m;i++)
            scanf("%s",map[i]);
        //memset(vis,0,sizeof(vis));
        int ans=0;
        node t;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(map[i][j]=='.')
                {
                    tmp=1;
                    map[i][j]='*';
                    t.x=i,t.y=j;
                    Bfs(t);
                    ans=max(tmp,ans);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
