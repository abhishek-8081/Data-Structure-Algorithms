class Solution {
    private:
    int f(int i,int j,int n, vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(i==n-1){
            return matrix[n-1][j];
        }
        if(dp[i][j]!=1e9) return dp[i][j];
        int down = matrix[i][j]+f(i+1,j,n,matrix,dp);
        int rd=matrix[i][j]+f(i+1,j+1,n,matrix,dp);
        return dp[i][j]=min(down,rd);


    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        return f(0,0,n,triangle,dp);

    }
};