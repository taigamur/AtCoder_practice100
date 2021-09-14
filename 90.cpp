#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;


/*
0915 ACにはならなかった
最小値の最大化問題は2分探索が有効
N+M個の縁の半径の最小値をx以上にすることは可能かという考え方

*/

//判定
bool check(vector<double> x, vector<double> y, vector<double> r, double val){
    for(int i = 0; i < x.size(); i++){
        for(int j = i+1; j < x.size(); j++){
            double dis = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));

            double r1,r2;
            if(i < r.size()){
                r1 = r[i];
            }else{
                r1 = val;
            }

            if(j < r.size()){
                r2 = r[j];
            }else{
                r2 = val;
            }

            if(dis < r1 + r2) return false;
        }
    }
    return true;
}

int main(){
    int N,M;
    cin >> N >> M;

    double mi = 100;
    vector<double> x(N+M),y(N+M),r(N);
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i] >> r[i];
        if(r[i] < mi){
            mi = r[i];
        }
    }

    for(int i = 0; i < M; i++){
        cin >> x[i] >> y[i];
    }

    //既にある円の半径が最小値になる場合もある
    //2分探索
    double left = 0;
    double right = mi;
    //整数値ではなく、rootの場合もあるので、繰り返し回数で終了判定
    for(int i = 0; i < 100; i++){
        double mid = (left + right) /2;
        if(check(x,y,r,mid)){
            left = mid;
        }else{
            right = mid;
        }
    }

    cout << fixed << setprecision(10) << left << endl;

    

}