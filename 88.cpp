#include <iostream>
#include <stack>
using namespace std;

/*
0909 よくわからなかった
*/

int main(){
    int N;
    cin >> N;
    stack<pair<int,int>> v;
    int ans = 0;
    int n;
    for(int i = 1; i <=N; i++){
        cin >> n;
        if(i == 1){
            //最初
            //firstが位置、secondが色
            if(n == 0){
                ans++;
                v.push(make_pair(0,1));
            }else{
                v.push(make_pair(1,1));
            }
        }else if(i % 2 == 1){
            //奇数の場合はそのまま
            if(n == 0)ans++;
            int t = v.top().first;
            if(n == t){
                int k = v.top().second;
                v.pop();
                v.push(make_pair(t,k+1));
            }else{
                v.push(make_pair(n,1));
            }
        }else{
            //偶数の場合
            int t = v.top().first;
            if(n == t){
                if(n == 0) ans++;
                int k = v.top().second;
                v.pop();
                v.push(make_pair(t,k+1));
            }else{
                int k = v.top().second;
                v.pop();
                int k2 = 0;
                if(v.size()) k2 += v.top().second, v.pop();

                if(n == 0){
                    ans += k + 1;
                }else{
                    ans -= k;
                }
                v.push(make_pair(n, k + k2 + 1));
            }

        }
    }
    cout << ans << endl;
}