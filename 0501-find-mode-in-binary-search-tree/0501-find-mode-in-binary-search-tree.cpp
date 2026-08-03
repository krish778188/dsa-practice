/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> m;
    int maxFreq = 0;
    vector<int> ans;
    void dfs(TreeNode* root) {
        if(root == NULL) return;
        m[root->val]++;
        if(m[root->val] == maxFreq) {
            ans.push_back(root->val);
        }
        else if(m[root->val] > maxFreq) {
            maxFreq = m[root->val];
            ans.clear();
            ans.push_back(root->val);
        }
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }
};