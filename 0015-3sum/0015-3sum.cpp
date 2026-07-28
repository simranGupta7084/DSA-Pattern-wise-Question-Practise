class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> res;
        int n = a.size();
        sort(a.begin(),a.end());
        for(int i = 0;i<n-2;i++){
            if(i>0 && a[i] == a[i-1])
                continue;
        
            int left = i+1;
            int right = n-1;
            int sum = -a[i];
            while(left < right){
                int s = a[left] + a[right];
                if(s == sum){
                    res.push_back({a[i],a[left],a[right]});
                    left++;
                    right--;
                    while(left<n and a[left] == a[left-1])
                        left++;
                    while(right>=0 and a[right] == a[right+1])
                        right--;
                }else if(s<sum){
                    left++;
                }else{
                    right--;
                }
            }
        }
        return res; 
    }
};