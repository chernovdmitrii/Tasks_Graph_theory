// https://leetcode.com/problems/reverse-integer
class Solution {
public:
    int reverse(int x) {
        long long rem; 
        long long rev = 0; 
        while(x != 0){    
             rem = x % 10;      
             rev = (rev * 10) + rem;    
             x /= 10;    
        } 
        if (rev > INT_MAX || rev < INT_MIN){
            return 0; 
        } else {
            return rev; 
        }
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
