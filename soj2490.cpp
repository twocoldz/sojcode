#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int const maxn=20005;

int Fa[maxn*2];

int FindFa(int x)
{
    if(Fa[x]!=x)
    {
        Fa[x]=FindFa(Fa[x]);
    }
    return Fa[x];
}

void Un(int a,int b)
{
    int fa=FindFa(a);
    int fb=FindFa(b);
    if(fa!=fb)
    {
        Fa[fa]=fb;
        Fa[a]=fb;
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        int x,y;
        for(int i=0;i<2*n;i++)
        {
            Fa[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            Un(i*2,x*2+y);
            printf("%d%d",Fa[0],Fa[1]);
            scanf("%d%d",&x,&y);
            Un(i*2+1,x*2+y);
            printf("%d%d",Fa[0],Fa[1]);
        }
        int flag=0;
        for(int i=0;i<n;i++)
        {

            if(FindFa(i*2)==FindFa(i*2+1))
            {
                flag=1;
                break;
            }
            printf("%d %d",Fa[i*2],Fa[i*2+1]);
        }
        if(flag)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
