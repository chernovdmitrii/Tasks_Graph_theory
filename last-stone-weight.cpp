//https://leetcode.com/problems/last-stone-weight/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
         for (int i = stones.size() / 2 + 1; i >= 0; i--) {
            siftDown(i, stones);
        }

        while (stones.size() >= 2) {
            int y = extractMax(stones);
            int x = extractMax(stones);

            if (x != y) {
                insert(y - x, stones);
            }
        }

        return stones.empty() ? 0 : stones[0];
    }

    void siftDown(size_t i, vector<int> & heap) {
        while (2*i + 1 < heap.size()) {
            int left = 2*i + 1;
            int right = 2*i + 2;

            int m = left;
            if (right < heap.size() && heap[right] > heap[left])
                m = right;

            if (heap[i] >= heap[m])
                break;

            swap(heap[i], heap[m]);
            i = m;
        }
    }

    void siftUp(size_t i, vector<int> & heap) {
        int par = (i - 1) / 2;
        while (par >= 0 && heap[i] >= heap[par]) {
            swap(heap[i], heap[par]);
            i = par;
            par = (i - 1) / 2;
        }
    }

    int extractMax(vector<int> & heap) {
        int max = heap[0];

        swap(heap[heap.size() - 1], heap[0]);

        heap.erase(heap.begin() + heap.size() - 1);

        siftDown(0, heap);
        return max;
    }


    void insert(int val, vector<int> & heap) {
        heap.push_back(val);
        siftUp(heap.size() - 1, heap);
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> stones = stringToIntegerVector(line);
        
        int ret = Solution().lastStoneWeight(stones);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
