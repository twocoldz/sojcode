#include <cstdio>
#include <cstring>
#include <algorithm>

#define UP 1
#define DN 0

using namespace std;
int h[100005];
int f[100005];

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        h[0]=0;
        int t=0,flag=UP;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",h+i);
            if(h[i]<h[i-1])
                f[t++]=i-1,flag=DN;
            if(h[i]>=h[i-1])
                flag=UP;
        }
        if(flag==UP)
            f[t++]=n;
        if(t==0)
        {
            printf("%d\n",n);
            continue;
        }
        int ans=0;
        for(int i=0;i<t;i++)
        {
            int num=1;
            for(int j=f[i]-1;j>=1&&h[j]<=h[j+1];j--)
                num++;
            for(int j=f[i]+1;j<=n&&h[j]<=h[j-1];j++)
                num++;
            ans=max(num,ans);
            if(ans==n)
                break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
