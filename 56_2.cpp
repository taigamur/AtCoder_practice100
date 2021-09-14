#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const long long INF = 1LL << 60; //十分に大きな値

/*
0820 ok
*/


//緩和
template<class T> bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}

struct Edge{
    int to;//隣接頂点
    long long w;
    Edge(int to, long long w) : to(to), w(w){}
};
using Graph = vector<vector<Edge> >;

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
    vector<long long> dist(V,INF);
    dist[r] = 0;

    //(d[v],v)のペアを要素としたヒープを作る
    priority_queue<pair<long long,int>,
                    vector<pair<long long,int>>,
                    greater<pair<long long, int>>> que;
    que.push(make_pair(dist[r],r));

    while(!que.empty()){
        int v = que.top().second;
        long long d = que.top().first;
        que.pop();

        if(d > dist[v]) continue;

        for(auto e : G[v]){
            if(chmin(dist[e.to],dist[v] + e.w)){
                que.push(make_pair(dist[e.to],e.to));
            }
        }
    }

    for(int i=0;i<V;i++){
        if(dist[i] < INF) cout << dist[i] << endl;
        else cout << "INF" << endl;
    }

}