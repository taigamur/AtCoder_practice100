#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

/*0923 AC*/

Graph G(100);
vector<bool> seen(100,false);
vector<int> d(100);
vector<int> f(100);
int sum = 1;
void dfs(int v){
    seen[v] = true;
    d[v] = sum;
    sum++;
    for(auto next_v : G[v]){
        if(seen[next_v]){
            continue;
        }else{
            dfs(next_v);
        }

    }
    f[v] = sum;
    sum++;
}


int main(){
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        int t;
        cin >> t;
        for(int j = 0; j < t; j++){
            int u;
            cin >> u;
            G[n-1].push_back(u-1);
        }
    }

    for(int i = 0; i < N; i++){
        if(!seen[i]){
            dfs(i);
        }    
    }


    for(int i = 0; i < N; i++){
        cout << i + 1 << " ";
        cout << d[i] << " ";
        cout << f[i] << endl;
    }



}