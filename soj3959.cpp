#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int dx[12]={1,0,-1,0,-2,-1,1,2,2,1,-1,-2};
const int dy[12]={0,1,0,-1,1,2,2,1,-1,-2,-2,-1};
struct node
{
    int x,y,step;
    int f,w; //f==0表示没有转换 w=0表示为rook 1为knight
}ss,ee;
bool vis[102][102][2][2];
char map[102][102];
int n,m;

bool Judge(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m||map[x][y]=='#')
        return false;
    return true;
}

bool Is(int x,int y)
{
    if(x==ee.x&&y==ee.y)
        return true;
    return false;
}

int Bfs()
{
    memset(vis,0,sizeof(vis));
    queue<node> q;
    node t,v;
    ss.w=0;
    ss.f=0;
    q.push(ss);
    ss.w=1;
    q.push(ss);
    vis[ss.x][ss.y][0][0]=vis[ss.x][ss.y][1][0]=1;
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        v.step=t.step+1;
        if(t.w==0)
        {
            v.f=t.f;
            v.w=t.w;
            for(int i=0;i<4;i++)
            {
                v.x=t.x;
                v.y=t.y;
                while(true)
                {
                    v.x+=dx[i];
                    v.y+=dy[i];
                    //v.step=t.step+1;
                    if(Judge(v.x,v.y))
                    {
                        if(Is(v.x,v.y))
                            return v.step;
                        if(!vis[v.x][v.y][v.w][v.f])
                        {
                            vis[v.x][v.y][v.w][v.f]=1;
                            q.push(v);
                        }
                    }
                    else
                        break;
                }
            }
            if(t.f==0)
            {
                v.f=1;
                v.w^=1;
                for(int i=4;i<12;i++)
                {
                    v.x=t.x+dx[i];
                    v.y=t.y+dy[i];
                    //v.step=t.step+1;
                    //printf("x=%d y=%d step=%d\n",v.x,v.y,v.step);
                    if(Is(v.x,v.y))
                            return v.step;
                    if(Judge(v.x,v.y)&&!vis[v.x][v.y][v.w][v.f])
                    {
                        vis[v.x][v.y][v.w][v.f]=1;
                        q.push(v);
                    }
                }
            }
        }
        else
        {
            v.f=t.f;
            v.w=t.w;
            for(int i=4;i<12;i++)
            {
                v.x=t.x+dx[i];
                v.y=t.y+dy[i];
                //v.step=t.step+1;
                if(Is(v.x,v.y))
                    return v.step;
                if(Judge(v.x,v.y)&&!vis[v.x][v.y][v.w][v.f])
                {
                    vis[v.x][v.y][v.w][v.f]=1;
                    q.push(v);
                }
            }
            if(t.f==0)
            {
                v.f=1;
                v.w^=1;
                for(int i=0;i<4;i++)
                {
                    v.x=t.x;
                    v.y=t.y;
                    while(true)
                    {
                        v.x+=dx[i];
                        v.y+=dy[i];
                        //v.step=t.step+1;
                        if(Judge(v.x,v.y))
                        {
                            if(Is(v.x,v.y))
                                return v.step;
                            if(!vis[v.x][v.y][v.w][v.f])
                            {
                                vis[v.x][v.y][v.w][v.f]=1;
                                q.push(v);
                            }
                        }
                        else
                            break;
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    int cases;
    scanf("%d",&cases);
    for(int id=1;id<=cases;id++)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%s",map[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(map[i][j]=='s')
                {
                    ss.x=i;
                    ss.y=j;
                    ss.step=0;
                }
                if(map[i][j]=='t')
                {
                    ee.x=i;
                    ee.y=j;
                }
            }
        printf("Case #%d: %d\n",id,Bfs());
    }
    return 0;
}
