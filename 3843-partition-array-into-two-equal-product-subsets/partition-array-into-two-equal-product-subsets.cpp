class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        __int128 product =1;
        for(int i=0;i<n;i++){
            product*=nums[i];

        }
        __int128 prod_subset =(__int128)target*target;
        if(prod_subset==product){
            return 1;
        }
        else{return 0;}


        
    }
};