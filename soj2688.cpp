#include <cstdio>

int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)==2)
    {
        int x,s=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            s^=(x%(k+1));
        }
        if(s)
            printf("windy7926778\n");
        else
            printf("fgjlwj\n");
    }
    return 0;
}
