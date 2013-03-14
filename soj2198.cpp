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
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n;
        scanf("%d",&n);
        getchar();
        int k=0,l;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                scanf("%d",&l);
                e[k].f=i,e[k].t=j,e[k++].l=l;
            }
            gets(tmp);
            //printf("%s ",tmp);
        }
        for(int i=1;i<=n;i++)
        {
            fa[i]=i;
        }
        sort(e,e+k);
        int t=1;
        int ans=0;
        for(int i=0;t<n&&i<k;i++)
        {
            int fx=FindFa(e[i].f);
            int fy=FindFa(e[i].t);
            if(fx!=fy)
            {
                fa[fy]=fx;
                t++;
                if(t==n)
                    ans=e[i].l;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
