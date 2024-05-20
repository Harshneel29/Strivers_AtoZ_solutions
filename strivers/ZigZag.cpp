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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        bool leftToright = true;

        queue<TreeNode*> myq;
        myq.push(root);

        while(!myq.empty()){
            int size = myq.size();
            vector<int> row(size);
            for(int i = 0; i < size; i++){
                TreeNode* node = myq.front();
                myq.pop();
                int index = leftToright? i : (size -1 -i);

                row[index] = node -> val;
                if(node -> left) myq.push(node -> left);
                if(node -> right) myq.push(node -> right);
            }
            leftToright = !leftToright;
            result.push_back(row);
        }
        return result;

    }
};