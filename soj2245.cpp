#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=50005;
int n,m;

int Fa[maxn];

int FindFa(int x)
{
    if(Fa[x]!=x)
    {
        Fa[x]=FindFa(Fa[x]);
    }
    return Fa[x];
}

void Merge(int x,int y,int &count)
{
    int a=FindFa(x);
    int b=FindFa(y);
    if(a!=b)
    {
        count--;
        Fa[b]=a;
    }
}

void Init()
{
    for(int i=1;i<=n;i++)
    {
        Fa[i]=i;
    }
}

int main()
{
    int cases=1;
    while(scanf("%d%d",&n,&m)==2)
    {
        if(n==0&&m==0)
        {
            break;
        }
        Init();
        int x,y;
        int count=n;
        while(m--)
        {
            scanf("%d%d",&x,&y);
            Merge(x,y,count);
        }
        printf("Case %d: %d\n",cases++,count);
    }
    return 0;
}
