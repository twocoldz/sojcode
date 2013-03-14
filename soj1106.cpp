#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

char map[22][22];
int dp[22][22];
int n,m;

struct node
{
	friend bool operator< (node a,node b)
	{
		return b.cnt < a.cnt;
	}
	int x,y,cnt;
};

priority_queue <node> q;

void make()
{
	int i,j;
	for(i=1;i<=20;i++)
	{
		for(j=1;j<=20;j++)
		{
			map[i][j]='0';
			dp[i][j]=1000000;
		}
	}
}

bool legal(int x,int y)
{
    if(x==0||x>m||y==0||y>n)
        return false;
    if(map[x][y]=='B')
        return false;
    return true;
}

int main()
{

	node ss,tt;
	int dir[8][2]={1,0,1,1,1,-1,-1,0,-1,-1,-1,1,0,1,0,-1};
	while(scanf("%d%d",&n,&m)==2)
	{
		make();
		int dx,dy,sx,sy,i,j;
		cin>>dx>>dy>>sx>>sy;
		int k,x,y;
		char c;
		cin>>k;
		for(i=0;i<k;i++)
		{
			cin>>x>>y>>c;
			map[x][y]=c;	
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(map[i][j]=='u')
				{
					map[i][j]='B';
					for(k=i-1;k>=1;k--)
					{
						if(map[k][j]!='0'&&map[k][j]!='1')
							break;
						map[k][j]='1';
					}
				}
				if(map[i][j]=='d')
				{
					map[i][j]='B';
					for(k=i+1;k<=m;k++)
					{
						if(map[k][j]!='0'&&map[k][j]!='1')
							break;
						map[k][j]='1';
					}
				}
				if(map[i][j]=='l')
				{
					map[i][j]='B';
					for(k=j-1;k>=1;k--)
					{
						if(map[i][k]!='0'&&map[i][k]!='1')
							break;
						map[i][k]='1';
					}
				}
				if(map[i][j]=='r')
				{
					map[i][j]='B';
					for(k=j+1;k<=n;k++)
					{
						if(map[i][k]!='0'&&map[i][k]!='1')
							break;
						map[i][k]='1';
					}
				}
			}
		}
		ss.x=dx;
		ss.y=dy;
		if(map[dx][dy]!='0')
		{
			cout<<-1<<endl;
			continue;
		}
		dp[ss.x][ss.y]=0;
		ss.cnt=0;
		while(!q.empty())
			q.pop();
		q.push(ss);
		while(!q.empty())
		{
			ss=q.top();
			q.pop();
			if(ss.cnt>dp[ss.x][ss.y])
				continue;
			for(i=0;i<8;i++)
			{
				tt=ss;
				tt.x+=dir[i][0];
				tt.y+=dir[i][1];
				if(!legal(tt.x,tt.y))
					continue;
				if(map[tt.x][tt.y]=='0')
				{
					if(tt.cnt>=dp[tt.x][tt.y])
						continue;
					dp[tt.x][tt.y]=tt.cnt;
					q.push(tt);
				}
				else
				{
					tt.x+=dir[i][0];
					tt.y+=dir[i][1];
					tt.cnt++;
					if(!legal(tt.x,tt.y))
						continue;
					if(map[tt.x][tt.y]!='0')
						continue;
					if(tt.cnt>=dp[tt.x][tt.y])
						continue;
					dp[tt.x][tt.y]=tt.cnt;
					q.push(tt);
				}
			}
		}
		if(dp[sx][sy]!=1000000)
		{
			cout<<dp[sx][sy]<<endl;
		}
		else
			cout<<-1<<endl;
	}
	return 0;
}