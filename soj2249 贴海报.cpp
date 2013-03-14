#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
struct node
{
		int r,l;
		int c;
}tree[10*10010];
int n;
int l[10010][2];
int flag[10010*2];
int num;
struct point
{
		int p;
		int num;
}po[2*10010];
int cmp(const void * a,const void *b)
{
		point *p1 =(point *)a;
		point *p2 = (point *)b;
		
		return p1->p-p2->p;
}
void build(int l,int r,int pos)
{
		if(l==r)
		{
				tree[pos].l=l;
				tree[pos].r=r;
				tree[pos].c=0;
				return;
		}
		tree[pos].l=l;
		tree[pos].r=r;
		tree[pos].c=0;
		int mid =(l+r)/2;
		build(l,mid,2*pos);
		build(mid+1,r,2*pos+1);
}
void insert(int l,int r,int p,int c)
{
		if(l==tree[p].l && r== tree[p].r)//��Ϳ��ɫ��ȫ���Ǵ˽ڵ㣨�߶Σ�
		{
				tree[p].c=c;
				return;
		}
		if(tree[p].c>0 && tree[p].c!=c)//Ϊ��ȫ���ǣ��ȸ�����������Ϊ֮ǰ������δ��Ϳɫ����Ϊ֮ǰtree[p].c>)������һ����ɫ��ȫ���ǣ�����֮ǰֻ���£�Ϳɫ������Ϊֹ��������Ҫ���´˽ڵ㲿����ɫ��Ӧ�ȡ�ͬ������������Ϊ֮��Ҫ����������и��£�
		{
				tree[2*p].c = tree[p].c;
				tree[2*p+1].c=tree[p].c;
				tree[p].c=0;
		}
		//����������и���
		int mid = (tree[p].l+tree[p].r)>>1;
		if(l>mid)
		{
				insert(l,r,2*p+1,c);
		}
		else if(r<=mid)
		{
				insert(l,r,2*p,c);
		}
		else
		{
				insert(l,mid,2*p,c);
				insert(mid+1,r,2*p+1,c);
		}
}
void search(int p)
{
		if(tree[p].c>0)
		{
			   	if(flag[tree[p].c]==0)//����������ȫ���ǵĶ�Ϊֹ��c>0��
				{
						num++;
						flag[tree[p].c]=1;
				}
				return;
		}
		if(tree[p].l==tree[p].r)
				return;
		search(2*p);
		search(2*p+1);
}
int main()
{
		int t =0;
		while(scanf("%d",&t)!=EOF)
		{
		int i =0;
		while(t--)
		{
				memset(tree,0,sizeof(tree));
				memset(flag,0,sizeof(flag));
				memset(po,0,sizeof(po));
				memset(l,0,sizeof(l));
				num=0;
				scanf("%d",&n);
				for(i=1;i<=n;i++)
				{
						scanf("%d",&l[i][0]);
						po[2*i-1].p=l[i][0];
						po[2*i-1].num=-1*i;
						scanf("%d",&l[i][1]);
						po[2*i].p=l[i][1];
						po[2*i].num=i;
				}
				//��ɢ��
				qsort(po+1,2*n,sizeof(point),cmp);
				int tp =1;//��¼�ж��ٲ�ͬ�ĵ㣨��ɢ��1��tp����
				int tmp = po[1].p;
				for(i=1;i<=2*n;i++)
				{
						if(tmp != po[i].p)//�����ظ���ֵ	
						{
								tp++;
								tmp=po[i].p;
						}
						if(po[i].num>0)
							l[po[i].num][1]=tp;
						else
							l[-1*po[i].num][0]=tp;
				}
				build(1,tp,1);
				for(i=1;i<=n;i++)
				{
						insert(l[i][0],l[i][1],1,i);
				}
				search(1);
				printf("%d/n",num);
		}
		}
}