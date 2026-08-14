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
    void helper(ListNode* node, int i, ListNode* &odd, ListNode* &even) {
        if(node == NULL) return;
        if(i%2 != 0 && odd) {
            odd->next = node;
            odd = node;
        }
        else if(i%2 == 0 && even){
            even->next = node;
            even = node;
        }
        helper(node->next, i+1, odd, even);
    }
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* odd = head;
        ListNode* even = NULL;
        ListNode* evenHead = NULL;
        if(head->next) {
            even = head->next;
            evenHead = even;
        }
        helper(even->next, 3, odd, even);
        odd->next = evenHead;
        even->next = NULL;
        return head;
    }
};