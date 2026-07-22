class Solution {
public:
    int Nodays(vector<int>& weights, int cap){
        int day = 1;
        int load = 0;
        for(int w : weights){
            if(load+w <= cap){
                load = load+w;
            }else{
                day++;
                load = w;
            }
        }
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
 
        while(low<high){
            int mid = low+(high-low)/2;
            if(Nodays(weights,mid ) <= days){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};