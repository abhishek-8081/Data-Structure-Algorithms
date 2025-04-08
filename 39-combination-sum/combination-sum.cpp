class Solution {


public:

void func(vector<int>&candidates,int i,int sum,vector<int>temp,vector<vector<int>>&ans){
    if(sum ==0){
        ans.push_back(temp);
        return;
    }
    if(sum<0 || i>=candidates.size()){
        return;
    }
    func(candidates,i+1,sum,temp,ans);
    temp.push_back(candidates[i]);
    func(candidates,i,sum-candidates[i],temp,ans);
    temp.pop_back();

}


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        func(candidates,0,target,v,ans);
        return ans ;
        
    }
};