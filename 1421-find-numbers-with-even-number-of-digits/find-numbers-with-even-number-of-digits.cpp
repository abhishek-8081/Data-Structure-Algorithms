class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans =0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            int x =0;
            while(nums[i]>0){
                nums[i]/=10;
                x++;
            }
            if(x%2==0){
                ans++;
            }
        }
        return ans;
        
    }
};