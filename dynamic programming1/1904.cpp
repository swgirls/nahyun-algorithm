#include <iostream>

using namespace std;

int main() {
    int number;
    cin >> number;
    //unsigned long int casenumber = number / 2 + 1;
    unsigned long int tilenumber[500000] = {0,};
    tilenumber[0] = 0;
    tilenumber[1] = 1;
    tilenumber[2] = 2;
    if (number > 2) {
        for(int j = 3; j <= number; j++){
            tilenumber[j] = tilenumber[j-1] + tilenumber[j-2];
        }
    }
    cout << tilenumber[number - 1]%15746 << endl;
    return 0;
}
