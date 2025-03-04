class Solution {
    private:
    bool check(int power,int n){
        if(n==0) return true;
    
    if (pow(3, power) > n) return false;

    bool add = check(power+1,n-pow(3,power));

    bool skip = check(power+1,n);
    return add||skip;
}
public:
    bool checkPowersOfThree(int n) {
        return check(0,n);
        
    }
};