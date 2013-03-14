#include <cstdio>

int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        int pre=0,now;
        while(n--)
        {
            scanf("%d",&now);
            if(now!=pre)
                printf("%d ",now);
            pre=now;
        }
        printf("$\n");
    }
    return 0;
}
