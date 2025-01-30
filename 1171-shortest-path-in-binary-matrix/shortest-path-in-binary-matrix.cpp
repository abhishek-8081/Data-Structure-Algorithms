class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>&A) {
        int n= A.size();
        queue<pair<int,pair<int,int>>>q;
        int X= n-1;
        int Y= n-1;

        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[0][0]=0;
        q.push({1,{0,0}});
        
        int dr[]= {-1,0,1,0,1,1,-1,-1};
        int dc[]= {0,1,0,-1,1,-1,-1,1};
        
        if(A[0][0]==1||A[X][Y]==1){
            return -1;
        }
        
        if(X==0 && Y==0){
            return 1;
        }
        
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            
            
            for(int i=0;i<8;i++){
                int nrow = r+dr[i];
                int ncol = c+dc[i];
                
                if(nrow>=0 && nrow<n && ncol<n && ncol>=0 && A[nrow][ncol]==0 && dis+1<dist[nrow][ncol]){
                    dist[nrow][ncol]=dis+1;
                    if(nrow==X && ncol == Y){
                        return dis+1;
                    }
                    q.push({dis+1,{nrow,ncol}});
                }
            }
        }
        
        return -1;
       
    }
        
        
    
};