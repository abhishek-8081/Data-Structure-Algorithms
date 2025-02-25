class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int MOD=1e9+7;
        vector<int>pre(n,0);
        pre[0]= arr[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+arr[i];
        }
        
        int odd=0,even=1,cnt=0;
        for(int i=0;i<n;i++){
            if(pre[i]%2==0){
                cnt=(cnt+odd)%MOD;
                even++;
            }
            else{
                cnt=(cnt+even)%MOD;
                odd++;
            }
        }
        return cnt;
    }
};