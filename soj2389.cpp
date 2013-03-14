#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn=1005;

int x[maxn],y[maxn],num[maxn];
int Fa[maxn];
int pos,total;
int n;


int Dis(int i,int j)
{
    return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}

/*void Dfs(int start)
{
    for(int i=1;i<=n;i++)
    {
        if(vis[i])
            continue;
        if(Dis(start,i)<=900)
        {
            total+=num[i];
            vis[i]=1;
            Dfs(i);
        }
        vis[i]=0;
    }
}
*/

int FindFa(int x)
{
    if(Fa[x]!=x)
    {
        Fa[x]=FindFa(Fa[x]);
    }
    return Fa[x];
}

int main()
{
    while(scanf("%d",&n)==1&&n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&x[i],&y[i],&num[i]);
            Fa[i]=i;
        }
        //memset(vis,0,sizeof(vis));
        int sum=0;

        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(Dis(i,j)<=900)
                {
                    int fi=FindFa(i);
                    int fj=FindFa(j);
                    if(fi!=fj)
                    {
                        Fa[fj]=fi;
                        num[fi]+=num[fj];
                    }
                }
            }
        }

        for(int i=1;i<=n;i++)
        {
            int fa=FindFa(i);
            if(num[fa]>sum)
            {
                sum=num[fa];
                pos=i;
            }
        }

        printf("%d %d\n",pos,sum);
    }
    return 0;
}
