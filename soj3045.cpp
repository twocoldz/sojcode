#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
const int maxn=100005;
char a[maxn],b[maxn];
int r[maxn*2];
int wv[maxn*2];
int sa[maxn*2];
int rank[maxn*2];
int height[maxn*2];
int Ws[maxn*2];
int *x=new int[maxn*2];
int *y=new int[maxn*2];

int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}

void Suffix(int n)
{
    int m=128;
    int i,j,p;
    int *t;
    for(i=0;i<m;i++)
    {
        Ws[i]=0;
    }
    for(i=0;i<n;i++)
    {
        Ws[x[i]=r[i]]++;
    }
    for(i=1;i<m;i++)
    {
        Ws[i]+=Ws[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        sa[--Ws[x[i]]]=i;
    }
    for(j=1,p=1;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++)
        {
            y[p++]=i;
        }
        for(i=0;i<n;i++)
        {
            if(sa[i]>=j)
            {
                y[p++]=sa[i]-j;
            }
        }
        for(i=0;i<n;i++)
        {
            wv[i]=x[y[i]];
        }
        for(i=0;i<m;i++)
        {
            Ws[i]=0;
        }
        for(i=0;i<n;i++)
        {
            Ws[wv[i]]++;
        }
        for(i=1;i<m;i++)
        {
            Ws[i]+=Ws[i-1];
        }
        for(i=n-1;i>=0;i--)
        {
            sa[--Ws[wv[i]]]=y[i];
        }
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
        {
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        }
    }
}

void GetHeight(int n)
{
    int i,j,k=0;
    for(i=1;i<=n;i++)
    {
        rank[sa[i]]=i;
    }
    for(i=0;i<n;height[rank[i++]]=k)
    {
        for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++)
		{
			;
		}
    }
}

int main()
{
    while(gets(a))
    {

       gets(b);
       int lena=strlen(a);
       int n=0;
       for(int i=0;a[i];i++)
       {
           r[n++]=a[i];
       }
       r[n++]=1;
       for(int i=0;b[i];i++)
       {
           r[n++]=b[i];
       }
       r[n]=0;
       Suffix(n+1);
       GetHeight(n);
       int MAX=0;
       for(int i=1;i<=n;i++)
       {
           if((sa[i]<lena&&sa[i-1]>lena)||(sa[i-1]<lena&&sa[i]>lena))
           {
               if(height[i]>MAX)
               {
                   MAX=height[i];
               }
           }
       }
       printf("%d\n",MAX);
    }
    return 0;
}
