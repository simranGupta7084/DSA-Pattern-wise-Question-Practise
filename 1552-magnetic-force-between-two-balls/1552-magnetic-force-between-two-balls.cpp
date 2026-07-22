class Solution {
public:
    bool function(vector<int>& position, int m, int dist){
        int c = 1;
        int last = position[0];
        for(int i=1;i<position.size();i++){
            if((position[i] - last) >= dist){
                c++;
                last = position[i];
            }
            if(c >= m) return true;
        }
        return false;
        
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low = 1;
        int high = position.back()-position.front(); 
        while(low<=high){
            int mid = low+(high-low)/2;
            if(function(position,m,mid)){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return high;
        
    }
};