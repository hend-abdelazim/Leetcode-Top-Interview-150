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
13    ListNode* rotateRight(ListNode* head, int k) {
14        if(head == nullptr) return nullptr;
15
16        // 1. Count linked list length
17        int len = 0;
18        ListNode *curr = head;
19        while(curr) {
20            len++;
21            curr = curr->next;
22        }
23
24        // 2. Update k, to handle k > len
25        k = k % len;
26        if (k == 0) {
27            return head;
28        }
29
30        // 3. Find tail node
31        ListNode *tail = head;
32        while(tail->next) {
33            tail = tail->next;
34        }
35
36        // 4. Jump to (len-k) position which is the "new head" node
37        ListNode *prev = nullptr;
38        curr = head; // reset the current ptr
39        for(int i = 0; i < (len-k); i++) {
40            prev = curr;
41            curr = curr->next;
42        }
43        // now curr is the new head and prev is the new tail
44        // 5. Disconnect to create two lists then merge them
45        prev->next = nullptr; // new tail
46        tail->next = head;
47
48        return curr; // new head
49    }
50};