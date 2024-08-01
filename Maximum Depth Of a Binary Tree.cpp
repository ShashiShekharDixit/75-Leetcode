class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        int x = maxDepth(root -> left);
        int y = maxDepth(root -> right);
        int maxi = 1 + max(x, y);
        return maxi;
    }
};