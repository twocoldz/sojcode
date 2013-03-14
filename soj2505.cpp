#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define max(a,b) (a>b?a:b)

int a[405][405];
int d[405];

struct node
{
    int order,t;
}p[405];

bool cmp(node a,node b)
{
    return a.t<b.t;
}

int main()
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        int i,j,ans=0;
        memset(d,0,sizeof(d));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&p[i].t);
            p[i].order=i;
        }
        sort(p+1,p+1+n,cmp);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(i=1;i<=n;i++)
        {
            if(a[1][p[i].order]<=p[i].t)
                d[i]=1; 
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<i;j++)
            {
                if(d[j]&&d[j]+1>=d[i]&&p[i].t>=a[p[j].order][p[i].order]+p[j].t)
                    d[i]=d[j]+1;
            }
            ans=max(ans,d[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}