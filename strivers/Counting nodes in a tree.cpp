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

    void counter(TreeNode* node, int &count){
        if(node == NULL) return;
        count++;
        counter(node -> left,count); 
        counter(node -> right,count); 
    }

    int countNodes(TreeNode* root) {
        int count = 0;
        counter(root , count);
        return count;
    }
};