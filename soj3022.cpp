#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

//#define max(a,b) a>b?a:b
//#define min(a,b) a<b?a:b
#define appear(x) show[x+100000]
using namespace std;

int num[200005];
int lg[200005]; //��¼��num[i]Ϊ��β��perfetc���ĳ���
int rep[200005];//��¼��num[i]Ϊ��β�Ĵ��������ظ���λ��
bool show[2000005];//��¼��ĿǰΪֹ��ĳ�����Ƿ���ֹ�

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&n)
    {
        int L,R,i,k;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
        }
        memset(show,0,sizeof(show));
        lg[1]=1;
        rep[1]=0;
        appear(num[1])=true;
        for(i=2;i<=n;i++)
        {
            if(!appear(num[i]))
            {
                appear(num[i])=true;
                lg[i]=lg[i-1]+1;
                rep[i]=rep[i-1];
            }
            else
            {
                k=i-lg[i-1];
                while(num[k]!=num[i])
                {
                    appear(num[k])=false;
                    k++;
                }
                lg[i]=i-k;
                rep[i]=i;
            }
        }

        int ans;
        while(m--)
        {
            ans=0;
            scanf("%d%d",&L,&R);
            L++;
            R++;
            while(true)
            {
                if(R-L+1<=ans)
                    break;
                ans=max(ans,min(lg[R],R-L+1));
                R=rep[R]-1;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
