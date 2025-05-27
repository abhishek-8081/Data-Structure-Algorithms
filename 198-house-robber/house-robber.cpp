class Solution {
    private:
     int maximumSum(vector<int>&nums){
        int n = nums.size();
        int prev = nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1)take+=prev2;
            int nottake= 0+prev;
            int curr = max(take,nottake);
            prev2=prev;
            prev= curr;
        }
        return prev;
    }
public:
    int rob(vector<int>& money) {
         int n = money.size();vector<int>temp1,temp2;
        if(n==1) return money[0];
        // for(int i=0;i<n;i++){
        //     if(i!=0)temp1.push_back(money[i]);
        //     if(i!=n-1)temp2.push_back(money[i]);
           

        // }
        
        return maximumSum(money);

        
    }
};

