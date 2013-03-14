#include <cstdio>
#include <cstring>

int f[4005][2];

int main()
{
    int n,p;
    while(scanf("%d%d",&n,&p)==2)
    {
        if(n==1)
        {
            printf("%d\n",1%p);
            continue;
        }
        int r=0;
        f[1][0]=1;
        for (int i=2;i<=n;i++)
        {
            r^=1;
            for (int j=1;j<=i;j++)
            {
                f[j][r]=(f[j-1][r]+f[i-j][r^1])%p;
            }
        }
        printf("%d\n",(f[n][r]<<1)%p);
    }
    return 0;
}
