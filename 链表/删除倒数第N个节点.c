/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* arr[31];
    struct ListNode* cur = head;
    int len = 0;

    while (cur != NULL) {
        arr[len] = cur;
        cur = cur->next;
        len++;
    }

    int moveloc = len - n;

    // 删除头节点
    if (moveloc == 0) {
        struct ListNode* newHead = head->next;
        free(head);
        return newHead;
    }

    // 删除尾节点
    if (moveloc == len - 1) {
        arr[moveloc - 1]->next = NULL;
        free(arr[moveloc]);
        return head;
    }

    // 删除中间节点
    arr[moveloc - 1]->next = arr[moveloc + 1];
    free(arr[moveloc]);

    return head;
}