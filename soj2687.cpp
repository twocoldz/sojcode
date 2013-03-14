#include <cstdio>

int main()
{
    int n,a,b;
    while(scanf("%d%d%d",&n,&a,&b)==3)
    {
        (n%(a+b)>=a&&n%(a+b)<=b)?printf("windy7926778\n"):printf("fgjlwj\n");
    }
    return 0;
}
