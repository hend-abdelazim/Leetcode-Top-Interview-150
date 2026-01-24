1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* deleteDuplicates(ListNode* head) {
14        ListNode *dummy = new ListNode(0);
15        dummy->next = head;
16        ListNode *prev = dummy;
17
18        while(head != NULL) {
19            if(head->next != NULL && head->val == head->next->val) {
20                while(head->next != NULL && head->val == head->next->val) {
21                    head = head->next;
22                }
23                prev->next = head->next;
24            }
25            else {
26                prev = prev->next;
27            }
28            head = head->next;
29        }
30        return dummy->next;
31    }
32};