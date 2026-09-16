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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // make 2 pointer
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // move fast to n+1 node
        for(int i = 0; i <= n;i++){
            fast = fast->next;
        }
        // move until both on NUll position
        while(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        // now delete the nth node
        slow->next = slow->next->next;

        return dummy->next;
        
    }
};