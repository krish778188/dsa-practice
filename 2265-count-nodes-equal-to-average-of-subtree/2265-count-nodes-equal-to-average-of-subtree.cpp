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
    int ans = 0;
public:
    pair<int, int> avgN(TreeNode* root, int &ans) {
        if (!root) return {0, 0};
        auto left = avgN(root->left, ans);
        auto right = avgN(root->right, ans);
        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;
        if (sum / count == root->val) ans++;
        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        avgN(root, ans);
        return ans;
    }
};