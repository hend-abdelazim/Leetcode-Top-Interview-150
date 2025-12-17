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
13    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
14        if(!list1) return list2;
15        if(!list2) return list1;
16
17        ListNode *head = list1;
18        if(list2->val < list1->val) {
19            head = list2;
20            list2 = list2->next;
21        } else {
22            list1 = list1->next;   // as it's already initialized to list1
23        }
24
25        ListNode* curr = head;
26        while(list1 && list2) {
27            if(list1->val < list2->val) {
28                curr->next = list1;
29                list1 = list1->next;
30            }
31            else {
32                curr->next = list2;
33                list2 = list2->next;
34            }
35            curr = curr->next;
36        }
37        // if list1 ended and list2 is not, take the remaining of list2 and vice vera
38        if(!list1) curr->next = list2; 
39        else curr->next = list1;
40        
41        return head;
42    }
43};