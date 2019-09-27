//https://leetcode.com/problems/permutation-sequence
class Solution {
public:
    int factorial(int num){
        int pTable[10] = {1};
        for(int i = 1; i <= num; i++) pTable[i] = i * pTable[i - 1];
        return pTable[num]; 
    }
    string getPermutation(int n, int k) {
        vector<int> elms(n);
        int num;
        for (int i = 1; i <= n; ++i)  elms[i - 1] = i;
        
        string sequence = "";
        int fac = factorial(n);
        
        for (int i = n; i >= 2; --i) {
            fac = fac / i;
            num = (k - 1) / fac;
            sequence = sequence + to_string(elms[num]);
            elms.erase(elms.begin() + num);
            k = k - num * fac;
        }
        sequence = sequence + to_string(elms[0]);
        return sequence;
}

};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        string ret = Solution().getPermutation(n, k);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
