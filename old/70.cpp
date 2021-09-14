#include <iostream>
using namespace std;

//0903 ok

// 繰り返し２乗法の実装
long long int calc(long long int m, long long int n, long long int p){
    if(n == 0){
        return 1;
    }
    if(n % 2 == 0){
        long long int t = calc(m, n/2 , p);
        return t*t % p;
    }
    return m*calc(m,n-1,p) % p;
}




int main(){
    long long int m,n;
    cin >> m >> n;
    long long int p = 1000000007;
    
    cout << calc(m,n,p) << endl;
}