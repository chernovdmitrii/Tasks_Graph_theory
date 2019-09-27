//https://leetcode.com/problems/multiply-strings/
class Solution {
public:
    string multiply(string num1, string num2) {
        string str(num1.size() + num2.size(), '0');
        
        for (int i = num1.size() - 1; i >= 0; --i) {
            for (int j = num2.size() - 1; j >= 0; --j) {
                int elm_1 = (num1[i] - '0');  // str -> int
                int elm_2 =(num2[j] - '0'); // str -> int
                int elm = elm_1 * elm_2;
                int index = i + j + 1;
                
                while (elm > 0) {
                    elm = elm + str[index] - '0';
                    str[index] = elm % 10 + '0';
                    index = index - 1;
                    elm = elm / 10;
                }
            }
        }
        size_t start_pos = str.find_first_not_of("0");
        if (start_pos != string::npos) return str.substr(start_pos);
        else return "0";
    }

};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string num1 = stringToString(line);
        getline(cin, line);
        string num2 = stringToString(line);
        
        string ret = Solution().multiply(num1, num2);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
