#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>

#define D 0
#define U 1

using namespace std;
stack<int> ss[105];
int pos[105],face[105];

int main()
{
    int n;
    int cases=1;
    char st[105],op[105];
    while(scanf("%d",&n)&&n)
    {
        scanf("%s",st);
        scanf("%s",op);
        for(int i=0;i<n;i++)
        {
            while(!ss[i+1].empty())
                ss[i+1].pop();
            ss[i+1].push(i+1);
            if(st[i]=='U')
                face[i+1]=U;
            else
                face[i+1]=D;
        }
        int L=1,R=n;
        for(int i=0;i<n-1;i++)
        {
            if(op[i]=='L')
            {
                while(!ss[L].empty())
                {
                    int t=ss[L].top();
                    ss[L].pop();
                    ss[L+1].push(t);
                    face[t]^=1;
                }
                L++;
            }
            else
            {
                while(!ss[R].empty())
                {
                    int t=ss[R].top();
                    ss[R].pop();
                    ss[R-1].push(t);
                    face[t]^=1;
                }
                R--;
            }
        }
        int i=1;
        while(!ss[L].empty())
        {
            int t=ss[L].top();
            ss[L].pop();
            pos[i++]=t;
        }
        scanf("%d",&n);
        int x;
        printf("Pile %d\n",cases++);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            if(face[pos[x]])
            {
                printf("Card %d is a face up %d.\n",x,pos[x]);
            }
            else
            {
                printf("Card %d is a face down %d.\n",x,pos[x]);
            }
        }
    }
    return 0;
}
