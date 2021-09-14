#include <iostream>
#include <vector>
using namespace std;


/*0730 ok*/

vector<int> s;
vector<int> t;
bool binary_search(int key){
    int left = 0;
    int right = s.size();

    while(right >= left){
        int mid = left + (right - left)/2;
        if(s[mid] == key) return true;
        else if(key < s[mid]) right = mid-1;
        else left = mid+1; 
    }
    return false;
}


int main(){
    int S;
    cin >> S;
    for(int i=0;i<S;i++){
        int j;
        cin >> j;
        s.push_back(j);
    }

    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int j;
        cin >> j;
        t.push_back(j);
    }

    int ans = 0;
    for(int i=0; i < t.size(); i++){
        if(binary_search(t[i])) ans++;
    }
    cout << ans << endl;


}