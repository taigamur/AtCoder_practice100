#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long INF = 1LL << 60;

// 0917 AC

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }

    long long cost = INF;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int s = a[i];
            int g = b[j];
            long long tmp = 0;
            for(int k = 0; k < n; k++){
                tmp += g - s;
                if(a[k] < s){
                    tmp += (s - a[k])*2;
                }
                if(b[k] > g){
                    tmp += (b[k] - g)*2;
                }
            }
            cost = min(cost,tmp);
        }
    }
    cout << cost << endl;
}