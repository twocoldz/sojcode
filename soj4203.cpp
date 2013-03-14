#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct node
{
    int s;   //记录出现这个值可能的状态
    int cnt; //记录这个状态所需的卡片数
    node(int a,int b)
    {
        s=a,cnt=b;
    }
};
vector<node> f[23];
vector<int> dp[2];  //滚动
int cnt[1<<22];
bool vis[1<<22];
int a[23];

void Dfs(int bit,int tot,int k,int c)
{
    if(tot<22)
    {
        for(int i=k;i<=22;i++)
        {
            if(i+tot<=22)
            {
                f[i+tot].push_back(node(bit|1<<(i-1),c+1));
                Dfs(bit|(1<<(i-1)),i+tot,i+1,c+1);
            }
        }
    }
}

int main()
{
    int n,m;
    int cases=1;
    Dfs(0,0,1,0);
    while(scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)
            break;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<m;i++)
            scanf("%d",a+i);
        int Max=1<<n;
        dp[0].clear();
        dp[0].push_back(0);
        int ans=0;
        int r=0;
        for(int i=0;i<m;i++)
        {
            r^=1;
            int Size=dp[r^1].size();
            if(!Size)
                break;
            dp[r].clear();
            memset(vis,0,(1<<n)*sizeof(vis[0]));
            for(int j=0;j<Size;j++)
            {
                int len=f[a[i]].size();
                for(int k=0;k<len;k++)
                {
                    if(f[a[i]][k].s>=Max)
                        continue;
                    if(!(f[a[i]][k].s&dp[r^1][j]))
                    {
                        int tt=f[a[i]][k].s|dp[r^1][j];
                        if(!vis[tt])
                        {
                            cnt[tt]=cnt[dp[r^1][j]]+f[a[i]][k].cnt;
                            if(cnt[tt]>ans)
                                ans=cnt[tt];
                            dp[r].push_back(tt);
                            vis[tt]=1;
                        }
                    }
                }
            }
        }
        printf("Game %d: %d\n",cases++,ans);
    }
    return 0;
}
