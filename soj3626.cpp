#include <cstdio>

int main()
{
    int a,b;
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d",&a,&b);
        printf("%.04lf\n",(double)a/(a+b+b));
    }
    return 0;
}
