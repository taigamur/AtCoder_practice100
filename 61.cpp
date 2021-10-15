#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1LL << 60;
typedef long long ll;
int main(){
    int N,M;
    cin >> N >> M;

    vector<vector<ll>> dp(N,vector<ll>(N,INF));

    for(int i = 0; i < M; i++){
        int a,b;
        ll t;
        cin >> a >> b >> t;
        dp[a-1][b-1] = t;
        dp[b-1][a-1] = t;
    }

    for(int i = 0; i < N; i++){
        dp[i][i] = 0;
    }


    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    ll ans = INF;
    for(int i = 0; i < N; i++){
        ll t = 0;
        for(int j = 0; j < N; j++){
            t = max(t,dp[i][j]);
        }
        ans = min(ans,t);
    }

    cout << ans << endl;
}