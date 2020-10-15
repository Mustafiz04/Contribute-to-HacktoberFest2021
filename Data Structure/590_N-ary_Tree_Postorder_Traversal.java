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
    public List<Integer> postorder(Node root) {
        Stack<Node> st = new Stack<>();
        LinkedList<Integer> l = new LinkedList<>();
        
        if( root == null ){
            return l;
        }
        st.add(root);
        while( !st.isEmpty() ){
            Node curr = st.pop();
            l.addFirst( curr.val );
            for( Node i : curr.children ){
                st.add( i );
            }
        }
        return l;
    }
}