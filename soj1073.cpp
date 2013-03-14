#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
const int dx[8]={1,1,2,2,-1,-1,-2,-2};
const int dy[8]={2,-2,1,-1,2,-2,1,-1};
int f[8][8];

int sx,sy,ex,ey;
queue<int> v;

bool Cleck(int x,int y)
{
    if(x<0||x>7||y<0||y>7)
        return 0;
    return 1;
}

void Bfs()
{
    memset(f,-1,sizeof(f));
    f[sx][sy]=0;
    while(!v.empty())
        v.pop();
    v.push(sx*8+sy);
    while(!v.empty())
    {
        int t=v.front();
        v.pop();
        int x=t/8,y=t%8;
        for(int i=0;i<8;i++)
        {
            int tx=x+dx[i],ty=y+dy[i];
            if(Cleck(tx,ty)&&f[tx][ty]==-1)
            {
                f[tx][ty]=f[x][y]+1;
                if(tx==ex&&ty==ey)
                    return ;
                v.push(tx*8+ty);
            }
        }
    }
}

int main()
{
    char a[4],b[4];
    while(scanf("%s%s",a,b)==2)
    {
        sx=a[0]-'a';
        sy=a[1]-'1';
        ex=b[0]-'a';
        ey=b[1]-'1';
        Bfs();
        printf("To get from %s to %s takes %d knight moves.\n",a,b,f[ex][ey]);
    }
    return 0;
}
