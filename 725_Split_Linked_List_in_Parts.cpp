//https://leetcode.com/problems/split-linked-list-in-parts/](https://leetcode.com/problems/split-linked-list-in-parts/
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        
        vector<ListNode*> arr (k);
        
        ListNode* node = root;
        int count = 0;
        while (node != NULL) {
            count++;
            node = node -> next;
        }
        
        int quand = count / k; 
        int reminder = count % k;
        
        for (int i = 0; i < k; ++i) {
            if (root != NULL) {
                arr[i] = NULL;
                ListNode *smp = NULL;
                for (int j = 0; j < quand + (reminder > 0 ? 1 : 0); ++j) {
                    ListNode *node = new ListNode(root -> val);
                    root = root -> next;
                    
                    if (smp != NULL) smp -> next = node;
                    if (arr[i] == NULL) arr[i] = node;
                    smp = node;
                }
                reminder--;
            }
        }
        return arr;
    }
};
