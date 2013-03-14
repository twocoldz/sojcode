#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 1000000000

using namespace std;
int ans,n;
int a[22];

bool cmp(int a,int b)
{
    return a>b;
}

void dfs(int cnt,int v,int num)
{
    if(num==n+1)
        return ;
    int t=v/a[num];
    v%=a[num];
    if(v==0)
    {
        ans=cnt+t;
        return ;
    }
    for(;t>=0;t--)
    {
        if(cnt+t+(v-1)/a[num+1]+1>=ans)
            break;
        dfs(cnt+t,v,num+1);
        v+=a[num];
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int v;
        scanf("%d%d",&n,&v);

        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
        }
        sort(a+1,a+1+n,cmp);
        ans=v/a[n];
        for(int i=1;i<=n;i++)
        {
            if(v%a[i]==0)
            {
                ans=v/a[i];
                break;
            }
        }
        a[n+1]=1;
        dfs(0,v,1);
        printf("%d\n",ans);

    }
    return 0;
}
