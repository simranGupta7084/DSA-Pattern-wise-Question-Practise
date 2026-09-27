class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> freq;

        // Store frequency of remainders
        for (int x : arr) {
            int rem = x % k;
            if (rem < 0) rem += k;   // handle negative numbers
            freq[rem]++;
        }

        // Check whether every remainder has its complement
        for (auto it : freq) {
            int rem = it.first;
            int count = it.second;

            if (rem == 0) {
                if (count % 2 != 0)
                    return false;
            }
            else {
                int complement = k - rem;

                if (freq[rem] != freq[complement])
                    return false;
            }
        }

        return true;
        
    }
};