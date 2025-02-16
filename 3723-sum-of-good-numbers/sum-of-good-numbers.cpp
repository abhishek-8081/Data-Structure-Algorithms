class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int n= nums.size();
        int sum = 0;


        for(int i=k;i<=n-1-k;i++){
            if(nums[i]>nums[i-k] && nums[i]>nums[i+k]){
                sum+=nums[i];
            }
        }

        for(int i=0;i<k;i++){
            if(nums[i]>nums[i+k]){
                sum+=nums[i];
            }
        }

        for(int i=n-k;i<n;i++){
            if(nums[i]>nums[i-k]){
                sum+=nums[i];
            }
        }

        return sum ;
        
    }
};