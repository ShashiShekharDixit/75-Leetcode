#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* prev = NULL;
        while (head != NULL) {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        if (head->next->next == NULL) {
            return head->val + head->next->val;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = NULL;
        slow = reverse(slow);
        int m = -1;
        while (slow != NULL) {
            m = max(m, slow->val + head->val);
            head = head->next;
            slow = slow->next;
        }
        return m;
    }
};

void insert(ListNode*& head, int val) {
    if (!head) {
        head = new ListNode(val);
        return;
    }
    ListNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
}

void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution solution;
    ListNode* head = NULL;
    insert(head, 4);
    insert(head, 2);
    insert(head, 2);
    insert(head, 3);

    cout << "Maximum Twin Sum: " << solution.pairSum(head) << endl;

    freeList(head);
    return 0;
}
