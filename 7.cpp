#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<vector<bool>> map(5001,vector<bool>(5001,false));
bool judge(int x, int y){
    if(x < 0 || x > 5000 || y < 0 || y > 5000){
        return false;
    }else{
        return map[x][y];
    }
}


int main(){
    int n;
    cin >> n;

    vector<pair<int,int>> list(n);
    for(int i = 0; i < n; i++){
        pair<int,int> p;
        cin >> p.first >> p.second;
        map[p.first][p.second] = true;
        list[i] = p;
    }

    long long ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int a_x,a_y;
            int b_x,b_y;
            a_x = list[i].first;
            a_y = list[i].second;
            b_x = list[j].first;
            b_y = list[j].second;

            int c_x,c_y;
            int d_x,d_y;
            //judge1  上側の正方形
            c_x = b_x - (b_y - a_y);
            c_y = b_y + (b_x - a_x);
            d_x = a_x - (b_y - a_y);
            d_y = a_y + (b_x - a_x);

            if(judge((int)c_x,(int)c_y) && judge((int)d_x,(int)d_y)){
                long long s = (a_x - b_x)*(a_x - b_x) + (a_y - b_y)*(a_y - b_y);
                ans = max(ans,s);
            }
   
            //judge2　下側の正方形
            c_x = b_x + (b_y - a_y);
            c_y = b_y - (b_x - a_x);
            d_x = a_x + (b_y - a_y);
            d_y = a_y - (b_x - a_x);
            if(judge((int)c_x,(int)c_y) && judge((int)d_x,(int)d_y)){
                long long s = (a_x - b_x)*(a_x - b_x) + (a_y - b_y)*(a_y - b_y);
                ans = max(ans,s);
            }
        }
    }
    cout << ans << endl;
}