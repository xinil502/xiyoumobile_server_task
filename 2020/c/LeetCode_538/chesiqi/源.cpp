int sum;
void dfs(struct TreeNode* root) {
    //��ʵ���Ǹ�������������������Ӷ���������������ʼ�ӣ��ӵ������Ͱ����ӵ�ֵ���������
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