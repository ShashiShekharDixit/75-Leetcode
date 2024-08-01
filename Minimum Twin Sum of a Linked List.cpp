class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* prev = NULL;
        while(head != NULL){
            ListNode* temp = head -> next;
            head -> next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        if(head -> next -> next == NULL) {
            return head -> val + head -> next -> val;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            prev = slow;
            slow = slow -> next;
        }
        prev -> next = NULL;
        slow = reverse(slow);
        int m = -1;
        while(slow != NULL){
            m = max(m, slow -> val + head -> val);
            head = head -> next;
            slow = slow -> next;
        }
        return m;
    }
};