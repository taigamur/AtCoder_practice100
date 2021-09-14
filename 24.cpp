#include <iostream>
#include <vector>
#include <stack>
using namespace std;


/*
0811 
参考書見ながら　
答えはあっているが、judgeが通らなかった

あとで復習
*/

int main(){
    int N;
    cin >> N;

    vector<vector<int> > G(N);
    //グラフの受け取り
    for(int i=0;i<N;i++){
        int n;
        cin >> n;
        int t;
        cin >> t;
        for(int j=0;j<t;j++){
            int s;
            cin >> s;
            G[n-1].push_back(s-1);
        }
    }

    //探索
    vector<bool> seen(N,false);
    stack<int> todo;

    int count = 1;
    seen[0] = true;
    todo.push(0);
    vector<int> d(N);
    vector<int> f(N);
    d[0] = count; 
    count++;
    int SUM = 1;
    while(SUM <= N){
        //todoからemptyを取り出す
        int v;
        if(!todo.empty()){
            v = todo.top();
        }else{
            int i=0;
            while(true){
                if(seen[i] == false){
                    todo.push(i);
                    v = i;
                    seen[i] = true;
                    d[i] = count;
                    count++;
                    break;
                }
                i++;
            }
        }

        //vからたどれる頂点を全て探す
        bool judge = false;
        for(int x : G[v]){
            if(seen[x]){
                continue;
            }

            judge = true;
            seen[x] = true;
            todo.push(x);
            d[x] = count;
            count++;
        }

        if(!judge){
            todo.pop();
            f[v] = count;
            count++;
            SUM++;
        }


    }


    for(int i=0;i<N;i++){
        cout << i + 1 << " " << d[i] << " " << f[i] << endl; 
    }

}