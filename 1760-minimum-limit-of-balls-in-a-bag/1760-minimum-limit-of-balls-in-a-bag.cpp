class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high =*max_element(nums.begin(), nums.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            long long operations = 0;

            for (int balls : nums) {
                operations += (balls - 1) / mid;
            }

            if (operations <= maxOperations) {
                // mid is possible; try a smaller penalty
                high = mid;
            }
            else {
                // Too many operations; increase penalty
                low = mid + 1;
            }
        }

        return low;
        
    }
};