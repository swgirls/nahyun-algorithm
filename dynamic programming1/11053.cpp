#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int number;
    cin >> number;
    int dp[1000] = {1,};
    int sequence[1000] = {0,};
    int result[1000] = {0,};
    int count = 0;
    if(number < 1 || number > 1000){
        cout << "number is not available" << endl;
        return -1;
    }
    for(int i = 0; i < number; i++) {
        cin >> sequence[i];
    }//입력을 받음
    //dp[0] = 0;
    int maxVal = 0;
    for(int i = 0; i <number; i++) {
        for(int j = 0; j < i; j++) {
            if(sequence[j] < sequence[i]) {
                maxVal = max(maxVal, dp[j]);
            //if (i == 5) cout << dp[j] << " ";
            }
        }
        dp[i] = maxVal + 1;
        maxVal = 0;
    }
    maxVal = dp[0];
    for(int i =0; i <number; i++) {
        maxVal = max(maxVal, dp[i]);
        //cout << dp[i] << " ";
    }
    cout << maxVal;
    return 0;

}