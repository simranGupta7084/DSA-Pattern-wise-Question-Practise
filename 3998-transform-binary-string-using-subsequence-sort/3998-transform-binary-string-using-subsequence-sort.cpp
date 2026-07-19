class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();
        vector<int> preS(n+1,0);
        int o = 0;
        for(int i = 0;i<n;i++){
            o+=(s[i]=='1');
            preS[i+1] = o;
        }
        vector<bool> ans;

        for(string t: strs){
            int fixedOnes = 0,q = 0;
            for(char c: t){
                if(c == '1') fixedOnes++;
                else if (c=='?') q++;

            }
            int need = o-fixedOnes;
            if(need<0 || need >q){
                ans.push_back(false);
                continue;
            }
            for(int i = n-1;i>=0;i--){
                if(t[i] == '?'){
                    if(need>0){
                        t[i] = '1';
                        need--;
                    }else{
                        t[i]='0';
                    }
                }
            }
            bool ok = true;
            int preT = 0;
            for(int i = 0;i<n;i++){
                if(t[i]=='1') preT++;
                if(preT > preS[i+1]){
                    ok = false;
                    break;
                }
            }
            ans.push_back(ok);
        }
        return ans;
        
    }
};