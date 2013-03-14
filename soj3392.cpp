#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int f[1005];

void Init()
{
    f[1]=1,f[2]=2,f[0]=0;
    for(int i=3;i<=1000;i++)
    {
        f[i]=1;
        if(i&1)
        {
            for(int j=1;j<i;j+=2)
            {
                f[i]+=f[(i-j)/2];
            }
        }
        else
        {
            for(int j=0;j<i;j+=2)
            {
                f[i]+=f[(i-j)/2];
            }
        }
    }
}

int main()
{
    Init();
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        printf("%d %d\n",i,f[x]);
    }
    return 0;
}
