#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>

#define inf 0x3f3f3f3f

using namespace std;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
struct node
{
    int x,y;
}p1,p2,p3;
deque<node> w,W,f;
int a[1002][1002],b[1002][1002],c[1002][1002];
char map[1005][1005];
int n,m;

bool Check(node a)
{
    if(a.x<0||a.x>=n||a.y<0||a.y>=m)
        return false;
    return true;
}

void Bfs()
{
    w.push_back(p1),f.push_back(p2),W.push_back(p3);
    while(!w.empty()||!f.empty()||!W.empty())
    {
        int len=w.size();
        node t,tt;
        for(int i=0;i<len;i++)
        {
            t=w.front();
            w.pop_front();
            for(int j=0;j<4;j++)
            {
                tt.x=t.x+dx[j],tt.y=t.y+dy[j];
                if(Check(tt)&&(a[tt.x][tt.y]==-1))
                {
                    if(map[tt.x][tt.y]=='#')
                    {
                        a[tt.x][tt.y]=a[t.x][t.y]+1;
                        w.push_back(tt);
                    }
                    else
                    {
                        w.push_front(tt);
                        a[tt.x][tt.y]=a[t.x][t.y];
                    }
                }
            }
        }
        len=f.size();
        for(int i=0;i<len;i++)
        {
            t=f.front();
            f.pop_front();
            for(int j=0;j<4;j++)
            {
                tt.x=t.x+dx[j],tt.y=t.y+dy[j];
                if(Check(tt)&&(b[tt.x][tt.y]==-1))
                {
                    if(map[tt.x][tt.y]=='#')
                    {
                        b[tt.x][tt.y]=b[t.x][t.y]+1;
                        f.push_back(tt);
                    }
                    else
                    {
                        f.push_front(tt);
                        b[tt.x][tt.y]=b[t.x][t.y];
                    }
                }
            }
        }
        len=W.size();
        for(int i=0;i<len;i++)
        {
            t=W.front();
            W.pop_front();
            for(int j=0;j<4;j++)
            {
                tt.x=t.x+dx[j],tt.y=t.y+dy[j];
                if(Check(tt)&&(c[tt.x][tt.y]==-1))
                {
                    if(map[tt.x][tt.y]=='#')
                    {
                        c[tt.x][tt.y]=c[t.x][t.y]+1;
                        W.push_back(tt);
                    }
                    else
                    {
                        W.push_front(tt);
                        c[tt.x][tt.y]=c[t.x][t.y];
                    }
                }
            }
        }
    }
}

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",map[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                a[i][j]=b[i][j]=c[i][j]=-1;
                if(map[i][j]=='w')
                {
                    p1.x=i,p1.y=j;
                    a[i][j]=0;
                }
                if(map[i][j]=='f')
                {
                    p2.x=i,p2.y=j;
                    b[i][j]=0;
                }
                if(map[i][j]=='W')
                {
                    p3.x=i,p3.y=j;
                    c[i][j]=0;
                }
            }
        }
        Bfs();
        int ans=inf;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(map[i][j]=='#')
                    ans=min(ans,a[i][j]+b[i][j]+c[i][j]-2);
                else
                    ans=min(ans,a[i][j]+b[i][j]+c[i][j]);
            }
        printf("%d\n",ans);
    }
    return 0;
}
