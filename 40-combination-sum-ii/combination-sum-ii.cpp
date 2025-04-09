class Solution {
public:

void func(int i,int sum,vector<vector<int>>&ans,vector<int>&v,vector<int>& candidates){
    if(sum==0){
        ans.push_back(v);
        return;
    }
    if(sum<0 || i>=candidates.size()){
        return;
    }
    v.push_back(candidates[i]);
    func(i+1,sum-candidates[i],ans,v,candidates);
    v.pop_back();
    for(int j=i+1;j<candidates.size();j++){
        if(candidates[j]!=candidates[i]){
            func(j,sum,ans,v,candidates);
            break;
            
        }
    }


}


    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        sort(candidates.begin(),candidates.end());
        func(0,target,ans,v,candidates);
        return ans;


        
    }
};