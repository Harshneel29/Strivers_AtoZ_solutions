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
    int findsum(TreeNode* node, int &maxi){
        if(!node) return 0;

        int lh = max(0,findsum(node -> left,maxi));
        int rh = max(0,findsum(node -> right,maxi));
        int value = node -> val;

        maxi = max(maxi, lh+rh+value);

        return max(lh , rh) + value;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findsum(root,maxi);
        return maxi;
        
    }
};