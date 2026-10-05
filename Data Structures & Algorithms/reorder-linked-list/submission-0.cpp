/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;

        if(head == nullptr && head -> next == nullptr)
        {
            return;
        }
        
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = second;

        while(curr != nullptr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        second = prev;
        
        ListNode* first = head;
        while(second != NULL)
        {
            ListNode* First_next = first->next;
            ListNode* Second_next = second->next;

            first->next = second;
            second->next = First_next;

            first = First_next;
            second = Second_next;
        }

    }
};
