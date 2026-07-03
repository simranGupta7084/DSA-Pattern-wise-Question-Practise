class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for(int c: nums){
            ans.push_back(to_string(c));
            
        }
        sort(ans.begin(),ans.end(),[](const string& a,const string &b){
        return a+b > b+a;
    });

        if(ans[0] =="0") return "0";

        string res;
        for(string s : ans){
            res+= s;
        }
        return res;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna