#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60; //十分に大きな値
/*
この実装の場合だと計算量がO(V^2)で判定が通らない
*/

struct Edge{
    int to;//隣接頂点
    long long w;
    Edge(int to, long long w) : to(to), w(w){}
};
//using Graph = vector<vector<Edge>>;

//緩和
template<class T> void chmin(T& a, T b){
    if(a > b){
        a = b;
    }
}

int main(){
    int V,E,r;
    cin >> V >> E >> r;
    
    vector<vector<Edge>> G(V);
    for(int i=0; i < E; i++){
        int a,b,c;
        cin >> a >> b >> c;
        G[a].push_back(Edge(b,c));
    }

    //ダイクストラ法
    vector<bool> used(V,false);
    vector<long long> dist(V,INF);
    dist[r] = 0;

    for(int i=0; i < V; i++){
        long long min_dist = INF;
        int min_v = -1;
        for(int j=0;j<V;j++){
            if(!used[j] && dist[j] < min_dist){
                min_v = j;
                min_dist = dist[j];
            }
        }
        if(min_v == -1) break;

        for(auto e : G[min_v]){
            chmin(dist[e.to],dist[min_v] + e.w);
        }

        used[min_v] = true;
    }

    for(int i=0;i<V;i++){
        if(dist[i] < INF){
            cout << dist[i] << endl;
        }else{
            cout << "INF" << endl;
        }
    }
}