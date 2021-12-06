/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *t = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *q = t;
    while(list1 != NULL && list2 != NULL)
    {
        if(list1->val <= list2->val)
        {
            q->next = list1;
            q = q->next;
            list1 = list1->next;
        }
        else
        {
            q->next = list2;
            q = q->next;
            list2 = list2->next;
        }
    }
    if(list1 == NULL)
    {
        q->next = list2;
    }
    if(list2 == NULL)
    {
        q->next = list1;
    }
    return t->next;
}
