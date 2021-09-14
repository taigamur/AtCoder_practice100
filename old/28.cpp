#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
0813 ok
*/

int main(){
    int n;
    cin >> n;
    vector<vector<int> > G(n,vector<int>(n));

    for(int i=0;i<n;i++){
        int id;
        cin >> id;
        int t;
        cin >> t;
        for(int j=0;j<t;j++){
            int u;
            cin >> u;
            G[id-1].push_back(u-1);
        }
    }

    vector<int> dist(n,-1);
    vector<int> list(n,1);
    queue<int> que;
    que.push(0);
    dist[0] = 0;
    list[0] = 0;


    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int x : G[v]){
            if(list[x] == 0) continue;

            que.push(x);
            dist[x] = dist[v] + 1;
            list[x] = 0;
        }
    }

    for(int i=0; i < n; i++){
        cout << i+1 << " " << dist[i] << endl;
    }
}