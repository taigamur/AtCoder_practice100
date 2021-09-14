#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmax(T& a, T b){
    if(a < b){
        a = b;
    }
}

/*
0817 ok
基本的な問題だが時間がかかった
比較するべき位置を間違っていたのが原因
*/
int main(){
    int n,w;
    cin >> n >> w;
    
    vector<vector <int> > dp(n+1,vector<int>(w+1,0));

    int weight[n];
    int val[n];
    for(int i=0;i<n;i++){
        cin >> val[i] >> weight[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=w;j++){

            //i番目を選んだ場合
            if(j-weight[i]>=0){
                dp[i+1][j] = dp[i][j-weight[i]] + val[i];
            }
            //iを選んでいない場合と比較
            chmax(dp[i+1][j],dp[i][j]);
        }
    }

    cout << dp[n][w] << endl;
}