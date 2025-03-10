class Solution {
    private:
    bool isVowel(char &ch){
        return ch =='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        map<int,int>mp;
        vector<int>nextconst(n);
        int last=n;
        for(int i=n-1;i>=0;i--){
            nextconst[i]=last;
            if(!isVowel(word[i])){
                last = i;
            }
        }
        int i=0;
        int j=0;
        int cons=0;
        long long int cnt =0;
        while(j<n){
            char ch = word[j];
            if(isVowel(ch)){
                mp[ch]++;
            }
            else{
                cons++;
            }
            while(i<n && cons>k){
                char ch = word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch]==0) mp.erase(ch);
                }
                else cons--;
                i++;
            }
            while(i<n && mp.size()==5 && cons==k){
                int idx = nextconst[j];
                cnt+=(idx-j);
                char ch = word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch]==0) mp.erase(ch);
                    
                }
                else cons--;
                i++;
            }
            j++;
        }
        return cnt;



        
    }
};