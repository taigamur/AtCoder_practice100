#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
設計を間違えることが多く、時間がかかったが、AC
もっと早く解けるようになりたい
*/

vector<vector<int>> map(55,vector<int>(55,0));
vector<vector<bool>> list(55,vector<bool>(55,true));
vector<vector<int>> ans(55,vector<int>(55,100));

void bfs(int x, int y,int dis){
    list[y][x] = false;
    ans[y][x] = dis;

    pair<int,int> t;
    t.first = x;
    t.second = y;
    list[y][x] = false;
    ans[y][x] = 0;
    queue<pair<int,int>> q;
    q.push(t);

    while(!q.empty()){
        pair<int,int> p = q.front();
        int sum = ans[p.second][p.first];

        q.pop();
        if(map[p.second][p.first+1] == 1 && list[p.second][p.first+1]){
            pair<int,int> l;
            l.first = p.first + 1;
            l.second = p.second;
            ans[l.second][l.first] = sum + 1;
            list[l.second][l.first] = false;
            q.push(l);
        }
        if(map[p.second][p.first-1] == 1 && list[p.second][p.first-1]){
            pair<int,int> l;
            l.first = p.first - 1;
            l.second = p.second;
            ans[l.second][l.first] = sum + 1;
            list[l.second][l.first] = false;
            q.push(l);
        }
        if(map[p.second+1][p.first] == 1 && list[p.second+1][p.first]){
            pair<int,int> l;
            l.first = p.first;
            l.second = p.second+1;
            ans[l.second][l.first] = sum + 1;
            list[l.second][l.first] = false;
            q.push(l);
        }
        if(map[p.second-1][p.first] == 1 && list[p.second-1][p.first]){
            pair<int,int> l;
            l.first = p.first;
            l.second = p.second-1;
            ans[l.second][l.first] = sum + 1;
            list[l.second][l.first] = false;
            q.push(l);
        }

    }
}

int main(){
    int r,c;
    cin >> r >> c;

    pair<int,int> s;
    cin >> s.first >> s.second;
    pair<int,int> g;
    cin >> g.first >> g.second;

    for(int i = 1; i <= r; i++){
        string str;
        cin >> str;
        for(int j = 0; j < c; j++){
            if(str[j] == '.'){
                map[i][j+1] = 1;
            }
        }
    }
    
    bfs(s.second,s.first,0);

    cout << ans[g.first][g.second] << endl;
    
}