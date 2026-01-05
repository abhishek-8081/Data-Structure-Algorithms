class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int long long sum =0;
        int mini = INT_MAX;
        int neg =0;
        for(auto & row:matrix){
            for(int val:row){
                sum+=abs(val);
                if(val<0){
                    neg++;
                }
                mini = min(mini,abs(val));

            }
        }
        if((neg%2)!=0){
            sum-=(2*mini);
        }
        return sum;

        
    }
};