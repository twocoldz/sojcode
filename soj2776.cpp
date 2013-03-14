#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

struct node
{
	int x0,x1,y0,y1;
	int mi;
	int child[4];
}tree[305*305*4];

int num[305][305],n;
int ind;

void BuildTree(int k,int x0,int x1,int y0,int y1)
{
	tree[k].x0=x0;
	tree[k].x1=x1;
	tree[k].y0=y0;
	tree[k].y1=y1;
	tree[k].mi=0x7fffffff;
	if(x0==x1&&y0==y1)
	{
		tree[k].mi=num[x0][y0];
	}
	else
	{
		int midx=(x0+x1)>>1;
		int midy=(y0+y1)>>1;
		tree[k].child[0]=++ind;
		BuildTree(ind,x0,midx,y0,midy);
		tree[k].child[1]=++ind;  
        BuildTree(ind,midx<x1?midx+1:x1,x1,y0,midy);  
        tree[k].child[2]=++ind;  
        BuildTree(ind,x0,midx,midy+1<y1?midy+1:y1,y1);  
        tree[k].child[3]=++ind;  
        BuildTree(ind,midx+1<x1?midx+1:x1,x1,midy+1<y1?midy+1:y1,y1);
		tree[k].mi=tree[tree[k].child[0]].mi;
		for(int i=1;i<4;i++)
		{
			if (tree[tree[k].child[i]].mi<tree[k].mi)
			{
				tree[k].mi=tree[tree[k].child[i]].mi;
			}
		}
	}
}

int Query(int k,int x0,int x1,int y0,int y1)
{
	if(x0>tree[k].x1||x1<tree[k].x0||y0>tree[k].y1||y1<tree[k].y0)   
        return 0x7fffffff;  
	
    if(x0<=tree[k].x0 && tree[k].x1<=x1&&y0<=tree[k].y0 && tree[k].y1<= y1)  
        return tree[k].mi;  
    int i;  
    int Min = 0x7fffffff;  
    for(i = 0; i < 4; i++)   
    {  
        int t = Query(tree[k].child[i], x0, x1, y0, y1);  
        if(t < Min)  
            Min = t;  
    }  
    return Min;  
}

int main()
{
	int t,i,j,q,x0,x1,y0,y1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				scanf("%d",&num[i][j]);
		}
		ind=0;
		BuildTree(0,1,n,1,n);
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
			printf("%d\n",Query(0,x0,x1,y0,y1));
		}
	}
	return 0;
}