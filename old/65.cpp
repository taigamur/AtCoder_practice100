#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


/*
0828 ok   連結成分に着目するのが難しかった
連結成分は最初はN個
uniteするごとに1つずつ減っていき、
K個になるまで繰り返せば良い
*/

struct UnionFind{
    vector<int> par,siz;

    UnionFind(int n) : par(n,-1) , siz(n,1){}

    int root(int x){
        if(par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y){
        return root(x) == root(y);
    }

    bool unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return false;

        if(siz[x] < siz[y]) swap(x,y);

        par[y] = x;
        siz[x] += y;
        return true;
    }

    int size(int x){
        return siz[root(x)];
    }
};

using Edge = pair<int, pair<int,int>>;

int main(){
    int N,M,K;
    cin >> N >> M >> K;
    vector<Edge> edges(M);
    for(int i=0; i < M; i++){
        int u,v,w;
        cin >> u >> v >> w;
        u = u-1;
        v = v-1;
        edges[i] = Edge(w,make_pair(u,v));
    }

    sort(edges.begin(),edges.end());

    long long res = 0;
    UnionFind uf(N);
    int components = N;
    for(int i=0;i<M;i++){
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if(components == K) break;
        if(uf.issame(u,v)) continue;
        components--;
        res += w;
        uf.unite(u,v);
    }
    cout << res << endl;
}