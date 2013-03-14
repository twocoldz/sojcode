#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char str[100005];

int MinString(int n)
{
    int i=0,j=1,k=0;
    while(i<n&&j<n&&k<n)
    {
        if(str[(i+k)%n]==str[(j+k)%n])
        {
            k++;
        }
        else
        {
            int t=str[(i+k)%n]-str[(j+k)%n];
            if(t>0)
            {
                i=i+k+1;
            }
            else
            {
                j=j+k+1;
            }
            if(i==j)
            {
                ++j;
            }
            k=0;
        }
    }
    return (i<j?i:j);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        int len=strlen(str);
        int pos=MinString(len);
        for(int i=pos;i<pos+len;i++)
        {
            printf("%c",str[i%len]);
        }
        printf("\n");
    }
    return 0;
}
