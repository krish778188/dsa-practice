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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head) return NULL;
        ListNode* temp = head;
        int len = 0;
        while(temp) {
            len++;
            temp = temp->next;
        }
        if(len == 1) return NULL;
        temp = head;
        int delIdx = len/2;
        for(int i=0; i<delIdx-1 && temp; i++) temp = temp->next;
        if(temp && temp->next) temp->next = temp->next->next;
        return head;
    }
};