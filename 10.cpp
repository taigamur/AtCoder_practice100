#include <iostream>
#include <vector>
using namespace std;

/*
ビット全探索の例題
0730 ok
*/

int N;
int j;
int sum;
int tf = 0;
vector<int> t;

bool calc(int a,int sum,int count){

    sum += a;
    if(count == t.size()){
        if(sum == j) tf = 1;
    }else{
        calc(0,sum,count+1);
        calc(t[count],sum,count+1);
    }

    if(tf == 1) return true;
    else return false;

}

int main(){
    
    cin >> N;
    
    for(int i=0; i < N; i++){
        int a;
        cin >> a;
        t.push_back(a);
    }

    int M;
    cin >> M;

    for(int i=0; i < M; i++){

        cin >> j;
        sum = 0;
        tf = 0;
        calc(0,0,0);
        if(tf == 1){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
        
    }
}