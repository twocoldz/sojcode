#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[100005],high[100005],temp[100005];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        int i,j,k;
        memset(high,0,sizeof(high));
        memset(temp,0,sizeof(temp));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=n;i>=1;i--)
        {
            k=a[i];
            j=i;
            while(k<temp[j+1])
            {
                j++;
                k+=a[j];
            }
            high[i]=high[j+1]+1;
            temp[i]=k;
        }
        printf("%d\n",high[1] );
    }
    return 0;    
}