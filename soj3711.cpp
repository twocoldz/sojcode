/*��Ŀ��˼��˵��һ��·������ ���Ҹ�����һЩ��Ҫ������·������ÿһ�ߣ��㲻�ܸı䳵�ĳ���˳��
��ֻ�ܸı�ĳһʱ�̣�����߷����������ұ߷�����
dp[i][j][K]��ʾ��߹���I�����ұ߹���J����K=0��ʾ���һ������߿����ģ�K=1��ʾ���ұ߿�����
����Ŀ��˼�����������ͬ�����һ�����ĳ���ʱ��ΪST=MAX(�������ʱ�䣬ǰһ��������ʱ��+10����
��һ�����ĵ���ʱ��ΪMAX(ǰһ��������ʱ��+10��ST����

��������ֱ����dp[i][j][0]��dp[I][J][1]�ֱ�������DP[I+1][J][0]��DP[I][J+1][1]��
���������Ժ���һ�����⣬����м���������ͬ�򣬵�ǰ���ĳ���ʱ��û��ȷ����
��Ϊ��ǰ���ĳ���ʱ���ǰ��һ�����йأ���ǰ��һ�����ĳ���ʱ����ܸ���ǰ��һ���йء�
���������У�
A 0 100
B 50 100
A 100 1
A 170 100

�������ǲ����ڶ���������ô��һ������100��ʱ�򵽴��������������110��ʱ�򵽴���ǵ��������������ʱ����10������
�Ӷ�����������20��ʱ��Ϳ��Գ����ˡ�
������ҵķ���������ô����Ϊ���������ĳ���ʱ����109����������������Ҫ219��ʱ����ܵ���

�Ľ�������
��dp[I][J][0]������DP[I][J+X][1],��DP[I][J][1]������DP[I+X][J][0]����ʾͬһ��������������X������*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;
int dp[205][205][2];
struct node
{
    int t,d;
}l[205],r[205];

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n,t,d;
        int a=0,b=0;
        char dir[2];
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%s %d %d",dir,&t,&d);
            if(dir[0]=='A')
            {
                l[++a].t=t;
                l[a].d=d;
            }
            else
            {
                r[++b].t=t;
                r[b].d=d;
            }
        }
        memset(dp,inf,sizeof(dp));
        dp[0][0][0]=dp[0][0][1]=0;
        int bt;
        for(int i=0;i<=a;i++)
        {
            for(int j=0;j<=b;j++)
            {
                if(dp[i][j][0]!=inf)
                {
                    bt=max(dp[i][j][0],r[j+1].t);
                    dp[i][j+1][1]=min(dp[i][j+1][1],bt+r[j+1].d);
                    //printf("dp[%d][%d]=%d\n",i,j+1,dp[i][j+1][1]);
                    for(int k=j+2;k<=b;k++)
                    {
                        bt=max(bt+10,r[k].t);
                        int tt=max(bt+r[k].d,dp[i][k-1][1]+10);
                        dp[i][k][1]=min(dp[i][k][1],tt);
                    }
                }
                if(dp[i][j][1]!=inf)
                {
                    bt=max(dp[i][j][1],l[i+1].t);
                    dp[i+1][j][0]=min(dp[i+1][j][0],bt+l[i+1].d);
                    //printf("dp[%d][%d]=%d\n",i+1,j,dp[i+1][j][0]);
                    for(int k=i+2;k<=a;k++)
                    {
                        bt=max(bt+10,l[k].t);
                        int tt=max(bt+l[k].d,dp[k-1][j][0]+10);
                        dp[k][j][0]=min(dp[k][j][0],tt);
                    }
                }
            }
        }
        int ans=min(dp[a][b][0],dp[a][b][1]);
        printf("%d\n",ans);
    }
    return 0;
}
