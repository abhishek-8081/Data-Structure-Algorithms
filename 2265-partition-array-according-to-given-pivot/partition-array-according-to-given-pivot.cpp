class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int cnt =0;
        vector<int>a;
        vector<int>b;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                a.push_back(nums[i]);
            }
            else if(nums[i]>pivot){
                b.push_back(nums[i]);
            }
            else{
                cnt++;
            }
        }

        vector<int>prefix(cnt,pivot);
        a.insert(a.end(),prefix.begin(),prefix.end());
        a.insert(a.end(),b.begin(),b.end());
        return a;
        
    }
};