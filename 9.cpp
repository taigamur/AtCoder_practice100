#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//0917 未解決問題　解決
//すごく時間がかかったので要復習


/*
boolの2次元配列を用意するには大きすぎるので、mapで対応
*/

int main(){
    int n;
    cin >> n;

    vector<pair<int,int>> star(n);
    for(int i = 0; i < n; i++){
        pair<int,int> p;
        cin >> p.first >> p.second;
        star[i] = p;
    }

    int m;
    cin >> m;

    map<pair<int,int>,bool> world;
    vector<pair<int,int>> list(m);
    for(int i = 0; i < m; i++){
        pair<int,int> p;
        cin >> p.first >> p.second;
        world[p] = true;
        list[i] = p;
    }

    //始点の決定
    for(int i = 0; i < m; i++){
        int dif_x = list[i].first - star[0].first;
        int dif_y = list[i].second - star[0].second;
        int cnt = 1;
        for(int j = 1; j < n; j++){
            pair<int,int> t;
            t.first = star[j].first + dif_x;
            t.second = star[j].second + dif_y;
            if(world[t]){
                cnt++;
            }
        }
        if(cnt == n){
            cout << dif_x << " " << dif_y << endl;
        }
    }
}