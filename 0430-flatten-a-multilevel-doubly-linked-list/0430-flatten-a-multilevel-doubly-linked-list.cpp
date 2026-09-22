/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) return head;

        Node* curr = head;

        while (curr != nullptr) {
            if (curr->child != nullptr) {
                Node* next = curr->next;
                Node* child = curr->child;

                // Connect child to curr
                curr->next = child;
                child->prev = curr;
                curr->child = nullptr;

                // Find tail of child list
                Node* tail = child;

                while (tail->next != nullptr) {
                    tail = tail->next;
                }

                // Connect tail to original next node
                tail->next = next;

                if (next != nullptr) {
                    next->prev = tail;
                }
            }

            curr = curr->next;
        }

        return head;
        
    }
};