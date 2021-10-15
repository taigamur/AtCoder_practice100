#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
1015 AC
*/

//UnionFind
struct UnionFind{
    vector<int> par,siz;

    //初期化
    UnionFind(int n) : par(n,-1),siz(n,1){}
    //根を求める
    int root(int x){
        if(par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }
    //x,yが同じグループかどうか
    bool issame(int x, int y){
        return root(x) == root(y);
    }
    //xを含むグループとyを含むグループを合併
    bool unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return false;
        //union by size (y側のサイズが小さくなるように)
        if(siz[x] < siz[y]) swap(x,y);
        //yをxの子とする
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }
    //xを含むグループのサイズ
    int size(int x){
        return siz[root(x)];
    }
};

using Edge = pair<int,pair<int,int>>;

int main(){
    int V,E;
    cin >> V >> E;

    vector<Edge> edges(E);
    for(int i = 0; i < E; i++){
        int s,t,w;
        cin >> s >> t >> w;
        edges[i] = Edge(w,make_pair(s,t));
    }

    //各辺を重みが小さい順にソート
    sort(edges.begin(),edges.end());

    //クラスカル法
    long long ans = 0;
    UnionFind uf(V);
    for(int i = 0; i < E; i++){
        int w = edges[i].first;
        int s = edges[i].second.first;
        int t = edges[i].second.second;

        if(uf.issame(s,t)) continue;

        ans += w;
        uf.unite(s,t);
    }
    cout << ans << endl;
}