//https://leetcode.com/problems/rectangle-area/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
         if (C<=E || A>=G || B>=H || D<=F )
            return (C-A) * (D-B) + (G-E) * (H-F);
        else
        {
            vector <int> h;
            h.push_back(A);
            h.push_back(C);
            h.push_back(E);
            h.push_back(G);

            vector <int> v;
            v.push_back(B);
            v.push_back(D);
            v.push_back(F);
            v.push_back(H);

            sort(h.begin(), h.end());
            sort(v.begin(), v.end());

            int total = - (h[2] - h [1]) * (v[2] - v[1])
                        + (C-A) * (D-B) + (G-E) * (H-F) ;
            return total;
        }
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int A = stringToInteger(line);
        getline(cin, line);
        int B = stringToInteger(line);
        getline(cin, line);
        int C = stringToInteger(line);
        getline(cin, line);
        int D = stringToInteger(line);
        getline(cin, line);
        int E = stringToInteger(line);
        getline(cin, line);
        int F = stringToInteger(line);
        getline(cin, line);
        int G = stringToInteger(line);
        getline(cin, line);
        int H = stringToInteger(line);
        
        int ret = Solution().computeArea(A, B, C, D, E, F, G, H);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
