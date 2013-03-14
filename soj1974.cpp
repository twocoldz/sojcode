#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
char a[1000005];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int f=1;
        scanf("%s",a);
        if(a[0]=='-')
            f=0;
        int ans=0;
        for(int i=f?0:1;a[i];i++)
        {
            ans+=a[i]-48;
        }
        ans%=9;
        if(!f)
            ans=9-ans;
        printf("%d\n",ans);
    }
    return 0;
}
