#include <iostream>
#include <vector>
using namespace std;

/*
0903 基本問題　ok
*/

int main(){
    int N;
    cin >> N;

    vector<long long> A(N);
    for(int i=0; i < N; i++){
        cin >> A[i];
    }

    //累積和
    //sum[0] = 0 , N+1個の配列を用意することに注意
    vector<long long> sum(N+1,0);
    for(int i=0; i < N; i++){
        sum[i+1] = sum[i] + A[i];
    }

    //各kに対して
    for(int k=0; k <= N; k++){
        long long res = 0;
        for(int j=0; j + k <= N; j++){
            res = max(res,sum[k+j] - sum[j])
        }
    }


}