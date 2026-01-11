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
13    ListNode* reverseBetween(ListNode* head, int left, int right) {
14        if(!head || left == right) return head; // if list is empty
15
16        // dummy node pointing at the head of the list
17        ListNode *dummy = new ListNode();
18        dummy->next = head;
19
20        // Point at the node before the left pointer
21        ListNode *leftPre = dummy; // assign it to dummy initially
22        ListNode *currNode = head;
23
24        // move until reaching the pre left interval
25        for(int i = 0; i < left - 1; i++) {
26            leftPre = leftPre->next;
27            currNode = currNode->next;
28        }
29
30        // save the left node itself (for joining the pieces at the end)
31        ListNode *leftNode = currNode;
32        
33        ListNode *preNode = NULL;
34        // start reversing
35        for(int i = 0; i <= right-left; i++) {
36            ListNode *nextNode  = currNode->next;
37            currNode->next = preNode;
38            preNode = currNode;
39            currNode = nextNode;
40        }
41        
42        // join the pieces
43        leftPre->next = preNode;
44        leftNode->next = currNode;
45        
46        return dummy->next;
47    }
48};