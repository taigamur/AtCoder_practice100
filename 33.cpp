#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
0927 AC
解法はすぐに思いついたが、所々ミスがあり、時間がかかった。
*/

int main(){
    int w,h;
    cin >> h >> w;

    int total = h*w;

    vector<vector<bool>> map(55,vector<bool>(55,false));
    vector<vector<int>> ans(55,vector<int>(55,-1));

    for(int i = 1; i <= h; i++){
        string str;
        cin >> str;
        for(int j = 1; j <= w; j++){
            if(str[j-1] == '.'){
                map[i][j] = true;
            }else{
                total--;
            }
        }
    }

    queue<pair<int,int>> que;
    pair<int,int> p;
    p.first = 1;
    p.second = 1;
    que.push(p);
    map[1][1] = false;
    ans[1][1] = 0;

    while(!que.empty()){
        p = que.front();
        que.pop();

        int x = p.first;
        int y = p.second;
        int sum = ans[y][x];

        if(map[y][x+1]){
            map[y][x+1] = false;
            ans[y][x+1] = sum+1;
            p.first = x+1;
            p.second = y;
            que.push(p);
        }
        if(map[y][x-1]){
            map[y][x-1] = false;
            ans[y][x-1] = sum+1;
            p.first = x-1;
            p.second = y;
            que.push(p);
        }

        if(map[y+1][x]){
            map[y+1][x] = false;
            ans[y+1][x] = sum+1;
            p.first = x;
            p.second = y+1;
            que.push(p);
        }

        if(map[y-1][x]){
            map[y-1][x] = false;
            ans[y-1][x] = sum+1;
            p.first = x;
            p.second = y-1;
            que.push(p);
        }


    }
    if(ans[h][w] == -1){
        cout << "-1" << endl;
    }else{
        cout << total - ans[h][w] -1<< endl;
    }
    



}