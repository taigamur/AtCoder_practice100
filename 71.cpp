#include <iostream>
using namespace std;
typedef long long ll;
const int MAX = 200000;
const int MOD = 1000000007;

//0903 okだが、逆元が難しい


//メモを保管
ll fact[MAX], inv_fact[MAX], inv[MAX];

//メモ計算
void init(){
    fact[0] = 1;
    fact[1] = 1;
    inv[0] = 1;
    inv[1] = 1;
    inv_fact[0] = 1;
    inv_fact[1] = 1;


    for(int i=2; i<MAX; i++){
        //階乗
        fact[i] = fact[i-1] * i % MOD;
        //逆元
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        //逆元の階乗
        inv_fact[i] = inv_fact[i-1] * inv[i] % MOD;
    }
}

ll nCk(int n, int k){
    ll x = fact[n]; //n!の計算
    ll y = inv_fact[n-k]; //(n-k)!の計算
    ll z = inv_fact[k]; //k!の計算

    //例外処理
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return x * ((y * z) % MOD) % MOD; //二項係数の計算
}


int main(){
    init();
    int w,h;
    cin >> w >> h;
    cout << nCk(w+h-2,w-1) << endl;
}