#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int f,t,l;
    bool operator <(const node &a)const
    {
        return l<a.l;
    }
}e[10005];
int fa[55];

int FindFa(int x)
{
    if(fa[x]!=x)
    {
        fa[x]=FindFa(fa[x]);
    }
    return fa[x];
}

int main()
{
    int n,m;
    while(scanf("%d",&n)&&n)
    {
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&e[i].f,&e[i].t,&e[i].l);
        }
        for(int i=1;i<=n;i++)
            fa[i]=i;
        sort(e,e+m);
        int t=1;
        int ans=0;
        for(int i=0;t<n&&i<m;i++)
        {
            int fx=FindFa(e[i].f);
            int fy=FindFa(e[i].t);
            if(fx!=fy)
            {
                fa[fy]=fx;
                t++;
                ans+=e[i].l;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
