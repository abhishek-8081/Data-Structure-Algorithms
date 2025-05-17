class Solution {
public:
    int maxFreqSum(string s) {
        map<char,int>mp;
        int n=s.length();
        for(int i=0;i<n;i++){
            mp[s[i]]++;

        }
        int x=0,y=0;
        for(auto &it:mp){
            if(it.first=='a'||it.first=='e'||it.first=='i'||it.first=='o'||it.first=='u'){
                x= max(x,it.second);
            }
            else{
                y= max(y,it.second);
            }
        }
        return x+y;
        
    }
};