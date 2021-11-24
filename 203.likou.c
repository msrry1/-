/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    if(head == NULL)
    {
        return NULL;
    }
    while(head -> val == val)
    {
        if(head -> next == NULL)
            return NULL;
        head = head -> next;
    }
    struct ListNode * p = NULL;
    struct ListNode * q = head;
    while(q != NULL)
    {
        if(q -> val == val)
        {
            if(q -> next == NULL)
            {   
                p -> next =NULL;
                break;
            }
            p -> next =q -> next;
            q = p -> next;
        }
        else
        {
            p = q;
            q = q -> next;
        }
    }
    return head;
}