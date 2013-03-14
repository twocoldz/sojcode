#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int fa[1005];

int FindFa(int x)
{
    if(x!=fa[x])
    {
        fa[x]=FindFa(fa[x]);
    }
    return fa[x];
}

void Union(int x,int y)
{
    int fx=FindFa(x);
    int fy=FindFa(y);
    fa[fx]=fy;
}

int main()
{
    int n,m,q;
    while(scanf("%d%d%d",&n,&m,&q)==3)
    {
        for(int i=1;i<=n;i++)
            fa[i]=i;
        int a,b;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            Union(a,b);
        }
        for(int i=1;i<=q;i++)
        {
            scanf("%d%d",&a,&b);
            if(FindFa(a)==FindFa(b))
                printf("Y\n");
            else
                printf("N\n");
        }
    }
    return 0;
}

