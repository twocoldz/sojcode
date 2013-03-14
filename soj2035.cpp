/*#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int n,m;
int map[62][62];
char a[62][62];
int num;

void dfs(int i,int j)
{
    if(i-1>=0)
    {
        if(a[i-1][j]=='#'&&map[i-1][j]==-1)
        {
            map[i-1][j]=1-map[i][j];
            if(map[i-1][j])
            {
                num--;
            }
            else
            {
                num++;
            }
            dfs(i-1,j);
        }
    }
    if(i+1<n)
    {
        if(a[i+1][j]=='#'&&map[i+1][j]==-1)
        {
            map[i+1][j]=1-map[i][j];
            if(map[i+1][j])
            {
                num--;
            }
            else
            {
                num++;
            }
            dfs(i+1,j);
        }
    }
    if(j-1>=0)
    {
        if(a[i][j-1]=='#'&&map[i][j-1]==-1)
        {
            map[i][j-1]=1-map[i][j];
            if(map[i][j-1])
            {
                num--;
            }
            else
            {
                num++;
            }
            dfs(i,j-1);
        }
    }
    if(j+1<m)
    {
        if(a[i][j+1]=='#'&&map[i][j+1]==-1)
        {
            map[i][j+1]=1-map[i][j];
            if(map[i][j+1])
            {
                num--;
            }
            else
            {
                num++;
            }
            dfs(i,j+1);
        }
    }
}

int main()
{
    int cases=0;
    while(scanf("%d%d",&n,&m)==2)
    {
        if(n==0&&m==0)
        {
            break;
        }
        if(cases!=0)
        {
            printf("\n");
        }
        cases=1;
        for(int i=0;i<n;i++)
        {
            scanf("%s",a[i]);
            for(int j=0;j<m;j++)
            {
                map[i][j]=-1;
            }
        }
        num=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='#'&&map[i][j]==-1)
                {
                    num=1;
                    map[i][j]=0;
                    dfs(i,j);
                    if(num!=0)
                    {
                        break;
                    }
                }
            }
            if(num!=0)
            {
                break;
            }
        }
        //下面这里可以输出覆盖后的情况，看看加深理解
        //for(int i=0;i<n;i++)
        //{
        //    for(int j=0;j<m;j++)
        //        printf("%d ",map[i][j]);
        //    puts("");
        //}
        if(num==0)
             printf("POSSIBLE\n");
        else
             printf("IMPOSSIBLE\n");
    }
    return 0;
}
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={-1,0,1,0};
int mk[65][65];
bool vis[65][65];
char a[65][65];
int n,m;

bool Hungary(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int tx=x+dx[i],ty=y+dy[i];
        if(tx<0 || tx>=n || ty<0 || ty>=m || a[tx][ty]!='#' || vis[tx][ty] )
            continue;
        vis[tx][ty]=1;
        if(mk[tx][ty]==-1||Hungary(mk[tx][ty]/n,mk[tx][ty]%n))
        {
            mk[tx][ty]=x*n+y;
            return true;
        }
    }
    return false;
}

int main()
{
    while(scanf("%d%d",&n,&m)&&(n+m))
    {
        for(int i=0;i<n;i++)
            scanf("%s",a[i]);
        memset(mk,-1,sizeof(mk));
        int cnt=0,ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(a[i][j]=='#')
                {
                    cnt++;
                    memset(vis,0,sizeof(vis));
                    if(Hungary(i,j))
                        ans++;
                }
        if((cnt&1)||cnt!=ans)
            printf("IMPOSSIBLE\n\n");
        else
            printf("POSSIBLE\n\n");
    }
    return 0;
}
