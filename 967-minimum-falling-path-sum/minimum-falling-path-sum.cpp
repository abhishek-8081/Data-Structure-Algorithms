class Solution {
public:
//Space Optimized Code
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m = matrix[0].size();
        vector<int>prev(m,0),curr(m,0);
        // vector<vector<int>>dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            prev[j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up = matrix[i][j]+prev[j];
                int ld= matrix[i][j];
                if(j-1>=0)ld+=prev[j-1];
                else ld+=1e9;
                int rd = matrix[i][j];
                if(j+1<m)rd+=prev[j+1];
                else rd+=1e9;
                curr[j]= min(up,min(ld,rd));
            }
            prev = curr;
        }
        int mini = INT_MAX;
        for(int i=0;i<m;i++){
            mini = min(mini,prev[i]);
        }
        return mini;

    }
};