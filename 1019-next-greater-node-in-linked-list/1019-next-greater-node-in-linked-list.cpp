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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        // convert the linked list into vector

        while(head != nullptr){
            nums.push_back(head->val);
            head = head->next;
        }

        int n = nums.size();
        vector<int> ans(n,0);
        // store indexes
        stack<int > st;

        // now find the next greator
        for(int i = 0;i<n;i++){
            while(!st.empty() && nums[i] > nums[st.top()]){
                ans[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;

        
    }
};