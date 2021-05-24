int lastvalue = 0;
void dfs(struct TreeNode *root)
{
    if (!root)
    {
        return;
    }
    dfs(root->right);
    root->val = lastvalue + root->val;
    lastvalue = root->val;

    dfs(root->left);

    return;
}

struct TreeNode *convertBST(struct TreeNode *root)
{
    dfs(root);
    lastvalue = 0;
    return root;
}