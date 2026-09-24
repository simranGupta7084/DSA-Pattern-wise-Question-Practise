class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> f;

        for(char c:t){
            f[c]++;
        }

        int left = 0;
        int start = 0;
        int count = t.size();
        int minLen = INT_MAX;

        for(int right = 0; right<s.size();right++){
            if(f[s[right]]> 0){
                count--;
            }
            f[s[right]]--;

            while(count == 0){
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                f[s[left]]++;

                if (f[s[left]] > 0) {
                    count++;
                }

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};