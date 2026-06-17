class Solution {
    ListNode* deleteAtPosition(ListNode* head, int pos) {
        if (head == NULL)
            return NULL;

        if (pos == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* prev = head;

        for (int i = 0; i < pos - 1 && prev->next != NULL; i++) {
            prev = prev->next;
        }

        if (prev->next != NULL) {
            ListNode* temp = prev->next;
            prev->next = temp->next;
            delete temp;
        }

        return head;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return NULL;

        int count = 0;
        ListNode* curr = head;

        while (curr != NULL) {
            count++;
            curr = curr->next;
        }

        int position = count - n;

        return deleteAtPosition(head, position);
    }
};
