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
} 재귀함수를 쓴 경우에는 이렇게 코드를 작성한다. */ 

int main() {
    int number;
    cin >> number;
    if(number > 90){
        cout << number;
        cout << " is not available" << endl;
        return -1;
    } 
    unsigned long int fibonacci[90] = {0,}; //너무 길어서 자료형을 이렇게 하니까 되었다. 
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for (int i = 2; i <= number; i++) {
        fibonacci[i] = fibonacci[i -1] + fibonacci[i-2];
        //cout << fibonacci[i] << endl;
    }

    cout << fibonacci[number] << endl;
    return 0;
}