#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;
int b[50005],e[50005];

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",b+i,e+i);
        }


        long long ans=inf;
        printf("lld\n",ans);
    }
    return 0;
}
