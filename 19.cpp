#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/*
0922 AC

始点からの逆回りはdを本店と考えればよい
それ以外は逆順ができている
*/
int main(){
    int d;
    cin >> d;

    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<int> list(n+1);
    list[0] = 0;
    for(int i = 1; i < n; i++){
        int t;
        cin >> t;
        list[i] = t;
    }
    list[n] = d;
    sort(list.begin(),list.end());


    //注文受け取り
    vector<int> order(m);
    for(int i = 0; i < m; i++){
        cin >> order[i];
    }

    int sum = 0;
    //各注文に対しての処理
    for(int i = 0; i < m; i++){
        int key = order[i];
        int left = 0;
        int right = n;
        int mid;
        while(right >= left){
            mid = (left + right) / 2;
            if(list[mid] == key){
                left = mid;
                right = mid;
                break;
            }else if(key < list[mid]){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        sum += min(abs(key - list[left]),abs(key - list[right]));
    }
    cout << sum << endl;
}