#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
char a[2000005*10];
int v[2000005];

/*int Partition(int l,int r)
{
    if(l<r)
    {
        int i=l;
        int j=r;
        int x=a[i];
        while(i<j)
        {
            while(i<j&&a[j]>x)
                j--;
            if(i<j)
            {
                a[i++]=a[j];
            }
            while(i<j&&a[i]<x)
                i++;
            if(i<j)
            {
                a[j--]=a[i];
            }
        }
        a[i]=x;
        return i;
    }
    return -1;
}

int Qsort(int l,int r,int k)
{
    if(l==r)
    {
        return a[l];
    }
    int p=Partition(l,r);
    int j=p-l+1;
    if(j==k)
    {
        return a[p];
    }
    else if(j>k)
    {
        return Qsort(l,p,k);
    }
    else
    {
        return Qsort(p+1,r,k-j);
    }
}*/

inline int getv()
{
    int i,j,t,f;
    for(i=0,j=0;a[i];i++)
    {
        if((a[i]>='0'&&a[i]<='9')||a[i]=='-')
        {
            if(a[i]=='-')
            {
                f=-1;
                i++;
            }
            else
            {
                f=1;
            }
            t=0;
            while(a[i]>='0'&&a[i]<='9')
            {
                t=t*10+(a[i++]-'0');
            }
            v[j++]=t*f;

        }
    }
    return j;
}

int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        getchar();
        gets(a);
        getv();
        nth_element(v,v+k-1,v+n);
        printf("%d\n",v[k-1]);
    }
    return 0;
}
