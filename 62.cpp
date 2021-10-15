#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1LL << 60;
typedef long long ll;

/*
1015 AC
*/

int main(){
    int H,W;
    cin >> H >> W;

    //dp配列
    vector<vector<ll>> dp(11,vector<ll>(11,INF));

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            int v;
            cin >> v;
            dp[i][j] = v;
        }
    }

    for(int k = 0; k < 10; k++){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }       
    }

    int ans = 0;
    for(int h = 0; h < H; h++){
        for(int w = 0; w < W; w++){
            int c;
            cin >> c;
            if(c == -1) continue;
            
            ans += dp[c][1];
        }
    }
    cout << ans << endl;


}