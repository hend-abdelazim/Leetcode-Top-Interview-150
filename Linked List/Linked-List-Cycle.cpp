1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode(int x) : val(x), next(NULL) {}
7 * };
8 */
9
10/* Slow pointer moves one step at a time.
11Fast pointer moves two steps at a time.
12If the list has a loop, the fast pointer will eventually lap the slow pointer and they meet. */
13class Solution {
14public:
15    bool hasCycle(ListNode *head) {
16        if(head == nullptr)
17            return false;
18        ListNode *fastPtr = head;
19        ListNode *slowPtr = head;
20
21        while (fastPtr->next && fastPtr->next->next) {
22            slowPtr = slowPtr->next;
23            fastPtr = fastPtr->next->next;
24            if(slowPtr == fastPtr)
25                return true;
26        }
27        return false;
28    }
29};