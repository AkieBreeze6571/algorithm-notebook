struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* N1 = head;
    int i = 0;
    int did = 0;

    // 这里是“节点指针数组”，不是“二级指针数组”
    struct ListNode* nodes[5001];

    // pre 应该保存上一组翻转后的尾节点，所以必须是节点指针
    struct ListNode* pre = NULL;

    while (N1 != NULL) {
        nodes[i] = N1;
        i++;
        N1 = N1->next;
    }

    if (i < k || k == 1) {
        return head;
    }

    // 第一组翻转后，原来的第 k 个节点会成为新头
    head = nodes[k - 1];

    while (i - did >= k) {
        // 当前这一组：
        // nodes[did] ... nodes[did + k - 1]

        // 上一组的尾，连接到当前组翻转后的新头
        if (pre != NULL) {
            pre->next = nodes[did + k - 1];
        }

        // 当前组原本的第一个节点，翻转后会成为尾节点
        // 它要连向下一组的第一个节点（或 NULL）
        nodes[did]->next = nodes[did + k - 1]->next;

        // 组内反转
        for (int j = 1; j < k; j++) {
            nodes[did + j]->next = nodes[did + j - 1];
        }

        // 当前组原本的第一个节点，现在已经是翻转后的尾节点
        pre = nodes[did];

        did += k;
    }

    return head;
}