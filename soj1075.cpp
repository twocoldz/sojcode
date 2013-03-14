#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int rudu[26];
bool show[26];
bool big[26][26];

char GetChar()
{
	char c;
	while((c=getchar())&&(c=='\n'||c==' '));
	return c;
}

int main()
{
	int n;
	while(scanf("%d",&n)==1&&n)
	{
		int i,j;
		char x,y;
		memset(rudu,0,sizeof(rudu));
		memset(big,0,sizeof(big));
		memset(show,0,sizeof(show));
		for(i=1;i<=n;i++)
		{
			x=GetChar();
			y=GetChar();
			show[x-'A']=1;
			show[y-'A']=1;
			rudu[y-'A']++;
			big[x-'A'][y-'A']=1;
		}
		int flag=0;
		for(i=0;i<26;i++)
		{
			for(j=0;j<26;j++)
			{
				if(show[j]&&rudu[j]==0)
				{
					flag==0?printf("%c",j+'A'):printf(" %c",j+'A');
					for(int k=0;k<26;k++)
					{
						if(show[k]&&big[j][k])
						{
							rudu[k]--;
						}
					}
					show[j]=0;
					flag=1;
					break;
				}
			}
		}
		printf("\n");
	}
	return 0;
}

//bool a[27][27];
//bool show[27];
//struct node
//{
//	int sum;
//	int pos;
//}jilu[27];
//
//bool cmp(node a,node b)
//{
//	return a.sum>b.sum;
//}
//
////void Updata(int x,int y)
////{
////	for(int i=0;i<26;i++)
////	{
////		if(a[i][x])
////		{
////			a[i][y]=1;
////			Updata(i,y);
////		}	
////	}
////}
//

//
//int main()
//{
//	int n;
//	while(scanf("%d",&n)==1&&n)
//	{
//		char x,y;
//		int i,j;
//		memset(a,0,sizeof(a));
//		memset(show,0,sizeof(show));
//		for(i=0;i<26;i++)
//		{
//			jilu[i].sum=0;
//			jilu[i].pos=i;
//		}
//		for(i=1;i<=n;i++)
//		{
//			x=GetChar();
//			y=GetChar();
//			show[x-'A']=true;
//			show[y-'A']=true;
//			a[x-'A'][y-'A']=1;
//			for(j=0;j<26;j++)
//			{
//				if(a[j][x-'A'])
//				{
//					a[j][y-'A']=1;
//					//Updata(j,y-'A');
//				}
//				if(a[y-'A'][j])
//				{
//					a[x-'A'][j]=1;
//				}
//			}
//		}
//		for(i=0;i<26;i++)
//		{
//			if(!show[i])
//				continue;
//			for(j=0;j<26;j++)
//			{
//				if(a[i][j])
//				{
//					jilu[i].sum++;
//				}
//			}
//		}
//		sort(jilu,jilu+26,cmp);
//		int flag=0;
//		for(i=0;i<26;i++)
//		{
//			if(show[jilu[i].pos])
//			{
//				flag==0?printf("%c",jilu[i].pos+'A'):printf(" %c",jilu[i].pos+'A');
//				flag=1;
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}
