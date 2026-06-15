struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur = dummy;
    int carry = 0;

    dummy->next = NULL;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int x = 0;
        int y = 0;
        int sum;
        struct ListNode* node;

        if (l1 != NULL) {
            x = l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            y = l2->val;
            l2 = l2->next;
        }

        sum = x + y + carry;
        carry = sum / 10;

        node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = NULL;

        cur->next = node;
        cur = cur->next;
    }

    return dummy->next;
}