#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int INF = 2000000000;

/*
1002 AC ビットの扱いに時間がかかった
参考URL
https://dalekspritner.hatenablog.com/entry/2018/09/27/231030
*/
int V,E;
vector<vector<int>> G(20,vector<int>(20,INF));
vector<vector<int>> dp(50,vector<int>(50000,-1));

/*
dp[S][v] Sを通ってvにいるときのその後に通る最短路長
*/

int calc(int s, int v){
    
    if(dp[v][s] >= 0){
        return dp[v][s];
    }

    if(s == (1 << V)-1 && v == 0){  //全部探索済みの場合の表現
        return dp[v][s] = 0;
    }

    int ans = INF;
    for(int i = 0; i < V; i++){
        if(!(s & 1 << i) && G[v][i] < INF){
            ans = min(ans,calc(s | 1 << i , i) + G[v][i]);
        }
    }

    dp[v][s] = ans;
    return ans;
}

int main(){
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int s,t,d;
        cin >> s >> t >> d;
        G[s][t] = d;
    }

    int ans = calc(0,0);

    if(ans != INF){
        cout << ans << endl;
    }else{
        cout << "-1" << endl;
    }
}