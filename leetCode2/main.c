/* main.c */
#include <stdlib.h>
#include <stdio.h>

/* 
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Constraints:
--The number of nodes in each linked list is in the range [1, 100].
--0 <= Node.val <= 9
--It is guaranteed that the list represents a number that does not have leading zeros.

*/



struct ListNode { // if next node is NULL then empty 
    int val;
    struct ListNode *next;
};


struct ListNode* createNumber(int val)
{
    struct ListNode* head, *tail;
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    tail = head;
    head->val = val%10;
    val = val/10;

    while(val > 0)
    {
        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        tail = tail->next;
        tail->val = val%10;
        tail->next = NULL;
        val = val/10;
    }
    return head;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *t1, *t2, *a;
    int val1, val2, i = 1 ,answer = 0;
    t1 = l1;
    t2 = l2;

    while((t1 != NULL)||(t2 != NULL)) // while neither is null
    {
        if(t1 != NULL){
            val1 = t1->val;
            t1 = t1->next;
        }
        else
        {
            val1 = 0;
        }
        if(t2 != NULL){
            val2 = t2->val;
            t2 = t2->next;
        }
        else
        {
            val2 = 0;
        }
        
        answer = i*val1 + i*val2 + answer;
        i = i*10;
    }
    return createNumber(answer);

}

void printlist(struct ListNode *head)
{
    struct ListNode *temp = head;

    while(temp!=NULL)
    {
        printf("%i", temp->val);
        temp = temp->next;
    }
    printf("\n");
}



void main(void)
{
    struct ListNode* t1, *t2, *a1;
    int test1 = 911, test2 =712;


    t1 = createNumber(test1);
    t2 = createNumber(test2); 
    printf("First Number: %i\n", test1); 
    printf("List 1(reverse order):");
    printlist(t1);
    printf("Second Number: %i\n", test2); 
    printf("List 2(reverse order):");
    printlist(t2);
    a1 = addTwoNumbers(t1,t2);
    printf("This is the linked list answer( in reverse order ):");
    printlist(a1);
    printf("This is the real answer: %i", (test1+test2));

}