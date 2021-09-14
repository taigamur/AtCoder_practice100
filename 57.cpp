#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const long long INF = 1LL << 60; //十分に大きな値

/*
中身は複雑だったが、ダイクストラ法を実装するだけで解ける
0820 ok
*/

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
    int V,N;
    cin >> V >> N;
    Graph G(V);
    for(int i=0;i<N;i++){

        int f;
        cin >> f;
        if(f == 1){
            //グラフの更新
            int from,to,weight;
            cin >> from >> to >> weight;

            G[from-1].push_back(Edge(to-1,weight));
            G[to-1].push_back(Edge(from-1,weight));
        }else{
            //客からの指示 ダイクストラ法
            int from , to;
            cin >> from >> to;
            
            from = from -1;
            to = to-1;
            vector<long long> dist(V,INF);
            dist[from] = 0;

            //(d[v],v)のペアを要素としたヒープを作る
            priority_queue<pair<long long,int>,
                            vector<pair<long long,int>>,
                            greater<pair<long long, int>>> que;
            que.push(make_pair(dist[from],from));

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

            if(dist[to] < INF){
                cout << dist[to] << endl;
            }else{
                cout << -1 << endl;
            }
        }
    }

    //ß << "ture" << endl;

}