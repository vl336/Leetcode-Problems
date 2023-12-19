#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//https://leetcode.com/problems/add-two-numbers/
//19.12.23 - Vladislav Ershov

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int* vec = malloc(3*sizeof (int));
    int vecSize = 3;
    int offset = 0;
    bool nxtIncrease = false;
    while((l1 != NULL || l2 != NULL) || nxtIncrease) {
        if(offset+1 == vecSize)
        {
            vecSize *= 3;
            vec = realloc(vec, vecSize*sizeof (int));
        }
        vec[offset] = 0;
        
        if(l1 != NULL)
            vec[offset] += l1->val;
        if(l2 != NULL)
            vec[offset] += l2->val;
        
        if(nxtIncrease) {
            vec[offset] += 1;
            nxtIncrease = false;
        }
        if(vec[offset] >= 10) {
            nxtIncrease = true;
            vec[offset] = vec[offset] % 10; 
        }
        
        offset++;
        if(l1 != NULL)
            l1 = l1->next;
        if(l2 != NULL)
            l2 = l2->next;
    }
    struct ListNode* ret = malloc((offset) * sizeof (struct ListNode));
    struct ListNode* prev = 0;
    for (int i = offset-1; i >= 0; i--) {
        ret[i].val = vec[i];
        ret[i].next = prev;
        prev = &ret[i]; 
    }
    free(vec);
    return ret;
}

int main() {
    struct ListNode n1_5, n2_5;
    n1_5.val = 1; n1_5.next = &n2_5;
    n2_5.val = 8; n2_5.next = NULL;

    struct ListNode n1_6;
    n1_6.val = 0; n1_6.next = NULL;
    struct ListNode* tc1 = addTwoNumbers(&n1_5, &n1_6);
    
    struct ListNode n1, n2, n3;
    n1.val = 2; n1.next = &n2;
    n2.val = 4; n2.next = &n3;
    n3.val = 3; n3.next = NULL;

    struct ListNode n1_2, n2_2, n3_2;
    n1_2.val = 5; n1_2.next = &n2_2;
    n2_2.val = 6; n2_2.next = &n3_2;
    n3_2.val = 4; n3_2.next = NULL;
    struct ListNode* tc2 = addTwoNumbers(&n1, &n1_2);

    struct ListNode n1_3, n2_3, n3_3,
            n4_3, n5_3, n6_3, n7_3;   
    
    n1_3.val = 9; n1_3.next = &n2_3;
    n2_3.val = 9; n2_3.next = &n3_3;
    n3_3.val = 9; n3_3.next = &n4_3;
    n4_3.val = 9; n4_3.next = &n5_3;
    n5_3.val = 9; n5_3.next = &n6_3;
    n6_3.val = 9; n6_3.next = &n7_3;
    n7_3.val = 9; n7_3.next = NULL;

    struct ListNode n1_4, n2_4, n3_4, n4_4;
    
    n1_4.val = 9; n1_4.next = &n2_4;
    n2_4.val = 9; n2_4.next = &n3_4;
    n3_4.val = 9; n3_4.next = &n4_4;
    n4_4.val = 9; n4_4.next = NULL;

    struct ListNode* tc3 = addTwoNumbers(&n1_3, &n1_4);
    return 0;
}
