#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 0909 

struct UnionFind{
    vector<int> par;

    UnionFind(int N) : par(N){
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x){
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return;
        par[rx] = ry;
    }

    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(){
    int N,Q;
    cin >> N >> Q;
    UnionFind tree(N);
    int p[Q],x[Q],y[Q];
    for(int i = 0; i < Q; i++){
        cin >> p[i] >> x[i] >> y[i];
    }
    for(int i = 0; i < Q; i++){
        if(p[i] == 0){
            tree.unite(x[i],y[i]);
        }else{
            if(tree.same(x[i],y[i])){
                cout << "1" << endl;
            }else{
                cout << "0" << endl;
            }
        }
    }
    return 0;
}