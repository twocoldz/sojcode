#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn=50005;
int n,k,d;

int fa[maxn],r[maxn];

int FindFa(int x)
{
    if(fa[x]!=x)
    {
        int t=fa[x];
        fa[x]=FindFa(fa[x]);
        r[x]=(r[x]+r[t])%3;
    }
    return fa[x];
}

void Un(int x,int y,int tx,int ty)
{
    fa[ty]=tx;
    r[ty]=(r[x]-r[y]+2+d)%3;
}

inline void Init()
{
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        r[i]=0;
    }
}

int main()
{
    while(scanf("%d%d",&n,&k)!=EOF&&n)
    {
        int a,b,tx,ty,count=0;
        Init();
        for(int i=1;i<=k;i++)
        {
            scanf("%d%d%d",&d,&a,&b);
            if(a>n||b>n||(d==2&&a==b))
            {
                count++;
                continue;
            }
            tx=FindFa(a);
            ty=FindFa(b);
            if(tx!=ty)
            {
                Un(a,b,tx,ty);
            }
            else
            {
                if(d==1&&r[a]!=r[b])
                {
                    count++;
                    continue;
                }
                else if(d==2&&(r[a]!=(r[b]+2)%3))
                {
                    count++;
                    continue;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
