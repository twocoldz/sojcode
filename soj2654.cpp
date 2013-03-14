#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int high[10005],low[10005];

int main()
{
    int m,n;
    while(scanf("%d%d",&n,&m)==2)
    {
        int i,j,sum=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&high[i]);
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d",&low[i]);
        }
        sort(high+1,high+n+1);
        sort(low+1,low+m+1);
        for(i=1,j=1;i<=n&&j<=m;i++)
        {
            if(low[j]<high[i])
            {
                j++;
                sum++;
            }
        }
        sum+=n;
        printf("%d\n",sum);
    }
	return 0;
}