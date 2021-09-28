#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
0928 AC
基本問題
*/

int main(){
    int n,w;
    cin >> n >> w;
    vector<vector<int>> ans(n+1,vector<int>(w+1,0));
    

    for(int i = 1; i <=n; i++){
        int v,s;
        cin >> v >> s;

        for(int j = 0; j <= w; j++){
            if(s <= j){
                ans[i][j] = ans[i-1][j-s] + v;
                
            }
            ans[i][j] = max(ans[i-1][j],ans[i][j]);
        }
    }


    cout << ans[n][w] << endl;
}