#include <stdio.h>

int main()
{
    int cases;
    scanf("%d",&cases);
    int a[51],b[51];
    while(cases--)
    {
        int n,i;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",a+i),b[n-i-1]=a[i];
        int f=0;
        for(i=1;i<=(n-1)/2;i++)
        {
            int j;
            for(j=0;j<i;j++)
            {
                if(a[j]!=a[i+j])
                    break;
            }
            if(j==i)
            {
                f=1;
                break;
            }
        }
        for(i=1;f==0&&i<=(n-1)/2;i++)
        {
            int j;
            for(j=0;j<i;j++)
            {
                if(b[j]!=b[i+j])
                    break;
            }
            if(j==i)
            {
                f=1;
                break;
            }
        }
        if(f)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
