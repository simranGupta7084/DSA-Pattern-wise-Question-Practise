class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int low = 0;
        int high = 0;
        int res = -1;
        int s = fruits.size();
        for(int high = 0; high<s;high++){
            mp[fruits[high]]++;
            while(mp.size() > 2){
                mp[fruits[low]]--;
                if(mp[fruits[low]]==0){
                    mp.erase(fruits[low]);
                }
                low++;
            }
            int len = high-low+1;
            res = max(res,len);
        }
        return res;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna