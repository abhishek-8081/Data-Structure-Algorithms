class Solution {
public:
    int climbStairs(int n) {
        vector<int>v(46);
        v[0]=0;
        v[1]=1;
        v[2]=2;
        for(int i=3;i<46;i++){
            v[i]=v[i-1]+v[i-2];
        }

        return v[n];
        
    }
};