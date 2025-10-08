class Solution {
    private:
    bool check(string s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++,j--;
        }
        return true;
    }

    void dfs(int index, string s,vector<string>&path,vector<vector<string>>&res){
        int n = s.length();
        if(index==n){
            res.push_back(path);
            return;

        }
        for(int i=index;i<n;i++){
            if(check(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                dfs(i+1,s,path,res);
                path.pop_back();
            }
        }

    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>path;
        dfs(0,s,path,res);
        return res;
        
    }
};