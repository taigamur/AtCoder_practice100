#include <iostream>
#include <vector>
#include <algorithm>

// ある程度できたが、WA 難しい

using namespace std;
using Graph = vector<vector<int>>;

int main(){
    int n;
    cin >> n;

    int m;
    cin >> m;
    Graph g(n+1);

    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        if(a > b){
            int t = a;
            a = b;
            b = t;
        }
        g[a-1].push_back(b-1);
    }


    //ビット全探索
    int ans = 1;
    for(int bit = 0; bit < (1 << n); bit++){
        

        int size = 0;
        for(int j = 0; j < n; j++){
            if(bit & (1 << j)){
                size++;
            }
        }

        vector<int> list(n,0); 
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int x : g[i]){
                    if(x == j){
                        list[i]++;
                        list[j]++;
                    }
                }
                
            }
        }

        //最後の判定
        int jud = 1;
        for(int j = 0; j < n; j++){
            if(bit & (1 << j)){
                if(list[j] == size-1){

                }else{
                    jud = 0;
                }
            }
        }
        if(jud == 1){
            ans = max(ans,size);
        }
        
    }
    cout << ans << endl;
}