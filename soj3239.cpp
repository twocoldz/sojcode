#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char str[81];
    int t,pos;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d %s",&pos,str);
        printf("%d ",i);
        for(int j=0;j<strlen(str);j++)
        {
            if(j+1!=pos)
                printf("%c",str[j]);
        }
        printf("\n");
    }
    return 0;
}
