#include <iostream>
using namespace std;
const long long INF = 1LL << 60;
/*
工夫して通り数を減らす全列挙

0729 
*/

int comp(int a,int b){
    if(a > b){
        return b;
    }else{
        return a;
    }
}

int main(){

    int a,b,c;
    int x,y;
    cin >> a >> b >> c >> x >> y;

    int c_max;
    if(x > y){
        c_max = x*2;
    }else{
        c_max = y*2;
    }
    long long min = INF;

    for(int i=0;i<=c_max;i+=2){
        int n_x = 0;
        int n_y = 0;
        if(x - i/2 > 0){
            n_x = x - i/2;
        }
        if(y - i/2 > 0){
            n_y = y - i/2;
        }
        
        long long sum = a*n_x + b*n_y + c*i;
        if(sum < min) min = sum;
    }
    cout << min << endl;
    

}