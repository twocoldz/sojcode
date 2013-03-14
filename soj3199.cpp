#include <cstdio>
#include <cstring>
#include <algorithm>

int main()
{
    int cases;
    char s[1005];
    scanf("%d",&cases);
    while(cases--)
    {
        int a=0,b=0;
        scanf("%s",s);
        for(int i=0;s[i];i++)
        {
            if(s[i]=='*')
                a++;
            else if(s[i]=='?')
                b++;
            else
            {
                if(a)
                    printf("*");
                for(int j=0;j<b;j++)
                {
                    printf("?");
                }
                printf("%c",s[i]);
                a=0,b=0;
            }
        }
        if(a)
            printf("*");
        for(int j=0;j<b;j++)
        {
            printf("?");
        }
        printf("\n");
    }
    return 0;
}
