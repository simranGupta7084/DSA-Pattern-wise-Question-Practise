class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int, int>> v;

        // Store {value, original index}
        for (int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});
        }

        // Sort according to value
        sort(v.begin(), v.end());

        int minIn = v[0].second;
        int res = 0;

        for (int j = 1; j < v.size(); j++) {

            res = max(res, v[j].second - minIn);

            minIn = min(minIn, v[j].second);
        }

        return res;
    }
};