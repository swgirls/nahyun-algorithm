#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    int number;
    unsigned long int result;
    cin >> number;
    if(number < 1 || number > 100) {
        cout << "number is not available";
        return -1;
    }
    unsigned long int dp[101][101] = {0,};
    for(int j=0; j < 10; j++) {
        dp[1][j] = 1;
    }// 갯수 초기화*/
    dp[1][0] = 0;
    //첫번째 자리에는 0이 올 수 없기 때문이다.
    
    for(int i =2; i <= number; i++) {
        for(int j=0; j < 10; j++){
            if(j == 0) {
                dp[i][j] = dp[i-1][j+1] % 1000000000;
            }
            else if(j == 9){
                dp[i][j] = dp[i -1][j - 1] % 1000000000;
            }
            else {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1] % 1000000000;
            }
        }
    }
    result = 0;
    for(int i = 0; i< 10; i++) {
        //cout << dp[number][i] << endl;
        result += dp[number][i];
    }
    
    cout << result % 1000000000;

    return 0;
}