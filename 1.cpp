#include <iostream>
using namespace std;

// 0916 AC

int main(){
    int n,x;
    while(true){
        cin >> n >> x;
        if(n == 0 && x == 0){
            break;
        }
        int sum = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                int z = x - i - j;
                if(z <= n && z > j){
                    sum++;
                }
            }
        }
        cout << sum << endl;
    }

}