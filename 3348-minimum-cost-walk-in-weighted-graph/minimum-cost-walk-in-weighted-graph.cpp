class Solution {
    private:
    int find(int node,vector<int>&parent){
        if(parent[node]== -1){
            return node;
        }
        return parent[node]= find(parent[node],parent);
    }

    void Union(int node1,int node2,vector<int>&parent,vector<int> &depth){
        int root1 = find(node1,parent);
        int root2= find(node2,parent);


        if(root1==root2) return ;//already in the same Component 
        if(depth[root1]<depth[root2]){
            swap(root1,root2);
        }
        parent[root2]=root1;
        if(depth[root1]==depth[root2]) depth[root1]++;

    }
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int>parent(n,-1);
        vector<int>depth(n,0);
        vector<int>componentCost(n,INT_MAX);
        for(auto & edge:edges){
            Union(edge[0],edge[1],parent,depth);
        }

        for(auto & edge:edges){
            int root = find(edge[0],parent);
            componentCost[root]&=edge[2];
        }

        vector<int>ans;
        for(auto &q:query){
            int start = q[0];
            int end = q[1];
            if(find(start,parent)!=find(end,parent)){
                ans.push_back(-1);
            }
            else{
                int root = find(start,parent);
                ans.push_back(componentCost[root]);
            }
        }
        return ans;

        
    }
};