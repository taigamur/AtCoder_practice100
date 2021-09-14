#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60;


/*
全探索の問題

0729 WA

1文字ずつ移動する全探索を行ったのでTLEになった。
StartとGoalの候補点は
a のいずれかの点　と　bのいずれかの点になる
これを踏まえた上で全探索すれば良い
*/


int main(){
    int N;
    cin >> N;

    vector<vector<int> > grid(N,vector<int>(2));

    long long  a_min = INF;
    int a_max = 0;
    long long  b_min = INF;
    int b_max = 0;
    for(int i=0; i<N; i++){
        int a,b;

        cin >> a >> b;
        grid[i][0] = a;
        grid[i][1] = b;

        if(a < a_min) a_min = a;
        if(a > a_max) a_max = a;
        if(b > b_max) b_max = b;
        if(b < b_min) b_min = b;


    }

    long long dis = INF;
    long long sum = 0;
    for(int i = a_min;i<a_max;i++){
        for(int j = b_min; j < b_max; j++){
            sum  = 0;
            for(int k=0; k < N; k++){
                sum += j - i;
                if(i > grid[k][0]) sum += (i - grid[k][0])*2;
                if(j < grid[k][1]) sum += (grid[k][1] - j)*2;
            }
            if(sum < dis) dis = sum;
        }
    }
    cout << dis << endl;

}