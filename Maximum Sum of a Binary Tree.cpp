#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int maxSum = INT_MIN, level = 0, index = 1;
        
        while (!q.empty()) {
            int size = q.size();
            int sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode *current = q.front();
                q.pop();
                sum += current->val;
                if (current->left != NULL) {
                    q.push(current->left);
                }
                if (current->right != NULL) {
                    q.push(current->right);
                }
            }
            level++;
            if (sum > maxSum) {
                maxSum = sum;
                index = level;
            }
        }
        return index;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    Solution solution;
    int result = solution.maxLevelSum(root);
    cout << "Level with maximum sum: " << result << endl;

    return 0;
}
