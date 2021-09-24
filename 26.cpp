#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
using Graph = vector<vector<ll>>;

/*
一部　WA
*/

void dfs(Graph &node, vector<ll> &ans, vector<ll> &sum ,int root, ll add){
    ans[root] += sum[root] + add;
    add += sum[root];
    for(auto next_v : node[root]){
        dfs(node, ans, sum, next_v, add);
    }
}

int main(){
    int n;
    cin >> n;
    int q;
    cin >> q;

    Graph node(n);
    for(int i = 1; i< n; i++){
        int a,b;
        cin >> a >> b;
        node[a-1].push_back(b-1);
    }

    
    vector<ll> sum(n,0);
    for(int i = 0; i < q; i++){
        int root;
        ll val;
        cin >> root >> val;
        sum[root - 1] += val;
    }

    ll add = 0;
    vector<ll> ans(n,0);
    dfs(node, ans, sum, 0, add);
    
    for(int i = 0; i < ans.size() - 1; i++){
        cout << ans[i] << " ";
    }
    cout << ans[n-1] << endl;


}