#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
char map[1005][1005];
int tmp[4];
int n,m;

void Dfs(int x,int y)
{
    if(map[x][y]!='.'||x==0||x==n-1||y==0||y==m-1)
        return ;
    int cnt=0;
    for(int i=0;i<4;i++)
    {
        if(map[x+dx[i]][y+dy[i]]=='A')
            tmp[cnt++]=i;
    }
    switch(cnt)
    {
        case 2:
            if((tmp[0]+tmp[1])%2==0||(map[x-dx[tmp[0]]-dx[tmp[1]]][y-dy[tmp[0]]-dy[tmp[1]]]!='.'))
                break;
        case 3:
        case 4:
            map[x][y]='A';
            for(int i=0;i<4;i++)
                Dfs(x+dx[i],y+dy[i]);

    }
}

bool Check(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m&&map[x][y]=='.')
        return true;
    return false;
}

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0;i<n;i++)
            scanf("%s",map[i]);
        for(int i=1;i<n-1;i++)
            for(int j=1;j<m-1;j++)
                Dfs(i,j);
        int sx,sy;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(map[i][j]=='A')
                {
                    sx=i-1;
                    sy=j;
                    goto out;
                }
        out:;
        //puts("======================================");
        //for(int i=0;i<n;i++)
        //    printf("%s\n",map[i]);
        int gx=sx,gy=sy;
        int ans=0,d=0,tx,ty;
        //顺时针 尽量往里面走
        do
        {
            //printf("gx=%d gy=%d\n",gx,gy);
            tx=gx+dx[(d+1)&3],ty=gy+dy[(d+1)&3];
            if(Check(tx,ty))
            {
                gx=tx;
                gy=ty;
                d=(d+1)&3;
                ans++;
                continue;
            }
            tx=gx+dx[d],ty=gy+dy[d];
            if(Check(tx,ty))
            {
                gx=tx;
                gy=ty;
                ans++;
                continue;
            }
            tx=gx+dx[(d+3)&3],ty=gy+dy[(d+3)&3];
            if(Check(tx,ty))
            {
                gx=tx;
                gy=ty;
                d=(d+3)&3;
                ans++;
                continue;
            }
        }while(gx!=sx||gy!=sy);
        printf("%d\n",ans);
    }
    return 0;
}
