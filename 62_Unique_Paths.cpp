//https://leetcode.com/problems/unique-paths/
#include <iostream>

using namespace std;

int uniquePaths(int m, int n) {
    int N = n + m - 2;
    int K = m - 1;
    long result = 1;
    for (int i = 1; i <= K; i++)
        result = result * (N - K + i) / i;
    return (int)result;
}


int main() {

    int result = uniquePaths(3, 2);//2
    cout << result << endl;
    result = uniquePaths(10, 10);//2
    cout << result << endl;

    return 0;
}
