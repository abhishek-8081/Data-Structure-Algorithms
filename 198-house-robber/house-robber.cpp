class Solution {
    int solve(vector<int>&nums){
     int n = nums.size();
    vector<int>dp(n+3,0);
   
    // dp[n]=0;

    for(int i=n-1;i>=0;i--){
        int include = nums[i]+dp[i+2];
        int exclude = 0+dp[i+1];
        dp[i] =max(include,exclude);

    }
    return dp[0];

}
public:
    int rob(vector<int>& nums) {
        return solve(nums);
        
    }
};