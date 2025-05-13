int MOD=1e9+7;
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        // map<char,int>mp;
        vector<int>mp(26,0);
        for(int i=0;i<s.length();i++){
            mp[s[i]-'a']++;
        }
        for(int i=0;i<t;i++){
            // map<char,int>temp;
            vector<int>temp(26,0);
            for(int i=0;i<26;i++){
                char ch = i+'a';
                int freq=mp[i];
                if(ch!='z'){

                    temp[ch+1-'a']=(temp[ch+1-'a']+freq)%MOD;
                }
                else{
                    temp[0]=(temp[0]+freq)%MOD;
                    temp[1]=(temp[1]+freq)%MOD;
                }
            }
            mp =temp;
        }
        
    int sum = 0;
    for (int i=0;i<26;i++) {
        sum = (sum+mp[i])%MOD;
    }
    return sum;
        
    }
};