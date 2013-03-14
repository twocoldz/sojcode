#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn=1005;

int cnt[maxn];  //记录每个节点的子节点数
int next[maxn][maxn]; //记录i节点的第j个节点的标号
bool worm[maxn];  //记录是否有小虫

struct P
{
    int step,leaves,nostep;
}node[maxn];

bool cmp(int a,int b)
{
    return (node[a].nostep+2)*node[b].leaves<(node[b].nostep+2)*node[a].leaves;
}

void Dfs(int k)
{
    if(cnt[k]==0)
    {
        node[k].leaves=1;
        node[k].step=node[k].nostep=0;
        return ;
    }

    int i,j;
    for(i=1;i<=cnt[k];i++)
    {
        j=next[k][i];
        Dfs(j);
        node[k].leaves+=node[j].leaves;
        if(worm[j])
            node[j].nostep=0;
        node[k].nostep+=(node[j].nostep+2);
    }

    sort(next[k]+1,next[k]+cnt[k]+1,cmp);

    int sum=0;

    for(i=1;i<=cnt[k];i++)
    {
        j=next[k][i];
        node[k].step+=node[j].step+(sum+1)*node[j].leaves;
        sum+=node[j].nostep+2;
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        int x;
        char c;
        memset(cnt,0,sizeof(cnt));
        memset(worm,false,sizeof(worm));
         memset(node,0,sizeof(node));
        for(int i=1;i<=n;i++)
        {
            scanf("%d %c",&x,&c);
            if(x!=-1)
            {
                cnt[x]++;
                next[x][cnt[x]]=i;
            }
            if(c=='Y')
            {
                worm[i]=1;
            }
        }
        Dfs(1);
        double ans=(double)node[1].step/(double)node[1].leaves;
        printf("%.4lf\n",ans);
    }
    return 0;
}
