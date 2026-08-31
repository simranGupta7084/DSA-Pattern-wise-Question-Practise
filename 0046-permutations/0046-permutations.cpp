class Solution {
public:
    void function(vector<int>& nums, int index, vector<vector<int>>& ans){
        // base case
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = index;i<nums.size();i++){
            // resusrion
            swap(nums[index],nums[i]);

            function(nums,index+1,ans);

            // backtracting
            swap(nums[index],nums[i]); 
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;

        function(nums,0,ans);
        return ans;
        
    }
};