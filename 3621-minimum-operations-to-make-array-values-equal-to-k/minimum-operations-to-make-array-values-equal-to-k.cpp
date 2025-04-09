class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        auto minElement = *min_element(nums.begin(), nums.end());
        if(k>minElement){
            return -1;

        }
        set<int>st;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>k)
            st.insert(nums[i]);
            
        }

        return st.size();
        
    }
};