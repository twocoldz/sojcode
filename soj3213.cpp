#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
bool can[1<<16];
int b[1<<16];
int dp[2][1<<16];
int v[16][16];
int a[16];
int n;

void Init()
{
    for(int i=0;i<16;i++)
        a[i]=1<<i;
    for(int i=0;i<(1<<16);i++)
    {
        if((i&(i>>1))==0)
        {
            can[i]=true;
        }
        else
            can[i]=false;
    }
}


int Cal(int x,int k)
{
    int sum=0;
    for(int i=0;i<n;i++)
        if((a[i]&k)>0)
            sum+=v[x][i];
    return sum;
}

int main()
{
    Init();
    char s[100];
    while(gets(s)!=NULL)
    {
        int len=strlen(s);
        s[len]=' ';
        n=0;
        v[0][n]=0;
        for(int i=0;i<=len;i++)
        {
            if(s[i]>='0'&&s[i]<='9')
                v[0][n]=v[0][n]*10+s[i]-'0';
            else
                v[0][++n]=0;
        }
        char x,y;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                x=getchar();
                y=getchar();
                getchar();
                v[i][j]=(x-'0')*10+y-'0';
            }
        }
        gets(s);         //¶Á¿ÕÐÐ

        int tt=0;
        for(int i=0;i<a[n];i++)
        {
            if(can[i])
                b[tt++]=i;
        }
        for(int i=0;i<tt;i++)
            dp[0][i]=Cal(0,b[i]);
        int r=0;
        for(int i=1;i<n;i++)
        {
            r^=1;
            for(int j=0;j<tt;j++)
            {
                dp[r][j]=0;
                int sum=Cal(i,b[j]);
                for(int k=0;k<tt;k++)
                {
                    if(((b[j]&b[k])==0)&&(((b[j]>>1)&b[k])==0)&&(((b[j]<<1)&b[k])==0))
                    {
                        if(dp[r][j]<dp[r^1][k]+sum)
                            dp[r][j]=dp[r^1][k]+sum;
                    }
                }
            }
        }
        int ans=dp[r][0];
        for(int i=1;i<tt;i++)
            ans=max(dp[r][i],ans);
        printf("%d\n",ans);
    }
    return 0;
}

