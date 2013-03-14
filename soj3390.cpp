#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
char cd[27];
char s[1005];

int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    int cases=1;
    while(t--)
    {
        gets(s);
        gets(cd);
        int len=strlen(s);
        printf("%d ",cases++);
        for(int i=0;i<len;i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                printf("%c",cd[s[i]-'A']);
            }
            else
                printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}
