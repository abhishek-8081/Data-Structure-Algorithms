class Solution {
    private:
    void fun(int row,vector<vector<string>>&ans,vector<string>&board,int n){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(poss(row,col,board,n)){
                board[row][col]='Q';
                fun(row+1,ans,board,n);
                board[row][col]='.';
            }
        }
    }
    bool poss(int row,int col,vector<string>&board,int n){
        int r=row,c=col;
        while(r>=0){
            if(board[r][col]=='Q'){
               return false;
            }
            r--;

        }
         r=row,c=col;
        while(r>=0 && c<n){
            if(board[r][c]=='Q'){
               return false;
            }
            r--;c++;

        }
        r=row,c=col;
        while(r>=0 && c>=0){
            if(board[r][c]=='Q'){
               return false;
            }
            r--;
            c--;
        }
        return true;
    }
public:
    vector<vector<string> > solveNQueens(int n) {
        //your code goes 
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        fun(0,ans,board,n);
        return ans;

    }
};