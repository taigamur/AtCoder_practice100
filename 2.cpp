#include <iostream>
using namespace std;

// 0916 AC  O(N√N)

int main(){
    int N;
    cin >> N;
    int ans = 0;
    for(int j = 1; j <= N; j+=2){
        int sum = 0;
        for(int i = 1; i*i <= j; i++){
            if(j % i == 0){
                sum++;
                if(j/i != i){
                    sum++;
                }
            }
        }
        if(sum == 8) ans++;
    }

    cout << ans << endl;
}