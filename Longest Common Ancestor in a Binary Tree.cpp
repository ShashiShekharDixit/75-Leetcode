#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) {
            return root;
        }
        TreeNode* resL = lowestCommonAncestor(root->left, p, q);
        TreeNode* resR = lowestCommonAncestor(root->right, p, q);
        if (resL && resR) {
            return root;
        } else if (resL) {
            return resL;
        } else {
            return resR;
        }
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left;  
    TreeNode* q = root->right; 

    Solution solution;
    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);
    
    cout << "Lowest Common Ancestor: " << lca->val << endl;

    return 0;
}
