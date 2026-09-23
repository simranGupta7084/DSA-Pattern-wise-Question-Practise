class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> freq;

        string word = "";

        for (int i = 0; i <= paragraph.size(); i++) {
            if (i < paragraph.size() && isalpha(paragraph[i])) {
                word += tolower(paragraph[i]);
            }
            else {
                if (!word.empty() && ban.find(word) == ban.end()) {
                    freq[word]++;
                }
                word = "";
            }
        }

        string ans = "";
        int maxi = 0;

        for (auto it : freq) {
            if (it.second > maxi) {
                maxi = it.second;
                ans = it.first;
            }
        }

        return ans;
        
    }
};