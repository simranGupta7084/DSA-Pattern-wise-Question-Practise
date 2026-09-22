class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> q;

        vector<int> ans;

        for(int x : nums1){
            q[x]++;

        }
        for(int x : nums2){
            if(q[x] > 0){
                ans.push_back(x);
                q[x]--;
            }
        }
        return ans;
    }
};