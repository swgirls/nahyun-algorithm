#include <iostream>
#include <algorithm>

using namespace std;



int main() {
    int number;
    cin >> number;
    int cost[10001] = {0,};
    int grape[10001] = {0,};
    if (number < 1 || number > 10000) {
        cout << "number is not available";
        return -1;
    }
    for(int i=1; i<=number; i++){
        cin >> grape[i];
    }// 양 입력

    cost[1] = grape[1];
    cost[2] = grape[2] + grape[1];
    cost[3] = max(cost[2], cost[2] - grape[1] + grape[3]);
    cost[3] = max(cost[3],cost[1] + grape[3]);
    for(int i=4; i <= number;i++){
        cost[i] = max(cost[i-2] + grape[i], cost[i-3] + grape[i-1] + grape[i]);
        cost[i] = max(cost[i],cost[i-1]);
        //cout << cost[i] << endl;
    }
    
    cout << cost[number];
    return 0;
}