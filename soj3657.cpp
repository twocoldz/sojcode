#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

int main()
{
    int n;
    int Bx,By,Gx,Gy;
    while(scanf("%d",&n)==1&&n)
    {
        map<int,set<int> > x,y;
        scanf("%d%d%d%d",&Bx,&By,&Gx,&Gy);
        int a,b;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            x[a].insert(b);
            y[b].insert(a);
        }
        int ans;
        set<pair<int,int> > vis;
        vis.insert(make_pair(Bx,By));
        queue<pair<pair<int,int>,int> > q;
        q.push(make_pair(make_pair(Bx,By),0));
        while(!q.empty())
        {
            int tx=q.front().first.first;
            int ty=q.front().first.second;
            int tt=q.front().second;
            q.pop();
            map<int,set<int> >::iterator ix,iy;
            ix=x.find(tx);
            iy=y.find(ty);
            set<int>::iterator it;

            if(ix!=x.end())
            {
                it=ix->second.upper_bound(ty);
                if(it!=ix->second.end())
                {
                    if(vis.find(make_pair(tx,*it-1))==vis.end())   //�ӵ�ǰλ����y���������ߣ������ĵ�һ��ʯͷ
                    {
                        if(tx==Gx&&(*it-1)==Gy)
                        {
                            ans=tt+1;
                            break;
                        }
                        q.push(make_pair(make_pair(tx,*it-1),tt+1));
                        vis.insert(make_pair(tx,*it-1));
                    }
                }
                if(it!=ix->second.begin())                      ////�ӵ�ǰλ����y�Ḻ�����ߣ������ĵ�һ��ʯͷ
                {
                    it--;
                    if(vis.find(make_pair(tx,*it+1))==vis.end())
                    {
                        if(tx==Gx&&(*it+1)==Gy)
                        {
                            ans=tt+1;
                            break;
                        }
                        q.push(make_pair(make_pair(tx,*it+1),tt+1));
                        vis.insert(make_pair(tx,*it+1));
                    }
                }
            }
            if(iy!=y.end())
            {
                it=iy->second.upper_bound(tx);
                if(it!=iy->second.end())
                {
                    if(vis.find(make_pair(*it-1,ty))==vis.end())       //ͬ�ϣ�ֻ��x��y���ϵת��һ��
                    {
                        if(ty==Gy&&(*it-1)==Gx)
                        {
                            ans=tt+1;
                            break;
                        }
                        q.push(make_pair(make_pair(*it-1,ty),tt+1));
                        vis.insert(make_pair(*it-1,ty));
                    }
                }
                if(it!=iy->second.begin())
                {
                    it--;
                    if(vis.find(make_pair(*it+1,ty))==vis.end())   //ͬ��
                    {
                        if(ty==Gy&&(*it+1)==Gx)
                        {
                            ans=tt+1;
                            break;
                        }
                        q.push(make_pair(make_pair(*it+1,ty),tt+1));
                        vis.insert(make_pair(*it+1,ty));
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
