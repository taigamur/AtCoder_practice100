#include <iostream>
#include <vector>
using namespace std;
typedef long long INF = 1LL << 60;
/*
dp[i][j] : iからjまでの最小コスト
右上に向かって推移する

漸化式の立式が難しくてできなかった
*/
int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> list(n+1);
    for(int i = 1; i <= n; i++){
        int a,b;
        pair<int,int> p;
        cin >> p.first >> p.second;
        list[i] = p;        
    }

    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));


    for(int i = 1; i <= n; i++) dp[i][i] = 0;

    // 斜めの列の数
    for(int l = 2; l <= n; l++){
        for(int i = 1; i < n - l + 1; i++){
            int j = i + l - 1;
            dp[i][j] = INF;
            for(int k = i; k < j - 1;){
                ll q = dp[i,k] + dp[k+1] + 
            }
        }
    }


}