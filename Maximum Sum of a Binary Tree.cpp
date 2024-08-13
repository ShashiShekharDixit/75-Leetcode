class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<vector<int>>result;
        if(root==NULL){
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>level;
            for(int i=0;i<size;i++){
                TreeNode *current=q.front();
                q.pop();
                if(current->left!=NULL){
                    q.push(current->left);
                }
                if(current->right!=NULL){
                    q.push(current->right);
                }
                level.push_back(current->val);
            }
            result.push_back(level);
        }
        int sum = INT_MIN;
        int n = result.size();
        int index = 1;
        for(int i = 0; i < n; i++){
            if(sum < accumulate(result[i].begin(), result[i].end(), 0)){
                index = i + 1;
                sum = accumulate(result[i].begin(), result[i].end(), 0);
            }
        }
        return index;
    }
};