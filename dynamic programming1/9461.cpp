#include <iostream>

using namespace std;

int main() {
    int testcase;
    cin >> testcase;
    //unsigned long int casenumber = number / 2 + 1;
    unsigned long int trinumber[100] = {0,};
    for (int i =0; i< testcase; i++) {
        int number;
        cin >> number;
        if (number < 1 || number > 100)
        {
            cout << number << ' ' << "is not available." << endl;
            return -1;
        }
        trinumber[0] = 1;
        trinumber[1] = 1;
        trinumber[2] = 1;
        if(number > 2) {
        for(int j = 3; j <= number; j++){
            trinumber[j] = trinumber[j-3]+trinumber[j-2];
        }
        }
        cout << trinumber[number - 1] << endl;
    }
    
    return 0;
}
