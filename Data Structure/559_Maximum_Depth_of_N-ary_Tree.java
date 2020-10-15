/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public int maxDepth(Node root) {
        int maxDepth = 0;
        if( root == null ){
            return maxDepth;
        }
        maxDepth = depthUtil( root, maxDepth + 1 );
        return maxDepth;
        
    }
    public int depthUtil( Node root, int h ){
        if( root.children.isEmpty()){
            return h;
        }
        int maxDepth = 0;
        for(Node n : root.children){
            maxDepth = Math.max( maxDepth, depthUtil( n, h+1 ) );
        }
        return maxDepth;
    }
}