class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int wordLen = words[0].size();
        int wordCount = words.size();

        unordered_map<string, int> freq;

        // Required frequency of each word
        for (string word : words) {
            freq[word]++;
        }

        // Try each possible starting offset
        for (int start = 0; start < wordLen; start++) {

            int left = start;
            int count = 0;

            unordered_map<string, int> window;

            for (int right = start;
                 right + wordLen <= s.size();
                 right += wordLen) {

                string word = s.substr(right, wordLen);

                // Word is not required
                if (freq.find(word) == freq.end()) {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                // Add word to window
                window[word]++;
                count++;

                // Too many occurrences of this word
                while (window[word] > freq[word]) {
                    string remove = s.substr(left, wordLen);
                    window[remove]--;
                    left += wordLen;
                    count--;
                }

                // All words found
                if (count == wordCount) {
                    ans.push_back(left);

                    // Move window forward
                    string remove = s.substr(left, wordLen);
                    window[remove]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
        
    }
};