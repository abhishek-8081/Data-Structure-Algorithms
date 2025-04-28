class Solution {
public:
    int mySqrt(int x) {
        int start =1,end=x/2;
        if(x==1){
            return 1;
        
        }
        long long int mid ;
        while(start<=end){
            mid =(start+end)/2;
            if(mid*mid==x||(mid*mid<x && (mid+1)*(mid+1)>x))
            return mid;
            else if(mid*mid<x){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return 0;

        
    }
};