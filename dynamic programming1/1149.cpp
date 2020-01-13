#include <iostream>
#include <algorithm>


using namespace std;

int main() {
    int housenumber;
    int minVal;
    cin >> housenumber;
    if (housenumber > 1000) {
        cout << "house's number is too large";
        return -1;
    }
    int house[1000][3] = {0,};
    int minCost[1000][3] = {0,};
    for(int i =0; i< housenumber; i++) {
        for(int j =0; j< 3; j++) {
             cin >> house[i][j]; //
             if(house[i][j] > 1000){
                 cout << "house's cost is too expensive";
                 cin >> house[i][j];
             }
        } 
    }// 집 색깔별로 비용 입력
    minCost[0][0] = house[0][0];
    minCost[0][1] = house[0][1];
    minCost[0][2] = house[0][2];
    for(int i =1; i< housenumber; i++) {
        minCost[i][0] = min(minCost[i-1][1],minCost[i-1][2]) + house[i][0];
        minCost[i][1] = min(minCost[i-1][0],minCost[i-1][2]) + house[i][1];
        minCost[i][2] = min(minCost[i-1][0],minCost[i-1][1]) + house[i][2];
        cout << minCost[i][0] << minCost[i][1] << minCost[i][2] << endl;
    }
    minVal = minCost[housenumber - 1][0];
    for(int i =0; i<3; i++) {
        minVal = min(minVal, minCost[housenumber - 1][i]);
    }
    cout << minVal;
    
     
    return 0;
}
