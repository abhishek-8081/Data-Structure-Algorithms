class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt =0;
        while(true){
            
            set<int>unique(nums.begin(),nums.end());
            int x = unique.size();
            int y= nums.size();
            if(x==y){
                break;
            }
            
            if(y<4){
                nums.clear();
            }
                
            
            else{
                nums.erase(nums.begin(),nums.begin()+3);
            }
            cnt++;
        }
        return cnt ;
        
    }
};