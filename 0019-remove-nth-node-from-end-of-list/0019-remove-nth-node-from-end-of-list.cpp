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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        int len = 0;
        ListNode* temp = head;
        while(temp) {
            len++;
            temp = temp->next;
        }
        if(len == 1 && n == 1) return NULL;
        if(len-n == 0) {
            return head = head->next;
        }
        temp = head;
        int delIdx = len - n - 1;
        while(delIdx-- && temp) temp = temp->next;
        if(temp->next) temp->next = temp->next->next;

        return head;
    }
};