class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int p = words[i].size();
            for(int j=i+1;j<n;j++){
                int q = words[j].size();
                if(q>=p && words[j].substr(0,p)== words[i] && words[j].substr(q-p)==words[i]){
                    cnt++;
                }
            }
        }
        
        return cnt ;

    }
};