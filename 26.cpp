#include <iostream>
#include <vector>
#include <stack>
using namespace std;


/*
0811 AC,WA,TLEが混ざっているが、解決方法がいまいちわからない
後で復習必要
グラフを作ってから深さ優先探索で実装
*/

int main(){
    int N,Q;
    cin >> N >> Q;
    vector<vector <int> > G(N+1);
    vector<int> ans(N+1,0);

    for(int i=1;i<N;i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    for(int i=0;i<Q;i++){
        int key,val;
        cin >> key >> val;

        stack<int> todo;
        todo.push(key);

        vector<bool> seen(N+1,false);
        seen[key] = true;

        while(todo.size() != 0){
            int v = todo.top();
            todo.pop();
            ans[v] += val;
            for(int x : G[v]){
                if(seen[x]) continue;
                todo.push(x);
                seen[x] = true;
            }
        }



    }
    for(int i=1;i<=N;i++){
        cout << ans[i];
        if(i <N) cout << " ";
    }
    cout << endl;
}