#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long INF = 1LL << 60;


/*
0810 すごく時間をかけてなんとかok
難しかった

*/
int main(){
    int n;
    cin >> n;

    vector<long long> h(n);
    vector<long long> s(n);

    for(int i=0;i < n; i++){
        cin >> h[i] >> s[i];
    }


    //2分探索で最適な時間を探していく
    long long right = INF;
    long long left = 0;

    while(right - left > 1){
        bool judge = true;
        vector<long long> time(n);
        long long mid = left + (right - left)/2;
        for(int i=0;i < n; i++){
            if(h[i] > mid) judge = false;
            else time[i] = (mid - h[i])/s[i];
        }

        sort(time.begin(),time.end());
        for(int i=0;i<n;i++){
            if(time[i] < i) judge = false;
        }

        if(judge) right = mid;
        else left = mid;
    }
    cout << right << endl;

    
}