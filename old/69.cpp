#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int Q = 100005;    
vector<int> prime(Q);

int size = 0;

void judge_prime(int n){
    int j = 2;
    while(j <= sqrt(n)){
        if(n%j == 0){
            return;
        }
        j++;
    }
    prime[size] = n;
    size++;
    return;
}

int main(){
    int N;
    cin >> N;
    int a,b;

    prime[size] = 2;
    size++;
    for(int i=0;i<10;i++){
        cout << prime[i] << " ";
    }

}