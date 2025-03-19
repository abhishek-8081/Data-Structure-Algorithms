class Solution {
    private:
    bool flip(vector<int>&nums,int idx,int n){
        if(idx+2>=n) return false;
        for(int i=idx;i<n && i<=idx+2;i++){
            nums[i]^=1;

        }
        return true;
    }
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(flip(nums,i,n)==false){
                    return -1;
                }
                ans++;
            }
        }
        return ans;
        
    }
};