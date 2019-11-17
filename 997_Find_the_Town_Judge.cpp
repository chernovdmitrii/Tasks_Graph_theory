//https://leetcode.com/problems/find-the-town-judge/
#include <iostream>
#include <vector>

using namespace std;

int findJudge(int N, vector<vector<int>> &trust) {
    vector<int> in(N + 1);
    vector<int> out(N + 1);
    int judge = -1;

    for (int i = 0; i < trust.size(); i++) {
        in[trust[i][1]]++;
        out[trust[i][0]]++;
    }

    for (int i = 0; i <= N; i++)
        if (in[i] == N - 1 && out[i] == 0)
            judge = i;

    return judge;
}

int main() {
    {int N = 2;
        vector<vector<int>> test = {{1, 2}};
        if (findJudge(N, test) != 2) {
            return 1;
        } else {
            cout << findJudge(N, test) << endl;
        }
    }

    {int N = 3;
        vector<vector<int>> test = {{1, 3}, {2, 3}};
        if (findJudge(N, test) != 3) {
            return 2;
        } else {
            cout << findJudge(N, test) << endl;
        }

    }
    {int N = 3;
        vector<vector<int>> test = {{1, 3}, {2, 3}, {3, 1}};
        if (findJudge(N, test) != -1) {
            return 3;
        } else {
            cout << findJudge(N, test) << endl;
        }
    }
return 0;
}
