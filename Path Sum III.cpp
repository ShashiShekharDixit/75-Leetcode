#include <iostream>
#include <unordered_map>

using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    unordered_map<long long, long long> mp;
    int ans = 0;

public:
    void getAns(TreeNode* root, int targetSum, long long current_sum) {
        if (root == NULL) {
            return;
        }
        long long val = current_sum + root->val;
        if (val == targetSum) {
            ans += 1;
        }
        if (mp.find(val - targetSum) != mp.end() && mp[val - targetSum]) {
            ans += mp[val - targetSum];
        }
        mp[val] += 1;
        getAns(root->left, targetSum, current_sum + root->val);
        getAns(root->right, targetSum, current_sum + root->val);
        mp[val] -= 1;
    }

    int pathSum(TreeNode* root, int targetSum) {
        long long current_sum = 0;
        getAns(root, targetSum, current_sum);
        return ans;
    }
};

TreeNode* createTree() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);
    return root;
}

int main() {
    TreeNode* root = createTree();
    Solution sol;
    int targetSum = 8;

    cout << "Number of paths with sum " << targetSum << ": " << sol.pathSum(root, targetSum) << endl;

    return 0;
}
