#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60;

/*
フロイドワーシャル法　動的計画法
計算量O(V^3)

dp[k][i][j] 頂点0,1,2,..,k-1 のみを中継頂点として通って良い場合のiからj
*/

int main(){
    int V,E;
    cin >> V >> E;

    vector<vector<long long>> dp(V,vector<long long>(V,INF));

    for(int i=0; i<E; i++){
        int s,t;
        long long d;
        cin >> s >> t >> d;
        dp[s][t] = d;
    }
    for(int i=0;i<V;i++) dp[i][i] = 0;

    //dp遷移　フロイドワーシャル法
    for(int k=0; k<V; k++){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }

    bool negative_cycle = false;

    //結果
    for(int v = 0; v < V; v++){
        if(dp[v][v] < 0) negative_cycle = true;
    }
    if(negative_cycle) cout << "NEGATIVE CYCLE" << endl;
    else{
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(j != 0) cout << " ";
                if(dp[i][j] < INF/2) cout << dp[i][j];
                else cout << "INF";
            }
            cout << endl;
        }
    }

}