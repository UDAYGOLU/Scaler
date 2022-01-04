// recursive Solution
public class Solution {
    public ListNode swapPairs(ListNode A) {

        if(A==null || A.next==null){
            return A;
        }
        ListNode temp=A.next;
        A.next=swapPairs(temp.next);
        temp.next=A;
        return temp;
    }
}
//fast
public class Solution {
    public ListNode swapPairs(ListNode A) {
        //fastest
        ListNode head=A;
        ListNode curr=A;
        while(curr!=null && curr.next!=null){
            int temp=curr.val;
            curr.val=curr.next.val;
            curr.next.val=temp;
            curr=curr.next.next;
        }
        return head;
    }
}

