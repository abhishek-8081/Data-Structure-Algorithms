class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        map<int, int> mp;
        int sum = 0, repeated = -1, missing = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[grid[i][j]]++;
                sum += grid[i][j];
            }
        }

        int totalSum = (n * n * (n * n + 1)) / 2;  

        
        for (auto it : mp) {
            if (it.second == 2) {  
                repeated = it.first;
                break;
            }
        }

       
        missing = totalSum - (sum - repeated);

        return {repeated, missing};
    }
};
