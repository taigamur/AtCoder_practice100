#include <iostream>
#include <vector>
using namespace std;

/*
0928 AC
最初の考え方が少しずれていた　
*/

int main(){
    int n;
    cin >> n;

    vector<int> ans(n);
    
    for(int i = 0; i < n; i++){

        string a,b;
        cin >> a;
        cin >> b;

        vector<vector<int>> list(b.size()+1,vector<int>(a.size()+1,0));

        for(int i = 1; i <= b.size(); i++){
            int t = 0;
            for(int j = 1; j <= a.size(); j++){
                if(a[j-1] == b[i-1]){
                    list[i][j] = list[i-1][j-1] + 1;
                }else{
                    list[i][j] = max(list[i-1][j],list[i][j-1]);
                }
        
            }
        }
        ans[i] = list[b.size()][a.size()];

    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
}