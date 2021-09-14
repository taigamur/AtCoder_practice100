#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60;
/*
巡回セールスマン問題
最短路は閉路になっているため、どの頂点からはじめても問題ない

dp[S][v] これまでどの都市を訪問したかの集合Sと今いる都市v
S-vに至るまでの最小コスト
dp[Sall][0]を求めれば良い

都市1,3,4を訪問した場合、
S={1,3,4} = 0011010となる
*/ 

struct Edge{
    int to;
    long long w;
    Edge(int to, long long w) : to(to), w(w){}
};
using Graph = vector<vector<Edge> >;

template<class T> void chmin(T& a, T b){
    if(a > b){
        a = b;
    }
}

int main(){
    
    int V,E;
    cin >> V >> E;
    Graph G(V);
    for(int i=0;i<E;i++){
        int f,to,w;
        cin >> f >> to >> w;
        G[f].push_back(Edge(to,w));
        if(to == 0){
            G[f].push_back(Edge(V,w));
        }
    }

    vecotr<vector<long long> > dp((1<<V))(V,INF);
    // 00...0 から　11...1　までのビット列を考える
    // 訪問済みが1 未訪問が0
    // >>  << は右シフト,左シフトを示している
    dp[0][0] = 0;
    for(int i=1; i < (1 << V); i++){
        for(int j=0; j<v; j++){
            if((i >> j) & 1){

                for(int k=0;k<n;k++){
                    long long t = i - (1 << j);
                    if(t >> j & 1 || t == 0){
                        dp[i][j] = min(dp[i][j],dp[t][j] + G[j][])
                    }
                }
                
            }
        }
    }

}