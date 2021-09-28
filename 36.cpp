#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N,W;
    cin >> N >> W;
    vector<vector<int>> list(N+1,vector<int>(W+1,0));

    for(int i = 1; i <= N; i++){
        int v,w;
        cin >> v >> w;
        for(int j = 0; j <= W; j++){
            if(j >= w){
                list[i][j] = list[i][j-w] + v;
            }
            list[i][j] = max(list[i-1][j],list[i][j]);
        }
    }
    cout << list[N][W] << endl;
}