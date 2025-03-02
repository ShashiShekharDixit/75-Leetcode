#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int ans;

    void solve(TreeNode* root, bool flag, int cnt) {
        if (!root) return;
        ans = max(ans, cnt);
        if (flag) {
            solve(root->left, !flag, cnt + 1);
            solve(root->right, true, 1);
        } else {
            solve(root->right, !flag, cnt + 1);
            solve(root->left, false, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        ans = 0;
        solve(root->left, false, 1);
        solve(root->right, true, 1);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(1);
    root->right->left->right = new TreeNode(1);
    root->right->left->right->left = new TreeNode(1);
    root->right->right->right = new TreeNode(1);
    root->right->right->right->right = new TreeNode(1);

    Solution solution;
    int result = solution.longestZigZag(root);
    cout << "Longest ZigZag Path Length: " << result << endl;

    return 0;
}
