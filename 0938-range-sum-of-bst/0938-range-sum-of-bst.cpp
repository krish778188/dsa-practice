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
    int rangeSumBST(TreeNode* root, int low, int high) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(q.size() > 0) {
            TreeNode* temp = q.front();
            q.pop();
            if(temp && temp->val >= low && temp->val <= high) ans += temp->val;

            if(temp && temp->val >= low) q.push(temp->left);
            if(temp && temp->val <= high) q.push(temp->right);
        }
        return ans;
    }
};