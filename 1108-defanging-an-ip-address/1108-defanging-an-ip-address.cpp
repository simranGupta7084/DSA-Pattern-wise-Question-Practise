class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        for(char c : address){
            if(c == '.'){
                res += "[.]";
            }
            else{
                res += c;
            }
        }
        return res;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna