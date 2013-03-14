#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define ForAll(it,set) for(typeof(set.begin()) it = set.begin(); it!=set.end();++it)

typedef vector<int> vi;
vi edges[50010];
int size[50010];
typedef long long ll;
typedef pair<int,ll> pll;
typedef vector<pll> vll;
#define depth first
#define cost second

bool bySize (int a, int b){return size[a]<size[b];}


void root(int a, int parent = -1)
{
    int treeSize = 1;
    for(int i=0; i<edges[a].size(); ){
        if(edges[a][i] == parent){
            edges[a][i] = edges[a].back();
            edges[a].pop_back();
        }
        else{
            root(edges[a][i], a);
            treeSize += size[edges[a][i]];
            ++i;
        }
    }
    size[a] = treeSize;
    sort(edges[a].begin(),edges[a].end(),bySize);

}
ll sqr(ll a)
{
    return a*a;
}
vll getSolutions(vi& a)
{
    if(a.empty())
    {
        return vll(1, pll(0,0));
    }
    vll solutions = getSolutions(edges[a[0]]);
    for(int i=0;i<solutions.size();i++)
        ++solutions[i].depth;
    if(a.size()==1)
    {
        int last = 0;
        for(int i=1;i<solutions.size();i++)
            if(solutions[i].cost+ sqr(solutions[i].depth) <solutions[last].cost + sqr(solutions[last].depth))
                solutions[++last] = solutions[i];
        solutions.resize(last+1);
    }
    for(int k=1;k<a.size();k++)
    {

        vll next = getSolutions(edges[a[k]]);
        for(int i=0;i<next.size();i++)
            ++next[i].depth;
        vll nextSolutions;
        nextSolutions.reserve(3*solutions.size()*next.size());

        for(typeof(solutions.begin()) A = solutions.begin(); A!=solutions.end();++A)
        {
            for(typeof(next.begin()) B = next.begin(); B!=next.end();++B)
            {
                if(A->depth == 0)
                    nextSolutions.push_back(pll(0, A->cost + B->cost + sqr(B->depth)));
                else {
                    nextSolutions.push_back(pll(A->depth,A->cost + B->cost + sqr( B->depth) ));
                    nextSolutions.push_back(pll(B->depth,A->cost + B->cost + sqr(A->depth)));
                    nextSolutions.push_back(pll(0, A->cost + B->cost + sqr(A->depth+B->depth)));
                }

            }
        }
        sort(nextSolutions.begin(),nextSolutions.end());
        int last = 0;
        for(int i=1;i<nextSolutions.size();i++)
            if(nextSolutions[i].cost+ sqr(nextSolutions[i].depth) <nextSolutions[last].cost + sqr(nextSolutions[last].depth))
                nextSolutions[++last] = nextSolutions[i];
        nextSolutions.resize(last+1);
        swap(solutions,nextSolutions);
    }
    return solutions;

}


int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<=n;i++)
        {
            edges[i].clear();
        }
         for(int i=1;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        const int ROOT = 1;
        root(1);
        vll viable = getSolutions(edges[ROOT]);
        ll best = 999999999999LL;
        const int rootSize = edges[ROOT].size();
        for(int i=0;i<viable.size();i++)
        {
            if(viable[i].depth == 0 || rootSize <= 1)
                best = min(best, viable[i].cost + sqr(viable[i].depth));
        }
        cout<<best<<endl;
    }
    return 0;
}
