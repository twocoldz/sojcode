#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define modd 19871118


//ÈÝ³âÔ­Àí
using namespace std;
int  n,m;
long long c[1010][1010];

long long Cal(int k,int  n)
{
    long long a=k;
    if(n==0)
    {
        return 1;
    }
    long long sum=1;
    if(n%2>0)
    {
        sum=sum*a%modd;
    }
    n/=2;
    while(n>0)
    {
        a=(a%modd)*(a%modd)%modd;
        if(n%2>0)
        {
            sum=sum*a%modd;
        }
        n/=2;
    }
    return sum;
}

int main(){
     for(int i=1;i<=1000;i++)
     {
         c[i][0]=c[i][i]=1;
         for(int j=1;j<i;j++)
         {
             c[i][j]=(c[i-1][j]+c[i-1][j-1])%modd;
         }
     }
     while(scanf("%d%d",&n,&m)==2)
     {
         if(m>n)
         {
             printf("0\n");
             continue;
         }
         long long ans=0;
         int flag=1;
         for(int i=m;i>0;i--)
         {
             ans=(modd+ans+flag*(c[m][i]*(i*Cal(i-1,n-1))%modd)%modd)%modd;
             flag=-flag;
            // printf("%lld\n",ans);
         }
         printf("%lld\n",ans);
     }
    return 0;
 }
