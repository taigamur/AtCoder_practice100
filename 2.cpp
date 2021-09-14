#include <iostream>
using namespace std;

/*
0728 ok
*/


int judge(int n){
    int sum = 0;
    for(int i=1;i<=n;i+=2){
        if(n % i == 0){
            sum++;
        }
    }
    return sum;
}

int main(){
    int N;
    cin >> N;
    int sum = 0;
    for(int i=1;i <=N;i++){
        if(judge(i) == 8) sum++;
    }

    cout << sum << endl;

}