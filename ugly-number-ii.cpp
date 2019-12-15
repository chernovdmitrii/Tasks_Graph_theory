//https://leetcode.com/problems/ugly-number-ii/

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0)
            return 0;
            
        int idx2 = 0, idx3 = 0, idx5 = 0;
        int candidate1 = 0, candidate2 = 0, candidate3 = 0;
        int i = 0,  min = 0;
        vector<int> uglyNumbers(n, 0);
        
        uglyNumbers[0] = 1;
        
        for (i = 1; i < n; ++i)
        {
            candidate1 = uglyNumbers[idx2] * 2;
            candidate2 = uglyNumbers[idx3] * 3;
            candidate3 = uglyNumbers[idx5] * 5;
            
            min = candidate1;
            if (min > candidate2)
                min = candidate2;
            if (min > candidate3)
                min = candidate3;
                
            uglyNumbers[i] = min;
            if (min == candidate1)
                ++idx2;
                
            if (min == candidate2)
                ++idx3;
                
            if (min == candidate3)
                ++idx5;
        }
        
        return uglyNumbers[n-1];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().nthUglyNumber(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
