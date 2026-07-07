class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = -1;

        for (int i = 0; i < word.size(); i++) {
            if (word[i] == ch) {
                idx = i;
                break;
            }
        }

        if (idx == -1)
            return word;

        int left = 0, right = idx;

        while (left < right) {
            swap(word[left], word[right]);
            left++;
            right--;
        }

        return word;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna