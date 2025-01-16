class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int x= nums1.size();
        int y = nums2.size();

        int m =0,n=0;

        if(x%2!=0){
            for(int i=0;i<y;i++){
                m=m^nums2[i];

            }
        }
        if(y%2!=0){
            for(int i=0;i<x;i++){
                n=n^nums1[i];
            }
        }
        return m^n;
        
    }
};