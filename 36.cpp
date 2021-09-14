#include <iostream>
#include <vector>
using namespace std;


/*
0817 ok
*/

template<class T> void chmax(T& a, T b){
    if(a < b){
        a = b;
    }
}

int main(){
    int w,n;
    cin >> n >> w;

    vector<vector<int> > dp(n+1,vector<int>(w+1,0));

    vector<int> weight(n);
    vector<int> val(n);
    for(int i=0;i<n;i++){
        cin >> val[i] >> weight[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=w;j++){
            if(j-weight[i]>=0){
                dp[i+1][j] = dp[i+1][j-weight[i]] + val[i];
            }
            chmax(dp[i+1][j],dp[i][j]);
        }
    }
    cout << dp[n][w] << endl;
}