#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

struct node
{
    int t;
    bool operator < (const node &a) const
    {
        return t>a.t;
    }
} a[100005];

void swap(int i,int j)
{
    node temp;
    temp.t=a[i].t;
    a[i].t=a[j].t;
    a[j].t=temp.t;
}

int Position(int l,int r)
{
    int x=a[r].t;
    int i=l-1;
    for(int j=l;j<r;j++)
    {
        if(a[j].t>=x)
        {
            i++;
            swap(i,j);
        }
    }
    i++;
    swap(i,r);
    return i;
}

void Sort(int l,int r)
{
    if(l>=r)
        return ;
    int p=Position(l,r);
    Sort(l,p-1);
    Sort(p+1,r);
}


int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n,m;
        while(scanf("%d%d",&n,&m)==2)
        {
            priority_queue<node> v;
            for(int i=1;i<=n;i++)
            {
                scanf("%d",&a[i].t);
            }
            if(n<m)
            {
                printf("0\n");
                continue;
            }
            //Sort(1,n);
            for(int i=1;i<=m;i++)
            {
                //printf("%d\n",a[i].t);
                v.push(a[i]);
            }
            node temp;
            int flag=1;
            for(int i=m+1;i<=n;i++)
            {
                temp=v.top();
                //printf("%d\n",temp.t);
                v.pop();
                temp.t+=a[i].t;
                if(temp.t>600)
                {
                    flag=0;
                    break;
                }
                v.push(temp);
            }
            if(!flag)
            {
                printf("-1\n");
                continue;
            }
            temp=v.top();
            printf("%d\n",temp.t);
        }
    }
    return 0;
}
