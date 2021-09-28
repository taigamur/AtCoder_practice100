#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

/*
未解決問題
0928 解説見ながら時間かけてAC
発想が難しかった
*/

/*
演算結果が0以上20以下しか扱わなくていい部分が大事
演算結果が sum+x , sum-x　としてDPで解く
*/

int main(){
    int n;
    cin >> n;
    vector<ll> num(n);
    for(int i = 0; i <n-1; i++){
        cin >> num[i];
    }
    int ans;
    cin >> ans;

    vector<vector<ll>> list(n,vector<ll>(21,0));

    list[0][num[0]] = 1;


    for(int i = 1; i < n-1; i++){
        for(int j = 0; j <= 20; j++){

            if(list[i-1][j] != 0){
                if(j + num[i] <= 20){
                    list[i][j+num[i]] += list[i-1][j];
                }
                if(j - num[i] >= 0){
                    list[i][j-num[i]] += list[i-1][j];
                }
            }

        }
    }

    cout << list[n-2][ans] << endl;




}