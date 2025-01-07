class Solution {
    private:
    vector<int>kmp(string s){
        vector<int>lps(s.size(),0);
        for(int i=1;i<lps.size();i++){
            int prev_index= lps[i-1];
            while(prev_index>0 && s[i]!=s[prev_index]){
                prev_index=lps[prev_index-1];
            }
            lps[i]=prev_index+(s[i]==s[prev_index]?1:0);
        }
        return lps;
        
    }

    //Here Previous Index denotes how much string is common or same at that point 
    //need to check when there is not a match .
public:
    string longestPrefix(string s) {
        vector<int>ans =kmp(s);
        return s.substr(0,ans.back());

        
        
        
        
    }
};