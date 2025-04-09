class Solution {
public:
void func(int sum,vector<int>&temp,vector<vector<int>>&ans,int k)
{
    if(sum==0 && temp.size()==k){
        ans.push_back(temp);
        return;

    }
    if(sum<0 || temp.size()>k)return ;
    int element = temp.empty()?1:temp.back()+1;

    for(int i=element;i<=9;i++){
        if(sum>=i){
            temp.push_back(i);
            func(sum-i,temp,ans,k);
            temp.pop_back();
            
        }
    }
}
    vector<vector<int> > combinationSum3(int k, int n) {
    	vector<vector<int>>ans;
        vector<int>temp;
        func(n,temp,ans,k);
        return ans ;
    }
};