#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f
using namespace std;

struct T
{
    char name[25];
    int ans,tot;
}a[205];
int dp[305],f[305];

bool cmp2(T a,T b)
{
    if(a.ans==b.ans)
        return a.tot<b.tot;
    return a.ans>b.ans;
}

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n,m;
        int t,fir;
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            memset(dp,0xff,sizeof(dp));
            memset(f,0xff,sizeof(f));
            dp[0]=f[0]=0;
            scanf("%s",a[i].name);
            for(int j=0;j<n;j++)
            {
                scanf("%d",&t);
                if(t!=-1)
                {
                    scanf("%d",&fir);
                    for(int k=300-fir;k>=0;k--)
                    {
                        if(dp[k]==-1)
                            continue;
                        if(dp[k+fir]==-1||dp[k+fir]<dp[k]+1||(dp[k+fir]==dp[k]+1&&f[k+fir]>f[k]+k+fir+(t-1)*20))
                        {
                            dp[k+fir]=dp[k]+1;
                            f[k+fir]=f[k]+k+fir+(t-1)*20;
                        }
                    }
                }
            }
            a[i].ans=0,a[i].tot=0;
            for(int j=0;j<=300;j++)
            {
                if(dp[j]>a[i].ans||(a[i].ans==dp[j]&&a[i].tot>f[j]))
                {
                    a[i].ans=dp[j];
                    a[i].tot=f[j];
                }
            }
        }
        sort(a,a+m,cmp2);
        for(int i=0;i<m;i++)
            printf("%s %d %d\n",a[i].name,a[i].ans,a[i].tot);
        printf("\n");
    }
    return 0;
}
