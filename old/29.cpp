#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;


/*
間違えて深さ優先探索で再帰を使って実装していた。
座標で幅優先探索を行う場合には、x用のqueとy用のqueを用意することもできる。

0816 ok
ある程度完成させてからACになるまで時間がかかった
*/

int main(){
    vector<vector<int> > map(50,vector<int>(50,0));
    vector<vector<int> > ans(50,vector<int>(50,-1));
    int r,c;
    cin >> r >> c;
    int s_x,s_y;
    int g_x,g_y;
    cin >> s_y >> s_x;
    cin >> g_y >> g_x;

    for(int i = 0; i < r; i++){
        string t;
        cin >> t;
        for(int j = 0; j < c; j++){
            if(t[j] == '.'){
                map[i][j] = 1;
            }
        }
    }


    //bfs(x-1,y-1,count);


    queue<int> que_x;
    queue<int> que_y;

    que_x.push(s_x-1);
    que_y.push(s_y-1);
    ans[s_y-1][s_x-1] = 0;

    while(!que_x.empty()){
        int x = que_x.front();
        que_x.pop();
        int y = que_y.front();
        que_y.pop();
        
        if(map[y][x+1] == 1){
            que_x.push(x+1);
            que_y.push(y);
            ans[y][x+1] = ans[y][x]+1;
            map[y][x+1] = 0;
        }
        if(map[y][x-1] == 1){
            que_x.push(x-1);
            que_y.push(y);
            ans[y][x-1] = ans[y][x]+1;
            map[y][x-1] = 0;
        }
        if(map[y-1][x] == 1){
            que_x.push(x);
            que_y.push(y-1);
            ans[y-1][x] = ans[y][x]+1;
            map[y-1][x] = 0;
        }
        if(map[y+1][x] == 1){
            que_x.push(x);
            que_y.push(y+1);
            ans[y+1][x] = ans[y][x]+1;
            map[y+1][x] = 0;
        }
    }


    cout << ans[g_y-1][g_x-1] << endl;

}