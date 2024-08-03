class Solution {
public:
int ans;
    void solve(TreeNode* root,bool flag,int cnt){
        if(!root) return;
        ans=max(ans,cnt);
        if(flag){
             solve(root->left,!flag,cnt+1);
             solve(root->right,1,1);
        }else{
              solve(root->right,!flag,cnt+1);
             solve(root->left,0,1);

        }
    }
    int longestZigZag(TreeNode* root) {
        ans=0;
        solve(root->left,0,1);
        solve(root->right,1,1);
        return ans;
    }
};