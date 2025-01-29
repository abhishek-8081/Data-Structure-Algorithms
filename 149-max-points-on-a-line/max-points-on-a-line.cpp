class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n= points.size();
        int cnt =0;
        if(n==1){
            return 1;

        }

        for(int i=0;i<n;i++){
            map<float,int>mp;
            int x1=points[i][0];
            int y1= points[i][1];
            for(int j=i+1;j<n;j++){
                int x2 = points[j][0];
                int y2 = points[j][1];

                if(x2-x1==0){
                    mp[INT_MAX]++; //When line is parallel to the Y-Axis and Slope is Infinite or not defined type 

                }
                else if(y2-y1==0){
                    mp[0]++; //When two points on the line are oparallel to the X-axis
                }
                else{
                    float slope = (float)(x2-x1)/(y2-y1);
                    mp[slope]++;
                }
            }

            for(auto &x:mp){
                cnt = max(cnt,x.second);
            }
        }

        return cnt+1;
        
    }
};