#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60; //十分に大きな値

/*
60.cppよりも簡単な問題
*/

int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<long long>> dp(N,vector<long long>(N,INF));

    for(int i=0;i<M;i++){
        int a,b,t;
        cin >> a >> b >> t;
        a = a-1;
        b = b-1;
        dp[a][b] = t;
        dp[b][a] = t;
    }
    for(int i=0;i<N;i++) dp[i][i] = 0;

    //フロイドワーシャル
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }

    vector<long long> time(N,0);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(time[i] < dp[i][j]) time[i] = dp[i][j];
        }
    }
    long long ans = INF;
    int bas;
    for(int i=0;i<N;i++){
        if(ans > time[i]){
            ans = time[i];
            bas = i;
        }
    }
    cout << time[bas] << endl;



}