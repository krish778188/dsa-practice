/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    void helper(ListNode* head, stack<int> &s) {
        if(head == NULL) return;
        s.push(head->val);
        helper(head->next, s);
    }
public:
    int getDecimalValue(ListNode* head) {
        stack<int> s;
        helper(head, s);
        int base2 = 1, ans = 0;
        while(s.size() > 0) {
            int val = s.top();
            ans += val*base2;
            base2 *= 2;
            s.pop();
        }
        return ans;
    }
};