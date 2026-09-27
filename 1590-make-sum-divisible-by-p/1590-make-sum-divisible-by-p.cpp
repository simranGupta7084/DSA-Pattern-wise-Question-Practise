class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;

        for (int x : nums)
            total += x;

        int target = total % p;

        // Already divisible
        if (target == 0)
            return 0;

        unordered_map<int, int> mp;

        // prefix remainder 0 at index -1
        mp[0] = -1;

        long long prefix = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i]) % p;

            int need = (prefix - target + p) % p;

            if (mp.find(need) != mp.end()) {
                ans = min(ans, i - mp[need]);
            }

            // Store latest index
            mp[prefix] = i;
        }

        return ans == nums.size() ? -1 : ans;
        
    }
};