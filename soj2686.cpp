#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N=1000;

struct Big
{
    int num[N];
    int len;
}w[3005],f[3005];

void NumToBig(Big &x,int n)
{
    memset(&x,0,sizeof(x));
    int i=0;
    if(!n)
    {
        x.num[0]=0;
        x.len=1;
    }
    else
    {
        while(n)
        {
            x.num[i++]=n%10000;
            n/=10000;
        }
        x.len=i;
    }
}

Big Add(Big x,Big y)
{
    int i,t=0;
    for(i=0;i<x.len||i<y.len;i++)
    {
        x.num[i]+=y.num[i]+t;
        if(x.num[i]>=10000)
        {
            x.num[i]-=10000;
            t=1;
        }
        else
            t=0;
    }
    if(t)
        x.num[i++]=1;
    x.len=i;
    return x;
}

void Init()
{
    NumToBig(w[1],1),NumToBig(w[2],1);
    NumToBig(f[1],0),NumToBig(f[2],1);
    for(int i=3;i<=3000;i++)
    {
        w[i]=Add(f[i-1],f[i-2]);
        f[i]=Add(w[i-1],w[i-2]);
    }
}

int main()
{
    Init();
    int n;
    while(scanf("%d",&n)==1)
    {
        int len=w[n].len-1;
        printf("%d",w[n].num[len]);
        for(int i=len-1;i>=0;i--)
        {
            printf("%04d",w[n].num[i]);
        }
        puts("");
    }
    return 0;
}
