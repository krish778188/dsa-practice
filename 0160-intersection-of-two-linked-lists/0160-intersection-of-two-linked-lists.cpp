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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *tA = headA;
        ListNode *tB = headB;
        while(tA) {
            lenA++;
            tA = tA->next;
        }
        while(tB) {
            lenB++;
            tB = tB->next;
        }

        int diff = abs(lenA - lenB);
        tA = headA; tB = headB;

        if(lenA > lenB) while(diff--) tA = tA->next;
        else while(diff--) tB = tB->next;

        while(tA && tB) {
            if(tA == tB) return tA;
            tA = tA->next;
            tB = tB->next;
        }

        return NULL;
    }
};