class Solution {
public:
 vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
 typedef pair<int, pair<int, int>> P;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();
       
       vector<vector<int>>result(m,vector<int>(n,INT_MAX));
       priority_queue<P, vector<P>, greater<P>> pq; 
       result[0][0]=0;
       pq.push({0,{0,0}});
       while(!pq.empty()){
            int currTime = pq.top().first;
            auto cell     = pq.top().second;
            int i = cell.first;
            int j = cell.second;
            pq.pop();
            if(i == m-1 && j == n-1) {
                return currTime;
            }

            for(auto &dir:directions){
                int inext= i+dir[0];
                int jnext = j+dir[1];
                 if(inext >= 0 && inext < m && jnext >= 0 && jnext < n) {
                    int wait    = max(moveTime[inext][jnext] - currTime, 0);
                    int arrTime = currTime + wait + 1;

                    if(result[inext][jnext] > arrTime) {
                        result[inext][jnext] = arrTime;
                        pq.push({arrTime, {inext, jnext}});
                    }
                    
                }
            }
        }

        return -1;

    


            
       

        
    }
};