#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int f,t,l;
    bool operator <(const node &a) const
    {
        return l<a.l;
    }
}e[130000];
int fa[505];
int FindFa(int x)
{
    if(fa[x]!=x)
    {
        fa[x]=FindFa(fa[x]);
    }
    return fa[x];
}
char tmp[4000];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int ans=0,k=0,l;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&l);
            e[k].f=0,e[k].t=i,e[k++].l=l;
        }
        getchar();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                scanf("%d",&l);
                e[k].f=i,e[k].t=j,e[k++].l=l;
            }
            gets(tmp);
        }
        sort(e,e+k);
        for(int i=0;i<=n;i++)
        {
            fa[i]=i;
        }
        int t=1;
        for(int i=0;t<=n&&i<k;i++)
        {
            int fx=FindFa(e[i].f);
            int fy=FindFa(e[i].t);
            if(fx!=fy)
            {
                fa[fy]=fx;
                t++;
                ans+=e[i].l;
                //printf("from=%d to=%d len=%d ans=%d\n",e[i].f,e[i].t,e[i].l,ans);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
