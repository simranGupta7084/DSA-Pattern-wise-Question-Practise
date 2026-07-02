class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            int freq[26] = {0};

            for (int j = i; j < n; j++) {

                freq[s[j] - 'a']++;

                int mx = 0;
                int mn = INT_MAX;

                for (int k = 0; k < 26; k++) {

                    if (freq[k] > 0) {
                        mx = max(mx, freq[k]);
                        mn = min(mn, freq[k]);
                    }
                }

                ans += (mx - mn);
            }
        }

        return ans;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna