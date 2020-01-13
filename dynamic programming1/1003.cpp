#include <iostream>

using namespace std; // cout endl을 사용하기 위한 라이브러리처럼 생각하면 된다 
//endl은 end line을 의미한다. ㅎ

/*int fibonacci(int n){
    if (n == 0)
    {
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci (n -2);
    }
}*/

int main() {
    int testcase;
    cin >> testcase;
    for (int j = 0 ; j < testcase; j++) {
        int number;
        cin >> number;
        if(number > 40){
            cout << number;
            cout << " is not available" << endl;
            return -1;
        } 
        unsigned long int fibonacci_zero[40] = {0,};
        unsigned long int fibonacci_one[40] = {0,};
        unsigned long int fibonacci[40] = {0,};
        fibonacci[0] = 0;
        fibonacci[1] = 1;
        fibonacci_zero[0] = 1;
        fibonacci_zero[1] = 0;
        fibonacci_one[0] = 0;
        fibonacci_one[1] = 1;
        for (int i = 2; i <= number; i++) {
            fibonacci_zero[i] = fibonacci_zero[i -1] + fibonacci_zero[i-2];
            fibonacci_one[i] = fibonacci_one[i -1] + fibonacci_one[i-2];
            fibonacci[i] = fibonacci[i -1] + fibonacci[i-2];
            //cout << fibonacci[i] << endl;
        }

        cout << fibonacci_zero[number] << ' ' << fibonacci_one[number] << endl;
    }
            return 0;
}