#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
0909 ok 解き方の発想が難しかった
*/

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
    int N,M;
    cin >> N >> M;
    int A[101], B[101];

    for(int i = 0; i < M; i++){
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }

    int ans = 0;
    //i番目の橋を無視して考える
    for(int i = 0; i < M; i++){
        UnionFind uf(N);
        //辺の結合
        for(int j = 0; j < M; j++){
            if(j != i) uf.unite(A[j],B[j]);
        }
        int c = 0;
        for(int j = 0; j < N; j++){
            if(j == uf.root(j)) c++;
        }
        if(1 < c) ans++;
    }
    cout << ans << endl;
}