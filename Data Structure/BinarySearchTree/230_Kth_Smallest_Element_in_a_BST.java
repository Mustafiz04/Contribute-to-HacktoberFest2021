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
    public int kthSmallest(TreeNode root, int k) {
        Queue<TreeNode> q = new LinkedList<>();
        Queue<Integer> ele =  new PriorityQueue<>(Collections.reverseOrder());
        
        q.add(root);
        
        while( !q.isEmpty() ){
            TreeNode curr = q.poll();
            ele.add(curr.val);
            
            if( curr.left != null ){
                q.add(curr.left);
            }
            if( curr.right != null ){
                q.add(curr.right);
            }
            
            while( ele.size() > k ){
                ele.poll();
            }
        }
        
        return ele.poll();
    }
}