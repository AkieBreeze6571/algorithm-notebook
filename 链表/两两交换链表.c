struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* N1 = head;
    struct ListNode* N2;
    struct ListNode* pre = NULL;
    int rehead = 0;

    if (N1 == NULL) {
        return head;
    }

    if (N1->next == NULL) {
        return head;
    }

    while (N1 != NULL) {
        if (N1->next != NULL) {
            N2 = N1->next;
        } else {
            return head;
        }

        if (pre == NULL) {
            N1->next = N2->next;
            N2->next = N1;

            pre = N1;
            N1 = N1->next;

            if (rehead == 0) {
                head = N2;
                rehead = 1;
            }
        } else {
            N1->next = N2->next;
            N2->next = N1;

            // 先让上一组尾节点接到这一组的新头
            pre->next = N2;

            // 再更新 pre：它现在应指向本组交换后的尾节点 N1
            pre = N1;

            // 进入下一组
            N1 = N1->next;
        }
    }

    return head;
}