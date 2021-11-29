/*
Problem Description
Given a singly linked list A and an integer B, reverse the nodes of the list B at a time and return modified linked list.

Problem Constraints

1 <= |A| <= 103

B always divides A

Input Format

The first argument of input contains a pointer to the head of the linked list.

The second arugment of input contains the integer, B.

Output Format

Return a pointer to the head of the modified linked list.

Example Input

Input 1:

 A = [1, 2, 3, 4, 5, 6]
 B = 2
Input 2:

 A = [1, 2, 3, 4, 5, 6]
 B = 3

Example Output

Output 1: [2, 1, 4, 3, 6, 5]
Output 2: [3, 2, 1, 6, 5, 4]

Example Explanation

Explanation 1:

 For the first example, the list can be reversed in groups of 2.
    [[1, 2], [3, 4], [5, 6]]
 After reversing the K-linked list
    [[2, 1], [4, 3], [6, 5]]
Explanation 2:

 For the second example, the list can be reversed in groups of 3.
    [[1, 2, 3], [4, 5, 6]]
 After reversing the K-linked list
    [[3, 2, 1], [6, 5, 4]]
*/ 
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(A==NULL || B==1){
        return A;
    }        
    ListNode* dummy=new ListNode(0);
    dummy->next=A;
    
    ListNode* curr=dummy;
    ListNode* nex=dummy;
    ListNode* prev=dummy;
    
    int count=0;
    while(curr->next!=NULL){
        curr=curr->next;
        count+=1;
    }
    
    while(count>=B){
        curr=prev->next;
        nex=curr->next;
        for(int i=1;i<B;i++){
            curr->next=nex->next;
            nex->next=prev->next;
            prev->next=nex;
            nex=curr->next;
        }
        prev=curr;
        count-=B;
    }
    return dummy->next;
}
// Given Sol.
ListNode * reverse(ListNode * A) {
    if (!A -> next)
        return A;
    ListNode * next = A -> next;
    A -> next = NULL;
    ListNode * reversed = reverse(next);
    next -> next = A;
    return reversed;
}

ListNode * Solution::reverseList(ListNode * A, int K) {
    ListNode * reversedFirst = A;
    for (int i = 1; i < K; i += 1) {
        reversedFirst = reversedFirst -> next;
    }
    ListNode * prev = new ListNode(0);
    ListNode * first;
    prev -> next = A;
    ListNode * last = prev;
    while (last -> next) {
        for (int i = 1; i <= K; i += 1) {
            last = last -> next;
        }
        first = prev -> next;
        prev -> next = NULL;
        ListNode * next = last -> next;
        last -> next = NULL;
        reverse(first);
        prev -> next = last;
        first -> next = next;
        prev = last = first;
    }
    return reversedFirst;
}
