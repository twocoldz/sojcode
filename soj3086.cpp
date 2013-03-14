#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node
{
    int ux,uy,dx,dy;
    int lazy,v;
}tree[1030*4];

void BuildTree(int k,int ux,int uy,int dx,int dy)
{
    tree[k].ux=ux;
    tree[k].uy=uy;
    tree[k].dx=dx;
    tree[k].dy=dy;
    tree[k].v=0;
    tree[k].lazy=0;
    if(ux==dx&&uy==dy)
    {
        return;
    }
    int midx=(ux+dx)>>1;
    int midy=(uy+dy)>>1;
    BuildTree(k*4-2,ux,uy,midx,midy);
    BuildTree(k*4-1,midx+1,uy,dx,midy);
    BuildTree(k*4,ux,midy+1,midx,dy);
    BuildTree(k*4+1,midx+1,midy+1,dx,dy);
}

void Insert(int k,int ux,int uy,int dx,int dy,int v)
{
    if(ux==dx&&uy==dy)
    {
        tree[k].v+=v;
        tree[k].lazy+=v;
        return ;
    }
    if(tree[k].lazy!=0)
    {
        tree[k*4-2].v+=tree[k].lazy;
        tree[k*4-1].v+=tree[k].lazy;
        tree[k*4].v+=tree[k].lazy;
        tree[k*4+1].v+=tree[k].lazy;
        tree[k*4-2].lazy+=tree[k].lazy;
        tree[k*4-1].lazy+=tree[k].lazy;
        tree[k*4].lazy+=tree[k].lazy;
        tree[k*4+1].lazy+=tree[k].lazy;
        tree[k].lazy=0;
    }
    int midx=(tree[k].ux+tree[k].dx)>>1;
    int midy=(tree[k].uy+tree[k].dy)>>1;
    if(dx<=midx&&dy<=midy)
    {
        Insert(k*4-2,ux,uy,dx,dy,v);
    }
    else if(ux>midx&&uy>midy)
    {
        Insert(k*4+1,ux,uy,dx,dy,v);
    }
    else if(dy<=midy)
    {
        Insert(k*4-2,ux,uy,midx,dy,v);
        Insert(k*4-1,midx+1,uy,dx,dy,v);
    }
    else if(uy>midy)
    {
        Insert(k*4,ux,uy,midx,dy,v);
        Insert(k*4+1,midx+1,uy,dx,dy,v);
    }
    else if(dx<=midx)
    {
        Insert(k*4-2,ux,uy,dx,midy,v);
        Insert(k*4,ux,midy+1,dx,midy,v);
    }
    else if(ux>midx)
    {
        Insert(k*4-1,ux,uy,dx,midy,v);
        Insert(k*4+1,ux,midy+1,dx,dy,v);
    }
    else
    {
        Insert(k*4-2,ux,uy,midx,midy,v);
        Insert(k*4-1,midx+1,uy,dx,midy,v);
        Insert(k*4,ux,midy+1,midx,dy,v);
        Insert(k*4+1,midx+1,midy+1,dx,dy,v);
    }
}

int Query(int k,int x,int y)
{
    if(tree[k].ux==tree[k].dx&&tree[k].uy==tree[k].dy&&x==tree[k].ux&&y==tree[k].dy)
    {
        return tree[k].v;
    }
    if(tree[k].lazy!=0)
    {
        tree[k*4-2].v+=tree[k].lazy;
        tree[k*4-1].v+=tree[k].lazy;
        tree[k*4].v+=tree[k].lazy;
        tree[k*4+1].v+=tree[k].lazy;
        tree[k*4-2].lazy+=tree[k].lazy;
        tree[k*4-1].lazy+=tree[k].lazy;
        tree[k*4].lazy+=tree[k].lazy;
        tree[k*4+1].lazy+=tree[k].lazy;
        tree[k].lazy=0;
    }
    int midx=(tree[k].ux+tree[k].dx)>>1;
    int midy=(tree[k].uy+tree[k].dy)>>1;

    if(x<=midx&&y<=midy)
    {
        Query(k*4-2,x,y);
    }
    else if(x>midx&&y<=midy)
    {
        Query(k*4-1,x,y);
    }
    else if(x<=midx,y>midy)
    {
        Query(k*4,x,y);
    }
    else
    {
        Query(k*4+1,x,y);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        BuildTree(1,1,1,n,n);
        int x0,x1,y0,y1,v;
        char c[3];
        while(q--)
        {
            scanf("%s",c);
            if(c[0]=='i')
            {
                scanf("%d%d%d%d%d",&x0,&y0,&x1,&y1,&v);
                x0++,y0++,x1++,y1++;
                Insert(1,x0,y0,x1,y1,v);
            }
            else if(c[0]=='a')
            {
                scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
                x0++,y0++,x1++,y1++;
            }
            else
            {
                scanf("%d%d",&x0,&y0);
                x0++,y0++;
                printf("%d\n",Query(1,x0,y0));
            }
        }
    }
    return 0;
}
