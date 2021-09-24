#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*
0923 ac
int,long などの部分で時間がかかった
*/

int main(){
    int n;
    cin >> n;

    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    
    vector<int> B(n);
    for(int i = 0; i < n; i++){
        cin >> B[i];
    }
    
    vector<int> C(n);
    for(int i = 0; i < n; i++){
        cin >> C[i];
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());

    long long sum = 0;
    for(int i = 0; i < n; i++){
        
        long long a = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        long long c = C.end() - upper_bound(C.begin(), C.end(), B[i]);
        sum += a * c;
    }
    cout << sum << endl;
}