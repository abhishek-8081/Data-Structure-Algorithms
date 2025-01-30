class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>maxDiff(n,vector<int>(m,1e9));
 priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        maxDiff[0][0]=0;
        pq.push({0,{0,0}});
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};

        while(!pq.empty()){
            auto p= pq.top();
            int diff = p.first;
            int r = p.second.first;
            int c = p.second.second;
            pq.pop();
            if(r==n-1 && c==m-1){
                return diff;
            }
            for(int i=0;i<4;i++){
                int nrow = r+dr[i];
                int ncol = c+dc[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int currdiff = abs(heights[nrow][ncol]-heights[r][c]);
                    if(max(currdiff,diff)<maxDiff[nrow][ncol]){
                        maxDiff[nrow][ncol]=max(currdiff,diff);
                        pq.push({max(currdiff,diff),{nrow,ncol}});
                    }
                }
            }


        }
        return -1;

        
        
    }
};