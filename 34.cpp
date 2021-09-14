#include <iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
    int sum[50];
    sum[0] = 1;
    sum[1] = 1;
    if(n == 0 || n == 1){
        cout << 1 << endl;
    }else{
        for(int i=2;i<=n;i++){
            sum[i] = sum[i-1] + sum[i-2];
        }
        cout << sum[n] << endl;
    }
    
}