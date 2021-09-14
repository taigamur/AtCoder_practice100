#include <iostream>
using namespace std;

// 0916 AC O(N)

int main(){
    string s;
    cin >> s;

    int ans = 0;
    int sum = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A' || s[i] == 'C' || s[i] == 'T' || s[i] == 'G'){
            sum++;
        }else{
            sum = 0;
        }
        if(sum > ans){
            ans = sum;
        }
    }
    cout << ans << endl;
}