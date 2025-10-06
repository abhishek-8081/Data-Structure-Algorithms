class Solution {
public:
vector<vector<int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};

    int swimInWater(vector<vector<int>>& grid) {
        int n= grid.size();
        int low =0,high =n*n-1;
        while(low<high){
            int mid = low+(high-low)/2;
            vector<vector<int>>vis(n,vector<int>(n,0));
            if(DFS(mid,grid,n,0,0,vis)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
        
    }
    int DFS(int T,vector<vector<int>>&grid,int n,int i,int j,vector<vector<int>>&vis){
        if(i==n-1 && j==n-1){
            return true;
        }
        vis[i][j]= true;
        for(auto x: dir){
            int i_= i+x[0];
           int j_= j+x[1];
            if(i_>=0 && i_<n && j_<n && j_>=0 && !vis[i_][j_] && grid[i][j]<=T && grid[i_][j_]<=T){
                if(DFS(T,grid,n,i_,j_,vis)){
                    return true;
                }
            }
        }
        return false;
    }

};