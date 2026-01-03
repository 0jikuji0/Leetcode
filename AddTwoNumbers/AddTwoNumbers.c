/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {


    struct ListNode dummyHead = {0, NULL};
    struct ListNode* current = &dummyHead;
    int carry = 0, v1, v2, sum;    

    while (l1 || l2 || carry){
        v1 = l1 ? l1 -> val :0;
        v2 = l2 ? l2 -> val :0;
        sum = v1 + v2 + carry;

        current->next = malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = sum %10;
        current->next = NULL;
        carry = sum/10;
        
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    return dummyHead.next;
}