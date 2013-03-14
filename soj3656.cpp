#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;
struct node
{
    int a,b;
}e[100005];
int r[100005],f[100005];
bool vis[100005];
long long L;
int m;

bool cmp(node x,node y)
{
    if(x.a==y.a)
        return x.b>y.b;
    return x.a<y.a;
}

int main()
{
    while(scanf("%lld%d",&L,&m)==2)
    {
        int l,flag=0;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&e[i].a,&l);
            e[i].b=e[i].a+l;
            if(l>=L)
            {
                flag=1;
            }
        }
        if(flag)
        {
            printf("1\n");
            continue;
        }
        sort(e+1,e+1+m,cmp);
        //��ȥ���������߶�
        for(int i=1,j=1;j<=m;)
        {
            e[i].a=e[j].a;
            e[i].b=e[j].b;
            while((e[i].b>=e[j].a)&&(e[i].b>=e[j].b)&&(j<=m))
                j++;
            i++;
            if(j>m)
                m=i-1;
        }
        //̰�� �ҵ�ÿ���߶ε���һ������ѡ��
        for(int i=m,j=m;i>=1;i--)
        {
            while(e[i].b<e[j].a&&(j>=1))
                j--;
            r[i]=j;
        }
        int ans=inf;
        for(int i=m;i>=0;i--)
        {
            if(e[i].b<L)//�����֦����Ҫ�����ĩ�˶�����L �Ϳ��Բ�����
                break;
            int t=e[i].b-L;
            f[i]=1;
            for(int j=i-1;j>=1;j--)
            {
                f[j]=f[r[j]]+1;
                if(e[j].a<=t)
                {
                    ans=min(ans,f[j]);
                    break;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
