/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int add=0;
    public TreeNode convertBST(TreeNode root) {
        change(root);
        return root;
    }
    public void change(TreeNode root){
        if(root!=null){
            change(root.right);
            root.val=add+root.val;
            add=root.val;
            change(root.left);
        }
        return;
    }
}