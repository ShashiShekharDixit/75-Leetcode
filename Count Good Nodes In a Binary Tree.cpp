class Solution {
public:
    int ans = 0;
    void fun(TreeNode* root, int m) {
        if(root == NULL)
        return;
        if(root -> val >= m) {
            ans++;
        }
        m = max(root -> val, m);
        fun(root -> left, m);
        fun(root -> right, m);
    }
    int goodNodes(TreeNode* root) {
        fun(root, INT_MIN);
        return ans;
    }
};