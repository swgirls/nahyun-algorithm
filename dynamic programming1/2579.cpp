#include <iostream>
#include <algorithm>


using namespace std;

int main() {
    int floornumber;
    cin >> floornumber;
    int floor[301] = {0,};
    int cost[301][301] = {0,};
    if(floornumber > 300) {
        cout << "floor's number is not available" << endl;
        return -1;
    }
    for (int i = 1; i <= floornumber; i++){
        cin >> floor[i];
        if (floor[i] > 10000) {
            cout << "floor score is not available";
            cin >> floor[i];
        }
    }//입력받는 부분
    cost[0][1] = floor[1];
    cost[0][2] = floor[2];
    for(int i = 1; i < floornumber; i++){
        if(i < 2) {
            cost[i][i+1] = cost[i-1][i] + floor[i+1];
            cost[i][i+2] = cost[i-1][i] + floor[i+2];
        }
        else {
            
            if(i+1 <= floornumber) {
                cost[i][i+1] = cost[i-2][i] + floor[i+1];
            }
            if(i+2 <= floornumber){
               //cout << i << i+1 << i+2 << endl;
                cost[i][i+2] = max(cost[i-1][i],cost[i-2][i]) + floor[i+2];
            }
        }

    }
    int maxVal = cost[0][floornumber];
    for(int i = 0; i <  floornumber; i++) {
        //cout << cost[i][floornumber] << endl;
        maxVal = max(maxVal, cost[i][floornumber]);
    }
    cout << maxVal;
    return 0;
}