/*全探索　全列挙型

0728 ok

*/

#include <iostream>
using namespace std;

int main(){

    int n,x;
    while(true){
        cin >> n >> x;
        if(n==0 && x==0){
            return 0;
        }

        int sum = 0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int k = x - i - j;
                if(k > j && k <= n){
                    sum++;
                }
            }
        }

        cout << sum << endl;


    }
}