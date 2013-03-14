#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    char s[5][128];
    while(scanf("%s",s[0])!=EOF)
    {
        for(int i=1;i<5;i++)
            scanf("%s",s[i]);
        int f=0;
        for(int i=0;i<5;i++)
        {
            int len=strlen(s[i]);
            for(int j=2;j<len;j++)
            {
                if(s[i][j-2]=='F'&&s[i][j-1]=='B'&&s[i][j]=='I')
                {
                    f==0?printf("%d",i+1):printf(" %d",i+1);
                    f++;
                    break;
                }
            }
        }
        if(!f)
        {
            printf("HE GOT AWAY!\n");
        }
        else
            printf("\n");
    }
    return 0;
}
