#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n;
        scanf("%d",&n);
        char s[4];
        int a=108-n;
        int b=27;
        while(n--)
        {
            scanf("%s",s);
            if(s[0]=='H')
                b--;
        }
        printf("%lf\n",1.0*b/a);
    }
    return 0;
}
