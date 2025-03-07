class Solution {
    private:
    //Function to create Sieve untill the Upper Limit 
    vector<int>sieve(int upperlimit){
        vector<int>sieve(upperlimit+1,1);
        sieve[0]=0;
        sieve[1]=0;
        for(int i=2;i*i<=upperlimit;i++){
            if(sieve[i]==1){
                for(int num = i*i;num<=upperlimit;num+=i){
                    sieve[num]=0;
                }
            }
        }
        return sieve;

    }

public:
    vector<int> closestPrimes(int left, int right) {
        vector<int>sievearray = sieve(right);
        vector<int>prime;
        for(int i=left;i<=right;i++){
            if(sievearray[i]==1){
                prime.push_back(i);
            }
        }

        vector<int>ans(2,-1);
        if(prime.size()<2){
            return {-1,-1};
        }
        int mindiff=INT_MAX;
        for(int i=0;i<prime.size()-1;i++){
            if(prime[i+1]-prime[i]<mindiff){
                mindiff=prime[i+1]-prime[i];
                ans[0]=prime[i];
                ans[1]=prime[i+1];
            }
        }

        return ans ;


        
    }
};