#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define inf 0x3f3f3f3f

using namespace std;
struct node
{
    int x,y;
}p[105];
int n,m,lenx,leny;
int x[105],y[105];
int dis[105];

inline int Dis(int i,int j,int k)
{
    return abs(p[k].x-x[i])+abs(p[k].y-y[j]);
}

void Init()
{
    int k=1;
    for(int i=2;i<=n;i++)
    {
        if(x[k]!=x[i])
        {
            k++;
            x[k]=x[i];
        }
    }
    lenx=k;
    k=1;
    for(int i=2;i<=n;i++)
    {
        if(y[k]!=y[i])
        {
            k++;
            y[k]=y[i];
        }
    }
    leny=k;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",x+i,y+i);
            p[i].x=x[i];
            p[i].y=y[i];
        }
        sort(x+1,x+n+1);
        sort(y+1,y+n+1);
        Init();
        int ans=inf;
        for(int i=1;i<=lenx;i++)
        {
            for(int j=1;j<=leny;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    dis[k]=Dis(i,j,k);
                }
                sort(dis+1,dis+n+1);
                int tt=0;
                for(int k=1;k<=m;k++)
                    tt+=dis[k];
                if(tt<ans)
                    ans=tt;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
