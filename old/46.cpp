#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, T b){
    if(a > b){
        a = b;
    }
}

int main(){

    int n;
    cin >> n;

    int val[n][2];
    for(int i=0;i<n;i++){
        cin >> val[i][0] >> val[i][1];
    }

    vector<vector<int> > dp(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){

            int t = 1;
            for(int k=j; k>=j-i-1; k--){
                t *= val[k];
            }
            if(j-i-1>0){
                dp[i][j] = t + dp[i][j-i-2];
            }else{
                dp[i][j] = t;
            }
            //cout << dp[i][j] << endl;

            if(i>0){

                chmin(dp[i][j],dp[i-1][j]);
            }
            

        }
    }

    cout << dp[n-2][n-1] << endl;
}
