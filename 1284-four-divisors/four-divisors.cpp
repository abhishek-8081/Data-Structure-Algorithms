class Solution{
public:
    int sumFourDivisors(vector<int>& nums){
        int ans=0;
        for(int k=0;k<nums.size();k++){
            int x=nums[k],c=0,s=0;
            int i=1;
            while(i*i<=x){
                if(x%i==0){
                    int j=x/i;
                    c++;s+=i;
                    if(i!=j){c++;s+=j;}
                    if(c>4)break;
                }
                i++;
            }
            if(c==4)ans+=s;
        }
        return ans;
    }
};
