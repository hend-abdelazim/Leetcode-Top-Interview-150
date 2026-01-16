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
13    ListNode* removeNthFromEnd(ListNode* head, int n) {
14        // create a dummy node that points to the head pointer to handle edge cases
15        ListNode *dummy = new ListNode(-1);
16        dummy->next = head;
17
18        // use fast and slow pointer to determine at which node you'll remove
19        // fast pointer if ahead by n steps
20        ListNode *firstPtr = dummy;
21        ListNode *secondPtr = dummy;
22
23        // move second pointer n steps ahead
24        for(int i = 0; i < n; i++) {
25            secondPtr = secondPtr->next;
26        }
27
28        // now move both pointers until the second pointer is null
29        while(secondPtr->next != NULL) {
30            firstPtr = firstPtr->next;
31            secondPtr = secondPtr->next;
32        }
33        firstPtr->next = firstPtr->next->next;
34        return dummy->next;
35    }
36};