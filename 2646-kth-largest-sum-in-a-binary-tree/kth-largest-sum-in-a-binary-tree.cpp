/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // int ans =0;
        vector<long long>a;
        long long  level=0;
        // int mxlvl=0;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            level++;
            long long cnt=0;

            long long sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();
                cnt+=node->val;

                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }



            }
            a.push_back(cnt);
            // mxlvl=max(mxlvl,level);


        }
        sort(a.begin(),a.end(),greater<long long>());
        if (k > a.size()) return -1;

        else{
            return a[k-1];
        }

        
    }
};