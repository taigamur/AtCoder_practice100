#include <iostream>
#include <vector>
using namespace std;

/*
0921 AC 解決
*/

int main(){
    int n,m;
    cin >> n;
    cin >> m;

    vector<vector<int>> list(m,vector<int>(n,0));
    vector<int> ans(m);
    for(int i = 0; i < m; i++){
        int j;
        cin >> j;
        for(int t = 0; t < j; t++){
            int k;
            cin >> k;
            list[i][k-1] = 1;
        }
    }
    for(int i = 0; i < m; i++){
        cin >> ans[i];
    }

    //スイッチの組み合わせの全探索
    int sum = 0;
    for(int bit = 0; bit < (1 << n); bit++){
        //各電球について
        int l = 0;
        for(int j = 0; j < m; j++){
            int t = 0;
            for(int k = 0; k < n; k++){
                if(bit & (1 << k)){
                    if(list[j][k] == 1){
                        t++;
                    }
                }
            }
            if(t % 2 == ans[j]){
                l++;
            }
        }
        if(l == m){
            sum++;
        }
    }
    cout << sum << endl;

}