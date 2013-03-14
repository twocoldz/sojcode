#include <iostream>
#include<cstring>
#include<cstdio>
#include <algorithm>

#define MAX 8005

struct nodes
{
   int l,r;
   int len;
}tree[MAX*4];

int cow[MAX];
int num[MAX];

 void BuildTree( int root, int left, int right )
 {
       tree[root].l = left;
       tree[root].r = right;
       tree[root].len= right-left+1;
       if( left == right )
           return ;
       int mid = ( left + right )>>1;
       BuildTree( root*2, left,mid );
       BuildTree( root*2+1, mid+1, right );
 }

 int Query( int root, int m )
 {
   tree[root].len--;
   if( tree[root].l == tree[root].r )
       return tree[root].l;
   else if( m <= tree[ root*2 ].len )
       return Query( root*2, m );
   else
       return Query( root*2+1, m-tree[root*2].len );
 }

int main()
{
   int n;
   int i;
   while( scanf( "%d", &n ) != EOF ){
       for( i=1; i<n; i++ )
           scanf( "%d", &cow[i] );
       BuildTree( 1,1,n );
       for( i=n-1; i>=1; i-- )
           num[i] = Query( 1, cow[i]+1 );
       num[0] = Query( 1,0+1 );
       for( i=0; i<n; i++ )
           printf( "%d\n", num[i] );
   }
   return 0;
 }
