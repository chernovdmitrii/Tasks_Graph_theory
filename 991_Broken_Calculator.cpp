//https://leetcode.com/problems/broken-calculator/
#include <iostream>
using namespace std;


int brokenCalc(int X, int Y) {
    int result = 0;
    while (Y > X) {
        result++;
        if (Y % 2 == 1){
            Y++;
        } else {
            Y /= 2;
        }
    }

    return result + X - Y;
}

int main() {
    int result = brokenCalc(2 , 3);//2
    cout << result << endl;
    result = brokenCalc(5 , 8);//2
    cout << result << endl;
    result = brokenCalc(3 , 10);//3
    cout << result << endl;
    result = brokenCalc(1024 , 1);// 1023
    cout << result << endl;
    return 0;
}
