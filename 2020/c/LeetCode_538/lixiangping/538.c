int sum;
void dfs(struct TreeNode *root)
{
	if(root!=NULL)
    {
     dfs(root->right);
    root->val = sum + root->val;
    sum = root->val;
    dfs(root->left);
    }
    
}
struct TreeNode* convertBST(struct TreeNode* root){
    sum=0;
   dfs(root);
    return root;
}
