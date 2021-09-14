#include <iostream>
#include <algorithm>
using namespace std;
const long long INF = 1LL << 60;
// 0916 WA
// ABだけを列挙して、A,Bを求め、比較

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    int c_max = max(x,y);
    c_max *= 2;
    long long ans = INF;
    for(int i = 0; i <= c_max; i++){
        long long sum = 0;
        sum += i*c;
        if(x > i/2){
            sum += a * (x - i/2);
        }
        if(y > i/2){
            sum += b * (y - i/2);
        }
        ans = min(ans,sum);
    }
    cout << ans << endl;
}