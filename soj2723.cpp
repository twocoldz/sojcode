#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(void)
{
    int n;
    int now, last, next;
    while(scanf("%d", &n)==1&&n)
    {
        last = -1, now = 0;
        for (int i = 1; i <= n; i++){
            scanf("%d", &next);
            if (last <= now && now >= next){
                printf("%d\n", i - 1);
            }
            last = now;
            now = next;
        }
        if (now >= last)
        {
            printf("%d\n", n);
        }
    }
    return 0;
}
