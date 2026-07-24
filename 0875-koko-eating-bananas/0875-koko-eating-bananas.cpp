class Solution {
public:
bool function(vector<int>& piles,int h,int speed){
    long long time = 0;
    for(int p : piles){
        time += (p + speed - 1) / speed;
    }
    return time<=h;

}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (function(piles,h,mid)) {   
                high = mid - 1;     
            }
            else {
                low = mid + 1;    
            }
        }

        return low;
        
    }
};