
class Solution {
public:
    int listSize(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;

        int count = listSize(head);
        k %= count;
        if (k == 0) return head;

        ListNode* newTail = head;
        for (int i = 1; i < count - k; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        ListNode* temp = newHead;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = head;
        return newHead;
    }
};