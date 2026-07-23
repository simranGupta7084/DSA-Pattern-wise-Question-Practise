class Solution {
public:
    bool function(vector<int>& nums, int k, int cap){
        int sub = 1;
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]+sum <= cap){
                sum += nums[i];
            }else{
                sub++;
                sum = nums[i];
            }
        }
        return sub <= k;
    }
    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        while(low <= high){
            int mid = low+(high - low)/2;
            if(function(nums,k,mid)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
        
    }
};