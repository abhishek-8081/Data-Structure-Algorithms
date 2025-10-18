class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int cnt =0;
        int Prev=INT_MIN;
        for(int i=0;i<n;i++){
            int lowerBound = nums[i]-k;
            int upper = nums[i]+k;
            if(Prev<lowerBound){
                 Prev = lowerBound;
                cnt++;

            }
               
            else if(Prev<upper){
                Prev++;
                cnt++;
            }


        }
        return cnt;
        
    }
};