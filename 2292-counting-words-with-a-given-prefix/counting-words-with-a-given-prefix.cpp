class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int cnt =0;
        int m = pref.size();
        for(int i=0;i<n;i++){
            if(words[i].substr(0,m)==pref){
                cnt++;
            }
        }
        return cnt;
        
        
    }
};