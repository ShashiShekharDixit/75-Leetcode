#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int ans = 0;
    void fun(TreeNode* root, int m) {
        if (root == NULL)
            return;
        if (root->val >= m) {
            ans++;
        }
        m = max(root->val, m);
        fun(root->left, m);
        fun(root->right, m);
    }
    int goodNodes(TreeNode* root) {
        fun(root, INT_MIN);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);
    
    Solution sol;
    cout << "Number of good nodes: " << sol.goodNodes(root) << endl;
    
    return 0;
}