#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int num[105];
int ans[15];

int n,t;
bool flag;

void dfs(int sum,int times,int len)
{
    int i;
    if(times>12)
        return;
    if(sum==t)
    {
        flag=true;
        for(i=0;i<times;i++)
        {
            i>0?printf("+%d",ans[i]):printf("%d",ans[i]);
        }
        printf("\n");
        return ;
    }
    for(i=len;i>=1;i--)
    {
        if(num[i]>0&&sum+i<=t)
        {
            num[i]--;
            ans[times]=i;
            dfs(sum+i,times+1,i);
            num[i]++;
        }
    }
}

inline void Init()
{
    for(int i=0;i<=100;i++)
    {
        num[i]=0;
    }
}

int main()
{
    while(scanf("%d%d",&t,&n)==2)
    {
        if(t==0&&n==0)
        {
            break;
        }
        Init();
        int x;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            num[x]++;
        }
        flag=false;
        printf("Sums of %d:\n",t);
        dfs(0,0,99);
        if(!flag)
        {
            printf("NONE\n");
        }
    }
}
