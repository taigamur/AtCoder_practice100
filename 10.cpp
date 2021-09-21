#include <iostream>
#include <vector>
using namespace std;

/*
全探索のプログラム
1問だけTLE
*/

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int m;
    cin >> m;
    vector<int> list(m);
    for(int i = 0; i < m; i++){
        cin >> list[i];
    }
    for(int i = 0; i < m; i++){
    
        int judge = 0;
        for(int bit = 0; bit < (1<<n); bit++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                if(bit & (1 << j)){
                    sum += a[j];
                }
            }
            if(sum == list[i]){
                cout << "yes" << endl;
                judge = 1;
                break;   
            }
        }
        if(judge == 0){
            cout << "no" << endl;
        }

    }
}