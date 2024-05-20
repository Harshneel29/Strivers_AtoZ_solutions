/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where 'N' is the number of nodes in the tree.
*/

// Use answer to store traversal of nodes.
vector<int> answer;

void inOrder(TreeNode *node) {

    // Base case.
    if (node == NULL) {
        return;
    }

    // Visit left subtree.
    inOrder(node->left);

    // Add data of node to answer.
    answer.push_back(node->data);

    // Visit right subtree.
    inOrder(node->right);
}

vector<int> getInOrderTraversal(TreeNode *root) {

    // Clear contents of answer before every test case.
    answer.clear();

    // Call inOrder function and store inOrder traversal in answer array.
    inOrder(root);

    // Return answer.
    return answer;

}


void preOrder(TreeNode *node) {

    // Base case.
    if (node == NULL) {
        return;
    }
    // Add data of node to answer.
    answer.push_back(node->data);

    // Visit left subtree.
    preOrder(node->left);

    // Visit right subtree.
    preOrder(node->right);
}

vector<int> getPreOrderTraversal(TreeNode *root) {

    // Clear contents of answer before every test case.
    answer.clear();

    // Call preOrder function and store preOrder traversal in answer array.
    preOrder(root);

    // Return answer.
    return answer;
}


void postOrder(TreeNode *node) {

    // Base case.
    if (node == NULL) {
        return;
    }

    // Visit left subtree.
    postOrder(node->left);

    // Visit right subtree.
    postOrder(node->right);

    // Add data of node to answer.
    answer.push_back(node->data);

}

vector<int> getPostOrderTraversal(TreeNode *root) {

    // Clear contents of answer before every test case.
    answer.clear();

    // Call postOrder function and store postOrder traversal in answer array.
    postOrder(root);

    // Return answer.
    return answer;
}

vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    vector<vector<int>> result(3);

    // Call function to get inOrder Traversal.
    result[0] = getInOrderTraversal(root);

    // Call function to get preOrder Traversal.
    result[1] = getPreOrderTraversal(root);

    // Call function to get postOrder Traversal.
    result[2] = getPostOrderTraversal(root);

    // Return all 3 tree traversals.
    return result;
}