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
11 
12// The solution iteratively adds corresponding digits of two linked lists representing numbers in reverse order,
13// handling carry-over at each step. It creates a new linked list for the result,
14// node by node, until both input lists and any remaining carry are processed.
15class Solution {
16public:
17    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
18        int sum, carry, digit;
19        ListNode *head = new ListNode();
20        sum = l1->val + l2->val;
21        carry = sum / 10; // save the carry for next addition
22        digit = sum % 10;
23        head->val = digit;
24        l1 = l1->next;
25        l2 = l2->next;
26        ListNode *ans = head; // saving the head of the list as a copy
27
28        while(l1 || l2) {
29            // if one list is longer than another
30            if(!l1) sum = l2->val;
31            else if(!l2) sum = l1->val;
32            else sum = l1->val + l2->val;
33            ListNode *newNode = new ListNode();
34            if(sum + carry <= 9) {
35                newNode->val = sum + carry;
36                head->next = newNode;
37            }
38            else { // if sum + carry >= 10
39                digit = (sum + carry) % 10;
40                newNode->val = digit;
41                head->next = newNode;
42            }
43            if(l1) l1 = l1->next;
44            if(l2) l2 = l2->next;
45            head = head->next;
46            carry = (sum + carry) / 10;
47        }
48        if(carry) {
49            ListNode *lastDigit = new ListNode();
50            lastDigit->val = carry;
51            head->next = lastDigit;
52        }
53
54        return ans;
55    }
56};
57