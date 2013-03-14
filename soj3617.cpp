#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    printf("Gnomes:\n");
    while(n--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if((a<b&&b<c)||(a>b&&b>c))
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }
    return 0;
}
