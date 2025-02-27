class Solution {
public:
    bool isThree(int n) {
        // if(n==2){
        //     return false; 
        // }
        int cnt =0;
        for(int i=1;i<=n/2;i++){
            if(n%i==0){
                cnt++;
            }
        }
        if(cnt==2){
            return true;
        }
        else{
            return false;
        }
        
    }
};