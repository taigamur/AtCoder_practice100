#include <iostream>
#include <vector>
using namespace std;

/*
1013 AC
*/

const long long INF = 1LL << 60;
typedef long long ll;
int main(){
    int V,E;
    cin >> V >> E;

    //dp配列
    vector<vector<ll>> dp(V,vector<ll>(V,INF));

    for(int e = 0; e < E; e++){
        int a,b;
        cin >> a >> b;
        ll w;
        cin >> w;
        dp[a][b] = w;
    }

    for(int v = 0; v < V; v++){
        dp[v][v] = 0;
    }

    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    bool negative = false;
    for(int i = 0; i < V; i++){
        if(dp[i][i] < 0) negative = true;
    }

    if(negative){
        cout << "NEGATIVE CYCLE" << endl;
    }else{
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(j) cout << " ";
                if(dp[i][j] < INF/2) cout << dp[i][j];
                else cout << "INF";
            }
            cout << endl;
        }
    }
}