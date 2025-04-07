class Solution {
    int t[201][20001];
    private:
    bool solve(vector<int>&nums , int index , int x){
        if(x==0){
            return true ;

        }
        if(index>=nums.size()){
            return false;
        }

        if(t[index][x]!=-1){
            return t[index][x];
        }

        bool take = false;
        if(x>=nums[index]){
            take = solve(nums,index+1,x-nums[index]);
            
        }
       bool not_take= solve(nums,index+1,x);

        return t[index][x]=take||not_take;


    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        memset(t,-1,sizeof(t));
        
            return solve(nums,0,sum/2);

        
       
        
    }
};