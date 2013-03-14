#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
struct node
{
    int t,num,id,f;
}c[1002];
bool operator < (const node &a,const node &b)
{
    return a.f>b.f;
}
int son[1002][1002];
bool vis[1002];
priority_queue<node> q;

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&c[i].t,&c[i].num);
            for(int j=0;j<c[i].num;j++)
            {
                scanf("%d",son[i]+j);
            }
            c[i].id=i;
        }

        memset(vis,0,sizeof(vis));
        vis[1]=1;
        c[1].f=c[1].t;
        q.push(c[1]);
        while(!q.empty())
        {
            node t=q.top();
            q.pop();
            int len=t.num;
            int i=t.id;
            for(int j=0;j<len;j++)
            {
                int tt=son[i][j];
                if(!vis[tt])
                {
                    vis[tt]=1;
                    //printf("t.f=%d c[%d].t=%d\n",t.f,tt,c[tt].t);
                    c[tt].f=t.f+c[tt].t;
                    q.push(c[tt]);
                    //printf("f[%d]=%d\n",tt,c[tt].f);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            ans=max(ans,c[i].f);
        printf("%d\n",ans);
    }
    return 0;
}
