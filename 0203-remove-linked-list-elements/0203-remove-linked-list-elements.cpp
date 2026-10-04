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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode* temp = head;
        while(head && head->val == val) {
            temp = head;
            head = head->next;
            delete temp;
        }
        if(!head) return head;
        temp = head;
        while(temp->next) {
            if(temp->next->val == val) {
                ListNode* del = temp->next;
                temp->next = temp->next->next;
                delete del;
            }
            else temp = temp->next;
        }
        return head;
    }
};