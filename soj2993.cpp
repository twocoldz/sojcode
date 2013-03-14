#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int a[1005];
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        int t=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
            t^=a[i];
        }
        if(t==0)
            printf("0\n");
        else
        {
            int ans=0;
            for(int i=0;i<n;i++)
            {
                if((a[i]-(t^a[i]))>0)
                {
                    ans++;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
