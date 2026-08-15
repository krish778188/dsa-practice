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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* prev2 = NULL;
        while(temp) {
            while(prev && temp && prev->val == temp->val) {
                prev2 = temp;
                temp = temp->next;
                delete prev2;
            }
            // if(prev2) prev2->next = NULL;
            if(prev) prev->next = temp;
            prev = temp;
            if(temp) temp = temp->next;
        }
        return head;
    }
};