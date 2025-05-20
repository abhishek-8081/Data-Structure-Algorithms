class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>diff_arr(n+1,0);
        for(auto it:queries){
            diff_arr[it[0]]+=1;
            if(it[1]+1<n){
                diff_arr[it[1]+1]-=1;
            }
        }

        for(int i=1;i<=n;i++){
            diff_arr[i]+=diff_arr[i-1];
        }

        int flag =1;
        for(int i=0;i<n;i++){
            if(diff_arr[i]<nums[i]){
                flag=0;
            }
        }
        if(flag){
            return true;

        }
        else{
            return false;
        }
        
    }
};