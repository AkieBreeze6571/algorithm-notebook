/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode* tail = &dummy;

    while (list1 != NULL && list2 != NULL) {
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->next = NULL;

        if (list1->val <= list2->val) {
            node->val = list1->val;
            list1 = list1->next;
        } else {
            node->val = list2->val;
            list2 = list2->next;
        }

        tail->next = node;
        tail = tail->next;
    }

    while (list1 != NULL) {
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = list1->val;
        node->next = NULL;

        tail->next = node;
        tail = tail->next;

        list1 = list1->next;
    }

    while (list2 != NULL) {
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = list2->val;
        node->next = NULL;

        tail->next = node;
        tail = tail->next;

        list2 = list2->next;
    }

    return dummy.next;
}