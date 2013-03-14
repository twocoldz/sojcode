#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int w,c;
}box[1005];
bool cmp(node a,node b)
{
    return a.c+a.w<b.c+b.w;
}
int dp[1005];

int main()
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&box[i].w);
        for(int i=1;i<=n;i++)
            scanf("%d",&box[i].c);
        sort(box+1,box+1+n,cmp);
        dp[0]=0;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(box[i].c>=dp[ans])
            {
                dp[ans+1]=dp[ans]+box[i].w;
                ans++;
            }
            for(int j=ans-1;j>=0;j--)
            {
                if(dp[j]<=box[i].c&&dp[j+1]>dp[j]+box[i].w)
                    dp[j+1]=dp[j]+box[i].w;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
