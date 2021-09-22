#include <iostream>
#include <vector>
using namespace std;

/*
0922 ok
*/

int main(){
    int s,t;
    cin >> s;
    vector<int> S(s);
    for(int i = 0; i < s; i++){
        cin >> S[i];
    }
    cin >> t;
    vector<int> T(t);
    for(int i = 0; i < t; i++){
        cin >> T[i];
    }

    //Tの要素をSから探す
    int ans = 0;
    for(int i = 0; i < t; i++){
        int left = 0;
        int right = s - 1;
        int key = T[i];
        while(right >= left){
            int mid = (right + left) / 2;
            if(S[mid] == key){
                ans++;
                break;
            }else if(key < S[mid]){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
    }
    cout << ans << endl;
}