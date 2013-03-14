#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        int num[32]={0};
        int i,j;
        for(i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            j=0;
            while(x)
            {
                num[j++]+=x%2;
                x/=2;
            }
        }
        for(i=0;i<32;i++)
        {
            if(num[i]%(k+1))
            {
                break;
            }
        }
        if(i==32)
            printf("mm\n");
        else
            printf("T\n");
    }
}
