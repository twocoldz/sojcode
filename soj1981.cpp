#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define inf 0x3f3f3f3f
using namespace std;
const int N=105;
int lx[N],ly[N],slack[N];
int w[N][N];
int mk[N];
bool visx[N],visy[N];
int nx,ny;

bool Find(int u)
{
    visx[u]=true;
    for(int i=0;i<ny;i++)
    {
        if(visy[i])
            continue;
        int t=lx[u]+ly[i]-w[u][i];
        if(t==0)
        {
            visy[i]=true;
            if(mk[i]==-1||Find(mk[i]))
            {
                mk[i]=u;
                return true;
            }
        }
        else if(slack[i]>t)
            slack[i]=t;
    }
    return false;
}

int K_M()
{
    memset(mk,-1,sizeof(mk));
    memset(ly,0,sizeof(ly));
    //memset(lx,-inf,sizeof(lx));
    for(int i=0;i<nx;i++)
    {
        lx[i]=-inf;
        for(int j=0;j<ny;j++)
            if(w[i][j]>lx[i])
                lx[i]=w[i][j];
    }

    for(int x=0;x<nx;x++)
    {
        for(int i=0;i<ny;i++)
            slack[i]=inf;
        while(true)
        {
            memset(visx,0,sizeof(visx));
            memset(visy,0,sizeof(visy));
            if(Find(x))
                break;
            int d=inf;
            for(int i=0;i<ny;i++)
            {
                if(!visy[i]&&d>slack[i])
                    d=slack[i];
            }
            for(int i=0;i<nx;i++)
                if(visx[i])
                    lx[i]-=d;
            for(int i=0;i<ny;i++)
            {
                if(visy[i])
                    ly[i]+=d;
                else
                    slack[i]-=d;
            }
        }
    }
    int ans=0;
    for(int i=0;i<ny;i++)
        ans+=w[mk[i]][i];
    return ans;
}

char map[N][N];
int mx[N],my[N],hx[N],hy[N];
int n,m;
int main()
{
    while(scanf("%d%d",&n,&m)&&(n+m))
    {
        nx=ny=0;
        for(int i=0;i<n;i++)
            scanf("%s",map[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(map[i][j]=='m')
                {
                    mx[nx]=i;
                    my[nx++]=j;
                }
                else if(map[i][j]=='H')
                {
                    hx[ny]=i;
                    hy[ny++]=j;
                }
            }
        for(int i=0;i<nx;i++)
        {
            for(int j=0;j<ny;j++)
            {
                w[i][j]=-(abs(mx[i]-hx[j])+abs(my[i]-hy[j]));
            }
        }
        printf("%d\n",-K_M());
    }
    return 0;
}
