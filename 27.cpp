#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
0924 AC
結構早く解けた
*/

vector<vector<int>> map(100,vector<int>(100,0));
int m;
int n;
int ans = 0;
void dfs(vector<vector<int>> &map, int x, int y, int sum){
    vector<vector<int>> map2(100,vector<int>(100,0));
    map2 = map;
    map2[y][x] = 0;
    sum++;
    ans = max(ans,sum);
    if(map2[y][x+1] == 1){
        dfs(map2,x+1,y,sum);
    }
    if(map2[y][x-1] == 1){
        dfs(map2,x-1,y,sum);
    }
    if(map2[y+1][x] == 1){
        dfs(map2,x,y+1,sum);
    }
    if(map2[y-1][x] == 1){
        dfs(map2,x,y-1,sum);
    }
}

int main(){
    cin >> m;
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int t;
            cin >> t;
            map[i][j] = t;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(map[i][j] == 1){
                dfs(map,j,i,0);
            }
            
        }
    }
    cout << ans << endl;
}