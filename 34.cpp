#include <iostream>
#include <vector>
using namespace std;

/*
0928 AC
すぐできた
*/

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);

    a[0] = 1;
    a[1] = 1;
    if(n == 0){
        cout << "1" << endl;
    }else if(n == 1){
        cout << "1" << endl;
    }else{
        for(int i = 2; i <= n; i++){
            a[i] = a[i-1] + a[i-2];
        }
        cout << a[n] << endl;
    }
}