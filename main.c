#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

//https://leetcode.com/problems/add-two-numbers/

struct ListNode {
    int val;
    struct ListNode *next;
};

void printArray(int* arr, int sz) {
    for (int i = 0; i < sz; i++) {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int* vec = malloc(3*sizeof (int));
    int vecSize = 3;
    int offset = 0;
    int fulfilled = 0;
    struct ListNode* current = l1;
    while(current != NULL) {
        if(offset+1 == vecSize) // offset -1
        {
            vecSize *= 3;
            vec = realloc(vec, vecSize*sizeof (int));
        }            
        vec[offset] = current->val;
        offset++;
        current = current->next;
    }
    
    fulfilled = offset;
    printArray(vec, fulfilled);
    current = l2; offset = 0;
    while(current != NULL) {
        int res = current->val + vec[offset];
        if(res >= 10) {
            if(offset == fulfilled-1)
            {
                vec[offset+1] = 1;
                fulfilled++;
            }
            else { 
                vec[offset+1] += 1;    
            }
            res = res % 10;
        }
        vec[offset] = res;
        offset++;
        current = current->next;
    }
    while(offset < fulfilled)
    {
        if(vec[offset] >= 10) {
            if(offset == fulfilled-1)
            {
                if(fulfilled <= vecSize) {
                    vec[offset + 1] = 1;
                    fulfilled++;
                }
            }
            else {
                vec[offset+1] += 1;
            }
            vec[offset] = vec[offset] % 10;
        }
        offset++;
    }
    printArray(vec, fulfilled);
    
    struct ListNode* ret = malloc((fulfilled) * sizeof (struct ListNode));
    struct ListNode* prev = 0;
    for (int i = fulfilled-1; i >= 0; i--) {
        ret[i].val = vec[i];
        ret[i].next = prev;
        prev = &ret[i]; 
    }
    return ret;
}

int main() {
    struct ListNode n1, n2, n3;
    n1.val = 2; n1.next = &n2;
    n2.val = 4; n2.next = &n3;
    n3.val = 3; n3.next = NULL;


    struct ListNode n1_2, n2_2, n3_2;
    n1_2.val = 5; n1_2.next = &n2_2;
    n2_2.val = 6; n2_2.next = &n3_2;
    n3_2.val = 4; n3_2.next = NULL;
    struct ListNode* a = addTwoNumbers(&n1, &n1_2);

    struct ListNode n1_3;
    struct ListNode n2_3;
    struct ListNode n3_3;
    struct ListNode n4_3;
    struct ListNode n5_3;
    struct ListNode n6_3;
    struct ListNode n7_3;   
    struct ListNode n1_4;
    struct ListNode n2_4;
    struct ListNode n3_4;
    struct ListNode n4_4;
    
    n1_3.val = 9; n1_3.next = &n2_3;
    n2_3.val = 9; n2_3.next = &n3_3;
    n3_3.val = 9; n3_3.next = &n4_3;
    n4_3.val = 9; n4_3.next = &n5_3;
    n5_3.val = 9; n5_3.next = &n6_3;
    n6_3.val = 9; n6_3.next = &n7_3;
    n7_3.val = 9; n7_3.next = NULL;
    
    n1_4.val = 9; n1_4.next = &n2_4;
    n2_4.val = 9; n2_4.next = &n3_4;
    n3_4.val = 9; n3_4.next = &n4_4;
    n4_4.val = 9; n4_4.next = NULL;

    struct ListNode* ab = addTwoNumbers(&n1_3, &n1_4);
    printf("8 9 9 9 0 0 0 1\n");
    return 0;
}
