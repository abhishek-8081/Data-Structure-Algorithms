class Solution {
public:

void func(int i, vector<int>&v,vector<vector<int>>&ans,vector<int>&nums){
    if(i==nums.size()){
        ans.push_back(v);
        return;
    }
    v.push_back(nums[i]);
    func(i+1,v,ans,nums);
    v.pop_back();
    for(int j=i+1;j<nums.size();j++){
        if(nums[j]!=nums[i]){
            func(j,v,ans,nums);
            return;
        }
    }

    // Adding this bcz in case of example like 1 2 2 2 the return will not happen and we have to add it to the ansso we will call the recursion on base case 
    func(nums.size(), v, ans, nums);

}
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>v;
        func(0,v,ans,nums);
        return ans;
    }
};



