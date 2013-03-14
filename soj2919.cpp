#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define maxn 32

using namespace std;
int N,K,M;

struct matrix
{
    long long g[maxn][maxn];
    matrix operator +(const matrix &a)
    {
        matrix t;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                t.g[i][j]=g[i][j]+a.g[i][j];
                t.g[i][j]%=M;
            }
        }
        return t;
    }

    matrix operator *(const matrix &a)
    {
        matrix t;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                t.g[i][j]=0;
                for(int k=0;k<N;k++)
                {
                    t.g[i][j]+=g[i][k]*a.g[k][j];
                }
                t.g[i][j]%=M;
            }
        }
        return t;
    }
}S,A;

matrix Pow(int k,matrix a)
{
    matrix b;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            b.g[i][j]=(i==j?1:0);
    }
    while(k)
    {
        if(k&1)
            b=b*a;
        k>>=1;
        a=a*a;
    }
    return b;
}

matrix Sum(int k,matrix a)
{
    if(k==1)
        return a;
    int t=k>>1;
    matrix tmp,tt;
    tmp=Sum(t,a);
    if(k&1)
    {
        return tmp+(tt=Pow(t+1,a))*tmp+tt;
    }
    else
    {
        return tmp+Pow(t,a)*tmp;
    }
}
int main()
{
    while(scanf("%d%d%d",&N,&K,&M)==3)
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                scanf("%d",&A.g[i][j]);
        S=Sum(K,A);

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                (j==N-1)?printf("%d\n",S.g[i][j]):printf("%d ",S.g[i][j]);
            }
        }
    }
    return 0;


}
