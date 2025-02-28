#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            int n = queue.size();
            vector<int> values;
            for (int i = 0; i < n; ++i) {
                TreeNode* node = queue.front();
                queue.pop();
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
                values.push_back(node->val);
            }
            result.push_back(values.back());
        }
        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    
    Solution sol;
    vector<int> result = sol.rightSideView(root);
    
    cout << "Right Side View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
