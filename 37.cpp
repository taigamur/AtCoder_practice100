#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int>> list(m+1,vector<int>(n+1,n));
    for(int i = 1; i <= m; i++){
        int c;
        cin >> c;
        for(int j = 0; j <= n; j++){
            list[i][j] = j;
            if(c <= j){
                list[i][j] = list[i][j-c] + 1;
            }
            list[i][j] = min(list[i][j],list[i-1][j]);
        }
    }

    cout << list[m][n] << endl;
}