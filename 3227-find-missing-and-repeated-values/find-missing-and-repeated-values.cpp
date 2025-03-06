class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n = grid.size();

        // n=n*n;
        int sum=0;
        int x=-1,y=-1;
        long long sqsum=0;


        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val = grid[i][j];
                sum+=val;
                sqsum+=(val*val);
            }
        }
        n = n*n;
        
        int totalsum = n*(n+1)/2;
         long long totalsqsum = (1LL*n*(n+1)*(2*n+1))/6;
        int sumdiff= sum-totalsum;
        long long  sqsumdiff= sqsum- totalsqsum;
        long long  p= sqsumdiff / sumdiff;
         x= (p+sumdiff)/2;
         y= (p-x);

         return {x,y};





        


        
    }
};