#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const long long INF = 1LL << 60;

/*
1012 AC
*/
struct Edge{
    int to;
    long long w;
    Edge(int to, long long w) : to(to), w(w){}
};

using Graph = vector<vector<Edge>>;

int main(){
    int n,k;
    cin >> n >> k;
    Graph G(n);
    for(int i = 0; i < k; i++){
        int f;
        cin >> f;
        if(f == 1){
            int a,b;
            long long c;
            cin >> a >> b >> c;
            G[a-1].push_back(Edge(b-1,c));
            G[b-1].push_back(Edge(a-1,c));
        }else{
            int from,to;
            cin >> from >> to;
            from -= 1;
            to -= 1;
            vector<long long> dist(n,INF);
            dist[from] = 0;
            priority_queue<pair<long long, int>,
                           vector<pair<long long, int>>,
                           greater<pair<long long, int>>> que;
            que.push(make_pair(dist[from],from));

            while(!que.empty()){
                int v = que.top().second;
                long long d = que.top().first;
                que.pop();

                if(d > dist[v]) continue;

                for(auto e : G[v]){
                    if(dist[e.to] > dist[v] + e.w){
                        dist[e.to] = dist[v] + e.w;
                        que.push(make_pair(dist[e.to],e.to));
                    }
                }
            }

            if(dist[to] < INF){
                cout << dist[to] << endl;
            }else{
                cout << "-1" << endl;
            }
        }
    }

}