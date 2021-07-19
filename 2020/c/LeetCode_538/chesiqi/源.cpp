int sum;
void dfs(struct TreeNode* root) {
    //其实就是个二叉树的中序遍历，从二叉树的右子树开始加，加到根结点就把所加的值赋给根结点
    if (root == NULL)return;
    else {
        dfs(root->right);
        sum += root->val;
        root->val = sum;
        dfs(root->left);
    }
}
struct TreeNode* convertBST(struct TreeNode* root) {
    sum = 0;
    dfs(root);
    return root;
}