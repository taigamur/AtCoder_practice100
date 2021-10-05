#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60;

/*
dp[s][v] sを巡回し,vにいるときの距離と時間のペア
*/

struct Edge{
    long long d;
    long long time;
    //Edge(long long d, long long time) : d(d), time(time){}
};
int N,M;

vector<vector<Edge>> G(17,vector<Edge>(17));
vector<vector<pair<ll,ll>>> dp(17,vector<pair<ll,ll>>(1 << 17,make_pair(0,0)));

// first : d  ,  second : 組み合わせ数;

// s 組み合わせ　v 位置
pair<ll, ll> calc(int s, int v){
    pair<ll,ll> ans;
    if(s == 0){
        if(v == 0){
            ans.first = 0;
            ans.second = 1;
            dp[v][s] = ans;
            return ans;
        }else{
            ans.first = INF;
            ans.second = 0;
            dp[v][s] = ans;
            return ans;
        }
    }

    if((s & (1 << v)) == 0){ //Sにvが含まれていない場合
        ans.first = INF;
        ans.second = 0;
        dp[v][s] = ans;
        return ans;
    }

    pair<ll,ll> val = dp[v][s];
    if(val.first != 0){ //すでにメモされている場合
        return val;
    }

    val.first = INF;
    val.second = 0;
    for(int i = 0; i < N; i++){
        pair<ll, ll> p = calc(s | (1 << v), i);
        p.first += G[i][v].d;
        if(p.first <= G[i][v].time){ //時間制限を満たす
            if(p.first < val.first){ //距離が変更になる場合
                val = p;
            }else if(val.first == p.first){ //距離が同じ場合
                val.second += p.second;
            }
        }
        dp[i][s | (1 << v)] = val;
    }
    return val;


}

int main(){
    
    cin >> N >> M;
    // Edge edge;

    for(int i = 0; i < 17; i++){
        for(int j = 0; j < 17; j++){
            G[i][j].d = INF;
            G[i][j].time = 0;
        }
    }

    
    for(int i = 0; i < M; i++){
        int s,t;
        ll d,time;
        cin >> s >> t >> d >> time;
        s--;
        t--;
        G[s][t].d = d;
        G[s][t].time = time;
        G[t][s].d = d;
        G[t][s].time = time;
    }

    pair<ll,ll> ans = calc(0,(1 << N)-1);

    if(ans.first != INF){
        cout << ans.first << " " << ans.second << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }

}