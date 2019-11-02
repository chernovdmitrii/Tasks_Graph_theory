//https://leetcode.com/problems/pascals-triangle/
#include <iostream>
#include <vector>
using namespace std;

void print(const vector<vector<int>>& v){
    for(auto i : v){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result(numRows);
    print(result);
    for (int i = 0; i < numRows; ++i) {
        //print(result);
        result[i].resize(i + 1);
        result[i][0] = 1;
        result[i][i] = 1;
        //print(result);
        for (int j = 1; j < i; j++) {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            //print(result);
        }
    }
    return result;
}

int main() {
    vector<vector<int>> Generate = generate(5);
    print(Generate);

}
