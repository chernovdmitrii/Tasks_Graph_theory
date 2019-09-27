//https://leetcode.com/problems/add-two-numbers/  
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        ListNode *prev = NULL;
        
        int rem = 0; //reminder
        
        while (l1 || l2) {
            int sum_1, sum_2, sum; 
            
            if (l1) sum_1 = l1 -> val;
            else sum_1 = 0; 
            
            if (l2) sum_2 = l2 -> val;
            else sum_2 = 0; 
            
            sum = sum_1 + sum_2 + rem; 
            
            rem = sum / 10;
            sum = sum % 10;
            
            ListNode *newnode = new ListNode(sum); //new(point)
            
            if (!head) head = newnode; //emptycheck
            if (prev) prev -> next = newnode; //
            
            prev = newnode;
            
            if (l1) l1 = l1 -> next;
            else l1 = NULL; 
            if (l2) l2 = l2 -> next; 
            else l2 = NULL; 
        }
        
        if (rem > 0) {
            ListNode *newnode = new ListNode(rem);
            prev -> next = newnode;
        }
        return head;
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

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
