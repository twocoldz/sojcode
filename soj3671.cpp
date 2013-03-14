#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int sum[20005];
int ans=0;
void Init()
{
    for(int i=1;i<=20000;i++)
    {
        for(int j=i+i;j<=20000;j+=i)
            sum[j]+=i;
    }
    for(int i=6;i<=18000;i++)
        ans=max(ans,sum[i]);
}

int main()
{
    int n;
    Init();
    printf("%d\n",ans);
    while(scanf("%d",&n)==1)
    {
        while(true)
        {
            if(sum[n]!=n&&sum[sum[n]]==n)
                break;
            n++;
        }
        printf("%d %d\n",n,sum[n]);
    }
    return 0;
}
