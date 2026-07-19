class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        if(start == target) return true;

        int p1 = (start[0] + start[1]) % 2;
        int p2 = (target[0] + target[1]) % 2;

        return p1==p2;
        
    }
};