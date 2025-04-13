long long mod=1e9+7;


class Solution {
public:

long long helper(long long a,long long b){
    if(b==1){
        return a%mod;

    }
    if(b==0){
        return 1;
    }

    long long temp = helper(a,b/2);
    temp=((temp%mod * temp%mod)%mod);
    if(b&1){
        temp*=a;
        temp%mod;
    }
    return temp;


}
    int countGoodNumbers(long long n) {
        long long even,odd;
        if(n&1){
             even = n/2+1;
         odd = n/2;
        }
        else{
             even =n/2;
           odd = n/2;
        }

        long long ans = ((helper(5,even)%mod)*(helper(4,odd)%mod)%mod);
        return ans ;

        
    }

};