/*Problem Description

Given a linked list A, remove the B-th node from the end of list and return its head.

For example, Given linked list: 1->2->3->4->5, and B = 2. After removing the second node from the end, the linked list becomes 1->2->3->5.

NOTE: If B is greater than the size of the list, remove the first node of the list.

NOTE: Try doing it using constant additional space.

Problem Constraints

1 <= |A| <= 106

Input Format

The first argument of input contains a pointer to the head of the linked list.

The second argument of input contains the integer B.

Output Format

Return the head of the linked list after deleting the B-th element from the end.

Example Input

Input 1:

A = [1, 2, 3, 4, 5]
B = 2
Input 2:

A = [1]
B = 1

Example Output

Output 1:[1, 2, 3, 5]

Output 2: [] 

Example Explanation

Explanation 1: In the first example, 4 is the second last element.
Explanation 2: In the second example, 1 is the first and the last element.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
       ListNode  *a, *b, *prev = 0;

    for (a = A; a && B; a = a->next) {
        B--;
    }

    for (b = A; a && b; a = a->next) {
        prev = b;
        b = b->next;
    }

    if (prev && b) {
        prev->next = b->next;
    } else {
        A = A->next;
    }

    return A;
}
//given sol
ListNode * Solution::removeNthFromEnd(ListNode * head, int n) {
    ListNode * t1 = head, * t2 = head;
    int sz = 0;
    while (t1) {
        t1 = t1 -> next;
        sz++;
    }
    if (n >= sz)
        head = head -> next;
    else {
        for (int i = 0; i < sz - n - 1; i++)
            t2 = t2 -> next;
        t2 -> next = t2 -> next -> next;
    }
    return head;
}
