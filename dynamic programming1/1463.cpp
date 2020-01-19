#include <iostream>
#include <algorithm>

#define MAXNUM 1000

using namespace std;

int main() {
    int number;
    cin >> number;
    if (number < 1 || number > 1000000) {
        cout << "number is not available";
        return -1;
    }
    int result[300][300] = {0,};
    int count = 0;
    for(int i = 0; i < 3; i++) {
        result[count][i] = number;
    }
    while (true) {
        count++;
        for(int i = 0; i < 3*count; i++) {
            if(result[count - 1][i]%3 == 0) {
                result[count][i] = result[count -1][count/3]/3;
            }
            else if(result[count-1][i]% 2 == 0){
                result[count][i] = result[count - 1][count/3]/2;
            }
            else {
                result[count][i] = result[count -1][count/3] -1;
            }
            cout << result[count][i] << endl;
            if(result[count][i] == 1) {
                cout << count;
                return 0;
            }

        }
        
    }
    return 0;

}