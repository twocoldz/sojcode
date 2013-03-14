#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
 {
     int v,nxt;
 }edge[10005],q[500005];
const int N=50005;
int heade[N],headq[N];
int ans[N],fa[N],indeg[N];
int num[N];
bool vis[N];
int n,m,e;

void Init()
 {
     e=0;
     memset(heade,-1,(n+1)*sizeof(heade[0]));
     memset(headq,-1,(n+1)*sizeof(headq[0]));
     memset(vis,0,(n+1)*sizeof(vis[0]));
     memset(ans,-1,sizeof(ans));
     memset(num,0,(n+1)*sizeof(num[0]));
     for(int i=1;i<=n;i++)
             fa[i]=i,indeg[i]=0;
 }

void AddEdge(int u,int v)
 {
     edge[e].v=v;
     edge[e].nxt=heade[u];
     heade[u]=e++;
 }

void AddQuery(int u,int v)
 {
     q[e].v=v;
     q[e].nxt=headq[u];
     headq[u]=e++;
 }

int FindFa(int x)
 {
     if(fa[x]!=x)
     {
         fa[x]=FindFa(fa[x]);
     }
     return fa[x];
 }

void tarjan(int u)
 {
     vis[u]=1;
     for(int i=headq[u];~i;i=q[i].nxt)
     {
         int v=q[i].v;
         if(vis[v]&&ans[i>>1]==-1)
         {
             ans[i>>1]=FindFa(v);
             num[ans[i>>1]]++;
         }
     }

     for(int i=heade[u];~i;i=edge[i].nxt)
     {
         int v=edge[i].v;
         if(!vis[v])
         {
             tarjan(v);
             fa[v]=u;
         }
     }
 }

int main()
 {
     char str[100];
     while(scanf("%d",&n)==1)
     {
         int k,a,b;
         Init();
         for(int i=1;i<=n;i++)
         {
             scanf("%d:(%d)",&a,&k);
             while(k--)
             {
                 scanf("%d",&b);
                 indeg[b]++;
                 AddEdge(a,b);
                 AddEdge(b,a);
             }
         }

         scanf("%d",&m);
         e=0;
         for(int j=0;j<m;j++)
         {
             scanf("%s",str);
             a=b=0;
             int i=1;
             while(str[i]>='0'&&str[i]<='9')
                 a=a*10+str[i]-48,i++;
             i++;
             while(str[i]>='0'&&str[i]<='9')
                 b=b*10+str[i]-48,i++;
             AddQuery(a,b);
             AddQuery(b,a);
         }
         int root;
         for(int i=1;i<=n;i++)
             if(indeg[i]==0)
             {
                 root=i;
                 break;
             }
         tarjan(root);
         for(int i=1;i<=n;i++)
             if(num[i])
                 printf("%d:%d\n",i,num[i]);
     }
     return 0;
 }
