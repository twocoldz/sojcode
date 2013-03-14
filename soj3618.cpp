#include <stdio.h>

int main()
{
    char a[100],b[100];
    while(1)
    {
        gets(a);
        gets(b);
        if(a[0]=='E')
            break;
        int n=0,m=0,i;
        for(i=0;a[i];i++)
        {
            if(a[i]=='R')
            {
                if(b[i]=='P')
                    m++;
                else if(b[i]=='S')
                    n++;
            }
            else if(a[i]=='P')
            {
                if(b[i]=='S')
                    m++;
                else if(b[i]=='R')
                    n++;
            }
            else
            {
                if(b[i]=='R')
                    m++;
                else if(b[i]=='P')
                    n++;
            }
        }
        printf("P1: %d\n",n);
        printf("P2: %d\n",m);
    }
    return 0;
}
