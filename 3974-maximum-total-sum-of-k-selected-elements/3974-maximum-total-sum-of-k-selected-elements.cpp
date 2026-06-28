class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end(),greater<int>());
        long long ans = 0;
        for(int i =0;i<k;i++){
            if(mul>1){
                ans = ans+1LL*nums[i]*mul;
            }else{
                ans = ans +nums[i];
            }
            mul--;
        } 
        return ans;        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna