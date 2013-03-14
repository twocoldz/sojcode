#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int Fa[100005];

int FindFa(int x)
{
    if(Fa[x]!=x)
    {
        Fa[x]=FindFa(Fa[x]);
    }
    return Fa[x];
}

void Un(int x,int y)
{
    int fx=FindFa(x);
    int fy=FindFa(y);
    if(fx!=fy)
    {
        Fa[fx]=fy;
        Fa[x]=fy;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,q;
        scanf("%d%d%d",&n,&m,&q);
        for(int i=1;i<=n;i++)
        {
            Fa[i]=i;
        }
        int x,y;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            Un(x,y);
        }
        for(int i=1;i<=n;i++)
        {
            FindFa(i);
        }
        for(int i=1;i<=q;i++)
        {
            scanf("%d%d",&x,&y);
            if(Fa[x]==Fa[y])
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
    return 0;

}
