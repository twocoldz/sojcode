#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
bool dp[40005];

struct node
{
    int h,a,c;
}ty[405];

bool cmp(node x,node y)
{
    return x.a<y.a;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&ty[i].h,&ty[i].a,&ty[i].c);
        }
        sort(ty+1,ty+1+n,cmp);
        memset(dp,0,sizeof(dp));
        dp[0]=true;
        int t=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=ty[i].c;j++)
            {
                for(int k=min(t,ty[i].a-ty[i].h);k>=0;k--)
                {
                    if(dp[k])
                    {
                        int m=k+ty[i].h;
                        dp[k+ty[i].h]=true;
                        if(m>t)
                        {
                            t=m;
                        }
                    }
                }
            }
        }
        printf("%d\n",t);
    }
    return 0;
}
