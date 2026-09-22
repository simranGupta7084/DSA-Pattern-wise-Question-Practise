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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        ListNode* second = head;
        ListNode* temp = head;

        // Find kth node in begining
        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        // Find kth node from end
        temp = first->next;

        while (temp != nullptr) {
            temp = temp->next;
            second = second->next;
        }

        // Swap values
        swap(first->val, second->val);

        return head;
        
    }
};