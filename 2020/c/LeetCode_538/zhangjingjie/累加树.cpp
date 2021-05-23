//ÀÛ¼ÓÊ÷ 
int t=0;

struct TreeNode* convertBST(struct TreeNode* root){
    RO(root);
    t=0;
    return root;
}

void F(struct TreeNode* root){
    if(root!=NULL)
    root->val=root->val+t;
}

void  RO(struct TreeNode* root){
	if(root!=NULL){
		RO(root->right);
    	F(root);
        t=root->val;
		RO(root->left);
	}
}
