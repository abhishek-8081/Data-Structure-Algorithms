class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        int curr =0,minVal=0,maxVal=0;
        for(int i=0;i<n;i++){
            curr= curr+differences[i];
            minVal = min(curr,minVal);
            maxVal=max(maxVal,curr);
            if(((upper-maxVal)-(lower-minVal)+1)<=0)
            return 0;

        }

        return (upper-maxVal)-(lower-minVal)+1;
        
    }
};