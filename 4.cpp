#include <iostream>
#include <algorithm>
using namespace std;

// 0916 AC O(NM^2)

int main(){
    int n,m;
    cin >> n >> m;

    long long p[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> p[i][j];
        }
    }

    long long ans = 0;
    for(int i = 0; i < m; i++){
        for(int j = i + 1; j < m; j++){
            long long sum = 0;
            for(int t = 0; t < n; t++){
                sum += max(p[t][i],p[t][j]);
            }
            ans = max(ans,sum);
        }
    }
    cout << ans << endl;


}