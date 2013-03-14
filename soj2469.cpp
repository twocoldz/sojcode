#include <iostream>
#include <cstdio>
#include <cstring>

char str[305];
int a[305][305];
const int modd=1000000000;

int dfs(int b,int e)
{
    if(a[b][e]!=-1)
    {
        return a[b][e];
    }
    if(((e-b)&1)||str[b]!=str[e])
    {
        return a[b][e]=0;
    }
    if(b==e)
    {
        return a[b][e]=1;
    }
    int i,ans;
    ans=dfs(b+1,e-1);
    for(i=b+2;i<e;i++)
    {
        if(str[b]==str[i])
        {
            ans+=(dfs(b+1,i-1)*(long long)dfs(i,e))%modd;
            ans%=modd;
        }
    }
    return a[b][e]=ans;
}

void Init()
{
    for(int i=0;i<=300;i++)
    {
        for(int j=0;j<=300;j++)
        {
            a[i][j]=-1;
        }
    }
}

int main()
{
    while(scanf("%s",str)==1)
    {
        Init();
        int len=strlen(str);
        printf("%d\n",dfs(0,len-1));
    }
    return 0;
}
