/*
Problem Description

Given a singly linked list A

 A: A0 → A1 → … → An-1 → An 
reorder it to:

 A0 → An → A1 → An-1 → A2 → An-2 → … 
You must do this in-place without altering the nodes' values.



Problem Constraints

1 <= |A| <= 106



Input Format

The first and the only argument of input contains a pointer to the head of the linked list A.



Output Format

Return a pointer to the head of the modified linked list.



Example Input

Input 1:

 A = [1, 2, 3, 4, 5] 
Input 2:

 A = [1, 2, 3, 4] 


Example Output

Output 1:

 [1, 5, 2, 4, 3] 
Output 2:

 [1, 4, 2, 3] 


Example Explanation

Explanation 1:

 The array will be arranged to [A0, An, A1, An-1, A2].
Explanation 2:

 The array will be arranged to [A0, An, A1, An-1, A2]. */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode* reverse(ListNode* mid)
{
    if(!mid || !mid->next)
        return mid;
    ListNode *curr, *next, *prev;
    prev = mid; //didn't understand this part; should be NULL but that doesn't works.
    curr = mid->next;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    mid->next = curr;
    return prev;
}

ListNode* merge(ListNode* l1, ListNode* l2)
{
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    ListNode* head = l1;
    l1 = l1->next;
    bool alteringListFlag = true;
    ListNode* p = head;
    while(l1 && l2)
    {
        if(!alteringListFlag)
        {
            p->next = l1;
            l1 = l1->next;
        }
        else
        {
            p->next = l2;
            l2 = l2->next;
        }
        alteringListFlag = !alteringListFlag;
        p = p->next;
    }
    
    if(l1)
        p->next = l1;
    else
        p->next = l2;
    return head;
}
ListNode* Solution::reorderList(ListNode* A) {
     if(!A || !A->next || !A->next->next)
        return A;
    ListNode *p, *q;
    p = q = A;
    while (q->next && q->next->next)
    {
        p = p->next;
        q = q->next->next;
    }
    ListNode* mid = p->next;
    p->next = NULL;
    
    ListNode* secondHalfPointer = reverse(mid);
    return A = merge(A, secondHalfPointer);
    
}
//given sol
ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    ListNode * head = l1; // head of the list to return
    l1 = l1 -> next;
    ListNode * p = head; // pointer to form new list
    // A boolean to track which list we need to extract from. 
    // We alternate between first and second list. 
    bool curListNum = true;
    while (l1 && l2) {
        if (curListNum == false) {
            p -> next = l1;
            l1 = l1 -> next;
        } else {
            p -> next = l2;
            l2 = l2 -> next;
        }
        p = p -> next;
        curListNum = !curListNum;
    }
    // add the rest of the tail, done!
    if (l1) {
        p -> next = l1;
    } else {
        p -> next = l2;
    }
    return head;
}

ListNode * reverseLinkedList(ListNode * head) {
    if (head -> next == NULL) return head;
    ListNode * cur = head, * nextNode = head -> next, * tmp;
    while (nextNode != NULL) {
        tmp = nextNode -> next;
        nextNode -> next = cur;
        cur = nextNode;
        nextNode = tmp;
    }
    head -> next = nextNode;
    return cur;
}

ListNode * Solution::reorderList(ListNode * head) {
    int sz = 0;
    ListNode * tmp = head;
    while (tmp) {
        sz++;
        tmp = tmp -> next;
    }
    assert(sz <= 1e6);
    if (head == NULL || head -> next == NULL || head -> next -> next == NULL)
        return head;
    //find the middle of the list, and split into two lists.    
    ListNode * slow = head, * fast = head;
    while (slow != NULL && fast != NULL && fast -> next != NULL && fast -> next -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    ListNode * mid = slow -> next;
    slow -> next = NULL;
    //reverse from the middle to the end
    ListNode * secondHalfReversed = reverseLinkedList(mid);
    //merge these two list
    return head = mergeTwoLists(head, secondHalfReversed);
}
