#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
0924 AC
基本的な問題はできるようになってきた
軽く復習程度でいい
*/

int main(){
    int n;
    cin >> n;

    vector<vector<int>> G(n);
    
    for(int i = 0; i < n; i++){
        int l;
        cin >> l;
        int m;
        cin >> m;
        for(int j = 0; j < m; j++){
            int t;
            cin >> t;
            G[i].push_back(t-1);
        }
    }

    queue<int> q;
    vector<int> ans(n,1000);
    ans[0] = 0;
    vector<bool> list(n,false);
    list[0] = true;
    q.push(0);

    while(!q.empty()){
        int s = q.front();
        q.pop();
        for(auto t : G[s]){
            if(list[t] == false){
                q.push(t);
                ans[t] = min(ans[t], ans[s] + 1);
                list[t] = true;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(ans[i] == 1000) cout << i + 1 << " " << "-1" << endl;
        else cout << i + 1 << " " << ans[i] << endl;
    }
}