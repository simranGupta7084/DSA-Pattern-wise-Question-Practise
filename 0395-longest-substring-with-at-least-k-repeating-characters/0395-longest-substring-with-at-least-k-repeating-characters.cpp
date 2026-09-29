class Solution {
public:
    int function(string s, int k, int left, int right) {
        if (right - left + 1 < k)
            return 0;

        vector<int> freq(26, 0);

        for (int i = left; i <= right; i++)
            freq[s[i] - 'a']++;

        // Find a character that occurs less than k times
        for (int i = left; i <= right; i++) {
            if (freq[s[i] - 'a'] < k) {

                int j = i + 1;

                while (j <= right && freq[s[j] - 'a'] < k)
                    j++;

                int leftPart = function(s, k, left, i - 1);
                int rightPart = function(s, k, j, right);

                return max(leftPart, rightPart);
            }
        }

        // Every character appears at least k times
        return right - left + 1;
    }

    int longestSubstring(string s, int k) {
        return function(s, k, 0, s.size() - 1);
        
    }
};