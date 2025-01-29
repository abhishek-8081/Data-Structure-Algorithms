class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int cnt =0;
        for(int i=0;i<32;i++){
            int BitA=(a>>i)&1;
            int BitB=(b>>i)&1;
            int BitC=(c>>i)&1;

            if(BitC==1){
                if(BitA==0 && BitB==0){
                    cnt++;
                }
            }
            if(BitC==0){
                cnt+=(BitA+BitB);
            }

        }
       return cnt;


    }
};