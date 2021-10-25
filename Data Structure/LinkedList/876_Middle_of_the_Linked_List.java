/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode node = head;
        int len = 0;
        while(node != null){
            len++;
            node = node.next;
        }
        ListNode c = head;
        int mid = (int)Math.ceil(len/2);
        for(int i = 0; i<mid; i++){
            c = c.next;
        }
        return c;
        
        
//         ListNode s = head;
//         ListNode f = head;
        
//         while( f != null && f.next != null){
//             s = s.next;
//             f = f.next.next;
            
//         }
//         return s;
    }
}