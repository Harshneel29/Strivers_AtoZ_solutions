/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int> *node){
    return !node->left && !node->right;
}
void addleaves(TreeNode<int> *node, vector<int> &ans){
    if(isLeaf(node)){
        ans.push_back(node ->data);
        return;
    }

    if(node -> left) addleaves(node->left,ans);
    if(node -> right) addleaves(node->right,ans);


}

void addleft(TreeNode<int> *node, vector<int> &ans){
    TreeNode<int>* cur = node -> left;
    while(cur){

        if(!isLeaf(cur)){
            ans.push_back(cur -> data);
        }

        if(cur ->left) cur = cur -> left;
        else cur = cur -> right;

    }

}
void addright(TreeNode<int> *node, vector<int> &ans){
    TreeNode<int> *cur = node -> right;
    vector<int> temp;
    while(cur){

        if(!isLeaf(cur)){
            temp.push_back(cur ->data);
        }

        if(cur ->right) cur = cur -> right;
        else cur = cur -> left;

    }
    for(int i = temp.size() - 1; i>=0; i--){
        ans.push_back(temp[i]);
    }

}


vector<int> traverseBoundary(TreeNode<int> *root)
{
	vector<int> ans;
    if(!root) return ans;
    if(!isLeaf(root)) ans.push_back(root -> data);
    addleft(root, ans);
    addleaves(root, ans);
    addright(root, ans);
    return ans;
}
