#define ll long long 
#define pll pair<ll,ll>
int MOD= 1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //Creating Adjacency List for Graph Also it's a Non Directed Graph 
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        // Priority Queue for Each time getting the Smallest Distance 
        priority_queue<pair<ll,ll>,vector<pll>,greater<pair<ll,ll>>>pq;
        //Ways Array to find the number of ways by which we can reach a node and with the smallest distance possible
        vector<ll>dist(n,1e12),ways(n,0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});//{dist,node};
        while(!pq.empty()){
            ll dis = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                ll adjnode = it.first;
                ll edw=it.second;

                //First time we get the smallest Distance 
                if(dis+edw<dist[adjnode]){
                    dist[adjnode]=dis+edw;
                    pq.push({dis+edw,adjnode});
                    ways[adjnode]=ways[node]%MOD;
                }

                //If distance obtained is equal to the Previous Smallest Distance then we need only to increase the value of Ways 


                else if(dis+edw==dist[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%MOD;

                }
        }
        }

        return ways[n-1]%MOD;
       


        
    }

};