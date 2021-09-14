#include <iostream>
#include <vector>
using namespace std;

/*
0903 時間かかったがok
    配列の位置などわからなかったら図を書くようにする
*/


int main(){
    int n,m;
    cin >> n >> m;

    vector<int> dist(n);
    vector<int> sum(n+1,0);

    for(int i=0; i < n-1; i++){
        cin >> dist[i];
    }

    for(int i=0; i<n-1; i++){
        sum[i+1] = sum[i] + dist[i];
    }

    long long ans = 0;
    // m日間の距離
    int pos = 0;//位置
    int next;
    for(int j=0; j < m; j++){
        cin >> next;
        if(next  > 0){
            ans += sum[next + pos] - sum[pos];
        }else{
            ans += sum[pos] - sum[pos + next];
        }
        pos = pos + next;
    }

    long long mod = 100000;
    ans = ans % 100000;
    cout << ans << endl;
}