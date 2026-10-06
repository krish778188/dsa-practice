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
    ListNode* reverse(ListNode* start, ListNode* end) {
        if(!start || !end) return start;
        ListNode* next = end->next;
        ListNode* prev = next;
        ListNode* curr = start;
        while(curr != next) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start = head;
        ListNode* prevGroup = nullptr;
        while(start) {
            ListNode* end = start;
            for(int i=1; i<k && end; i++) end = end->next;
            if(!end) break;
            ListNode* nextGroup = end->next;
            ListNode* newStart = reverse(start, end);

            if(prevGroup) prevGroup->next = newStart;
            else head = newStart;

            prevGroup = start;
            start = nextGroup;
        }
        return head;
    }
};