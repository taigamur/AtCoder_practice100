#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
0923 AC
*/

int w,h;
void dfs(vector<vector<int>> &map, int x, int y){
    map[x][y] = 0;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j<= 1; j++){
            if(map[x+i][y+j] == 1){
                dfs(map,x+i,y+j);
            }
        }
    }
}


int main(){

    vector<int> list;
    while(true){
        cin >> w >> h;
        if(w == 0 && h == 0){
            break;
        }

        vector<vector<int>> map(h+2,vector<int>(w+2,0));
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                cin >> map[i][j];
            }
        }

        int ans = 0;
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                if(map[i][j] == 1){
                    ans++;
                    dfs(map,i,j);
                }

            }
        }
        list.push_back(ans);
        // cout << ans << endl;
    }

    for(int i = 0; i < list.size(); i++){
        cout << list[i] << endl;
    }
}