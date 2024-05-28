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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map <int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode* ,pair<int,int>>> todo;
        todo.push({root,{0,0}});

        while(!todo.empty()){
            auto current = todo.front();
            todo.pop();
            TreeNode* temp = current.first;

            int col = current.second.first;
            int level = current.second.second;

            nodes[col][level].insert(temp -> val);

            if(temp -> left){
                todo.push({temp -> left,{col-1,level+1}});
            }

            if(temp -> right){
                todo.push({temp -> right,{col + 1, level + 1}});
            }

        }

        vector<vector<int>> ans;
        for(auto p : nodes){
            vector<int> inner;
            for(auto q : p.second){
                inner.insert(inner.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(inner);
        }

        return ans;

    }
};