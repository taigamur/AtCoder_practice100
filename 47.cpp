#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
int N = 2000;
vector<vector<ll>> dp(N+1,vector<ll>(2*N+1,0));
vector<ll> val(2*N+1,0);

/*
1001 AC
メモ化DP 円環問題
テーブルの定義の方法が全くわからず非常に時間がかかった
なんとか理解できるようになったのでよかった。

参考URL
-> https://scrapbox.io/ia7ck-comp-pro/%E3%82%B1%E3%83%BC%E3%82%AD%E3%81%AE%E5%88%87%E3%82%8A%E5%88%86%E3%81%91%EF%BC%92_(Cake_2)

*/

ll solve(int i, int j){
    
    if(dp[i][j] > 0){
        return dp[i][j];
    }

    if(j - i == 1){
        dp[i][j] = max(val[i],val[j]);
        return dp[i][j];
    }
    if(j == i) return val[i];

    ll a = 0;
    a += val[i];
    if(val[i+1] > val[j]){
        if(i+2 > n){
            a += solve(i+2-n,j-n);
        }else{
            a += solve(i+2,j);
        }
    }else{
        if(i+1 > n){
            a += solve(i+1-n,j-1-n);
        }else{
            a += solve(i+1,j-1);
        }
    }
    ll b = 0;
    b += val[j];
    if(val[i] > val[j-1]){
        if(i+1 > n){
            b += solve(i+1-n,j-1-n);
        }else{
            b += solve(i+1,j-1);
        } 
    }else{
        b += solve(i,j-2);
    }

    dp[i][j] = max(a,b);
    return dp[i][j];

}

int main(){

    cin >> n;

    for(int i = 1; i <= n; i++){
        ll t;
        cin >> t;
        val[i] = t;
        val[i+n] = t;
        dp[i][i] = t;
        dp[i][n+i] = t;
    }

    ll ans = 0;

    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= i + n - 1; j++){
            solve(i,j);
        }
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= 2*n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    

    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i][n+i-1]);
    }
    cout << ans << endl;

}