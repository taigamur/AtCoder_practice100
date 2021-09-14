#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N;
    cin >> N;

    cout << N << ":";
    int n = N;
    if(N == 1){
        return 0;
    }else{
        for(int i=2; i<=sqrt(n);){
            if(N%i == 0){
                cout << " " << i;
                N = N/i;
            }else{
                i++;
            }
        }
        if(N != 1) cout << " " << N;
        cout << endl;
    }
}