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
private:
    void getLeafNode(TreeNode* root, vector<int> &temp){
        if(!root) return;
        if(!root->left && !root->right){
            temp.push_back(root->val);
        }
        if(root->left){
            getLeafNode(root->left, temp);
        }
        if(root->right){
            getLeafNode(root->right, temp);
        }
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1;
        vector<int> leaf2;
        getLeafNode(root1, leaf1);
        getLeafNode(root2, leaf2);
        if(leaf1.size()!=leaf2.size()) return false;
        for(int i=0;i<leaf1.size();i++){
            if(leaf1[i]!=leaf2[i]){
                return false;
            }
        }
        return true;
    }
};
