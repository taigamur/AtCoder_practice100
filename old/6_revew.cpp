#include <iostream>
using namespace std;

/*
char と　int　の扱いが非常に参考になる
*/

int main(){
    cin >> N >> S;
    
    string S;
    int N,cnt;

    for(int i=0;i<1000;i++){
        
        int c[3] = {i/100 , (i/10)%10 , i%10};
        int f = 0;
        for(int j=0; j < N; j++){
            if(S[j] - '0' == c[f]) f++;//数字を数値に変換している
            if(f == 3) break;
        }
        if(f == 3)cnt++;
    }
    cout << cnt << endl;

}