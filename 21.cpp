#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

/*
0923 AC
midに到達するまでの時間を計算し、危険なものから順番に割っていく

*/
int main(){
    int n;
    cin >> n;
    vector<ll> H(n);
    vector<ll> S(n);
    
    ll right = 0;
    for(int i = 0; i < n; i++){
        cin >> H[i] >> S[i];
        right = max(right, H[i] + S[i]*(n-1));
    }

    ll left = 0;
    ll ans = right;
    while(right >= left){
        ll mid = (left + right) / 2;
        vector<ll> time(n);
        bool j = true;
        for(int i = 0; i < n; i++){
            if(H[i] > mid) j = false;
            else time[i] = (mid - H[i]) / S[i]; //midに到達するまでの時間
        }

        sort(time.begin(),time.end());
        for(int i = 0; i < n; i++){
            if(time[i] < i) j = false;
        }

        if(j){
            right = mid - 1;
            ans = min(ans,mid);
        }else{
            left = mid + 1;
        } 
    }
    cout << ans << endl;
}