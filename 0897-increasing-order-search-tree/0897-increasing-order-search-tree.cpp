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
    void inorder(TreeNode* root, TreeNode* &head, TreeNode* &temp) {
        if(!root) return;
        inorder(root->left, head, temp);
        TreeNode* rightChild = root->right;
        root->left = NULL;
        if(!head){
            head = root;
            temp = root;
        } 
        else {
            temp->right = root;
            temp = root;
        }
        inorder(rightChild, head, temp);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* head = NULL;
        TreeNode* temp = NULL;
        inorder(root, head, temp);
        if(temp) temp->right = NULL;
        return head;
    }
};