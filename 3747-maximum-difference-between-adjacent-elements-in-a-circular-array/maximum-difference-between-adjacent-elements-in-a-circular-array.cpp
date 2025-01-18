class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {

        int ans =0;
        for(int i=0;i+1<nums.size();i++){
            ans = max(ans,abs(nums[i]-nums[i+1]));
        }

        return max(ans,abs(nums[0]-nums[nums.size()-1]));
        
    }
};