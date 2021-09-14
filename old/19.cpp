#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
0810 解説見ながらok
*/

int main(){
    int d,m,n;
    cin >> d;
    cin >> n;
    cin >> m;

    vector<int> shop(n+1);

    shop[0] = 0;
    for(int i=1;i<n;i++){
        cin >> shop[i];
    }
    shop[n] = d;

    sort(shop.begin(),shop.end());

    int sum = 0;

    for(int i=0;i<m;i++){
        int p;
        cin >> p;

        int left = 0;
        int right = n;
        int dis_a,dis_b;

        while(right >= left){
            int mid = left + (right - left)/2;

            if(p == shop[mid]){
                right = mid;
                left = mid;
                break;
            }else if(p < shop[mid]){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        dis_a = abs(p - shop[left]);
        dis_b = abs(shop[right] - p);

        if(dis_a < dis_b){
            sum += dis_a;
        }else{
            sum += dis_b;
        }
    }
    cout << sum << endl;
}