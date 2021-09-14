#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
ある程度できていたがacにならなかった
0818 no
*/

template<class T> void chmin(T& a, T b){
    if(a > b){
        a = b;
    }
}
int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int> > dp(m+1,vector<int>(n+1,n));

    vector<int> coin(m);
    for(int i=0;i<m;i++){
        cin >> coin[i];
    }

    sort(coin.begin(),coin.end());

    for(int i=0;i<m;i++){
        for(int j=0;j<=n;j++){
            dp[i+1][j] = j;
            if(j-coin[i]>=0){
                dp[i+1][j] = dp[i+1][j-(j/coin[i])*coin[i]] + j/coin[i];
            }
            chmin(dp[i+1][j],dp[i][j]);
        }

        // for(int s=0;s<=m;s++){
        //     for(int t=0;t<=n;t++){
        //         cout << dp[s][t];
        //     }
        //     cout << endl;
        // }
        // cout <<"-----" << endl;


    }

    cout << dp[m][n] << endl;

}