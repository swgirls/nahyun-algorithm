#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int number;
    int maxCost;
    cin >> number;
    if (number < 1 || number > 500)
    {
        cout << "number is not available";
        return -1;
    }
    int triangle[500][500] = {0,};
    int cost[500][500] = {0,};
    for(int i = 0; i < number; i++){
        for(int j = 0; j < i+1; j++){
            cin >> triangle[i][j];
            if(triangle[i][j] > 9999 || triangle[i][j] < 0) {
                cout << "number is not available";
                cin >> triangle[i][j];
            }
        }
    }
    cost[0][0] = triangle[0][0];
    cost[1][0] = cost[0][0] + triangle[1][0];
    cost[1][1] = cost[0][0] + triangle[1][1];
    maxCost = max(cost[1][0], cost[1][1]);
    for(int i = 2; i < number; i++){
        for(int j = 0; j < i+1; j++) {
            if(j == 0) {
                cost[i][j] = cost[i - 1][j] + triangle[i][j];
            }
            else if (j == i) {
                cost[i][j] = cost[i-1][j-1] + triangle[i][j];
            }
            else {
                cost[i][j] = max(cost[i-1][j-1], cost[i-1][j]) + triangle[i][j];
            }
        }
    }
    maxCost = cost[number -1][0];
    for(int i = 0; i < number; i++){
        maxCost = max(maxCost, cost[number -1][i]);
    }
    cout << maxCost;

    return 0;
}