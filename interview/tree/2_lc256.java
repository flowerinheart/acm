

// Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

//简单就是说对于一个，右节点要么为空或者叶子同时必须有兄弟节点的树，将它上下反正，右叶节点变成左叶节点


public class Solution {
    /**
     * @param root: the root of binary tree
     * @return: new root
     */
     
     
    public TreeNode upsideDownBinaryTree(TreeNode root) {
        // write your code here
        
        if(root == null || root.left == null)
            return root;
        TreeNode res= upsideDownBinaryTree(root.left);
        root.left.left = root.right;
        root.left.right = root;
        root.left = root.right = null;
        return res;
    }
    

}