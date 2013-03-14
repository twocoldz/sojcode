#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=100005;

int num[maxn*2];
int Fa[maxn*2];
int n,w;

int FindFa(int x)
{
    if(Fa[x]!=x)
    {
        Fa[x]=FindFa(Fa[x]);
    }
	return Fa[x];
}

void Insert(int l,int x)
{
    l=FindFa(l);
    num[l]=x;
    Fa[l]=Fa[l+1];
    if(l>w)
        w=l;
}

inline void Init()
{
    for(int i=0;i<=n+n;i++)
    {
        num[i]=0;
        Fa[i]=i;
    }
}

int main()
{
    while(scanf("%d",&n)==1&&n)
    {
        Init();
        int x;
        w=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            Insert(x,i);
        }
        printf("%d\n",w);
        for(int i=1;i<=w;i++)
        {
            i==w?printf("%d\n",num[i]):printf("%d ",num[i]);
        }
    }
    return 0;
}
