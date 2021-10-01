#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

/*
少々時間がかかった　要素の数が偶数と奇数で処理が異なる点に注意
*/

int main(){

    vector<ll> ans; 
    while(true){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }

        vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
        for(int i = 1; i <= n; i++){
            dp[i][i] = 0;
        }

        vector<ll> val(n+1,0);
        for(int i = 1; i <= n; i++){
            cin >> val[i];
        }

        //斜めの列について
        for(int l = 2; l <= n; l++){
            for(int i = 1; i <= n - l + 1; i++){
                int j = i+l-1;

                if((j-i)%2== 1){
                    if(j-i == 1){
                        if(abs(val[i]-val[j]) <= 1) dp[i][j] = 2;
                    }else{
                        if((dp[i+1][j-1] == j-i-1) && (abs(val[i]-val[j]) <= 1)){
                            dp[i][j] = j-i+1;
                        }else{
                            ll sum = 0;
                            for(int k = i+1; k < j; k++){
                                sum = max(sum,dp[i][k]+dp[k+1][j]);
                            }
                            dp[i][j] = sum;
                        }
                    }
                }else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }

            }
        }

        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= n; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        ans.push_back(dp[1][n]);

    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}