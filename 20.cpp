#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
0810 できなかった

stl の　lower_boundがわかれば解けた問題
*/


int binary_count(vector<int> &list, int key){

    int left = 0;
    int right = list.size()-1;
    int mid = 0;
    while(right >= left){
        mid = left + (right - left)/2;
        
        if(key == list[mid]){
            break;
        }else if(key <= list[mid]){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    while(list[mid-1] == list[mid]){
        mid++;
    }
    return mid ;
}

int main(){
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    for(int i=0;i<n;i++){
        cin >> c[i];
    }

    sort(a.begin(),a.end());
    sort(c.begin(),c.end());

    int sum = 0;
    for(int i=0;i<n; i++){
        int t = b[i];
        int a_sum = binary_count(a,t);
        int c_sum = binary_count(c,t);

        sum += a_sum * (c.size() - c_sum);

        cout << n - c_sum << endl;
    }
    cout << sum << endl;
}