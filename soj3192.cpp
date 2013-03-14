#include <cstdio>
#include <cstring>
#include <algorithm>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(y/2>=x)
            printf("%d\n",y);
        else
            printf("%d\n",y+x-(y/2));
    }
    return 0;
}
