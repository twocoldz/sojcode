#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int dp[40];
int a[40],b[40];
int n,mod;

void Init()
{
    a[0]=b[0]=1;
    for(int i=1;i<40;i++)
    {
        a[i]=a[i-1]*2%mod;
        b[i]=b[i-1]*3%mod;
    }
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<40;i++)
    {
        dp[i]=(dp[i-1]*2%mod+(a[i-1]*b[i-1])%mod)%mod;
    }
}

int Solve()
{
    Init();
    int bit[40],len;
    int i,j,ret=0,temp=0,tt,k,cnt;
    len=0;
    n++;
    while(n)
    {
        bit[len++]=n%3;
        n/=3;
    }
    for(i=len-1;i>=0;temp=temp*3+bit[i],temp%=mod,i--)
    {
       for(j=0;j<bit[i];j++)
         {
             tt=(temp*3+j)%mod;
             if(i==0)
                ret+=tt;
             else
             {
                for(k=i-1;k>=0;k--)
                    ret+=((tt*b[i-1-k]%mod)*a[i-1-k]%mod)*b[k]%mod+(dp[i-1-k]*b[k])%mod;
                ret+=((tt*b[i]%mod)*a[i])%mod+dp[i];
            }
         }
         if(bit[i]==2)
         {
             i--;
             break;
         }
    }
    cnt=0;
   if(i>=0)
   {
        for(;i>=0;cnt%=mod,i--)
            cnt=cnt*3+bit[i];
   }
   ret+=cnt*temp%mod;
   return ret%mod;
}

int main()
{
    while(scanf("%d%d",&n,&mod)==2)
    {
        printf("%d\n",Solve());
    }
    return 0;
}
