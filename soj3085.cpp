#include <iostream>
#include <stack>
#include <cstring>
#include <cstdio>
using namespace std;

int a[100005];
long long sum[100005];
int Left[100005],Right[100005];
int temp[100005]; //保存栈中第i个位置所存的数组下标

int main()
 {
     int n;
     while(scanf("%d",&n)!=EOF&&n)
     {
         int i,j;
         long long ans,Max=0;
         memset(sum,0,sizeof(sum));
         for(i=1;i<=n;i++)
         {
             scanf("%d",&a[i]);
             sum[i]=sum[i-1]+a[i];
         }
         stack<int> v;
         Left[1]=0;
         Right[n]=n+1;
         temp[0]=0;
         temp[1]=1;
         v.push(a[1]);
         for(i=2,j=1;i<=n;i++,j++)   //用单调栈求Left[i]
        {
             while(!v.empty()&&v.top()>=a[i])
             {
                 v.pop();            //删除掉比当前元素大的值
                j--;
             }
             v.push(a[i]);
             temp[j+1]=i;          //记录当前位置压入的数组下标
            Left[i]=temp[j];      //栈中前一个位置的数组下标就是Left[i]的值
        }
         while(!v.empty())
         {
             v.pop();
         }
         v.push(a[n]);
         temp[1]=n;
         temp[0]=n+1;
         for(i=n-1,j=1;i>=1;i--,j++)
         {
             while(!v.empty()&&v.top()>=a[i])
             {
                 v.pop();
                 j--;
             }
             v.push(a[i]);
             temp[j+1]=i;
             Right[i]=temp[j];
         }
         for(i=1;i<=n;i++)
         {
             ans=a[i]*(sum[Right[i]-1]-sum[Left[i]]);
             if(ans>Max)
                 Max=ans;
         }
         cout<<Max<<endl;
     }
     return 0;
 }
