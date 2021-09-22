#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
using namespace std;

/*
0921 AC
setprecisionで桁を指定しないとWAになる
*/

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> map(n);
    int list[n];
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        pair<int,int> p;
        p.first = a;
        p.second = b;
        map[i] = p;
        list[i] = i;
    }

    double sum = 0;
    double dis = 0;
    do{
        
        for(int i = 0; i < n - 1; i++){
            dis += sqrt((map[list[i]].first - map[list[i+1]].first)*(map[list[i]].first - map[list[i+1]].first) + 
            (map[list[i]].second - map[list[i+1]].second) * (map[list[i]].second - map[list[i+1]].second));
        }
        sum++;
    }while(next_permutation(list,list+n));

    cout << fixed << setprecision(10) << dis / sum << endl;
}