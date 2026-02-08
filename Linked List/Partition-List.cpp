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
12private:
13    ListNode *leftListHead, *leftListTail; // to store values < x
14    ListNode* rightListHead, *rightListTail; // to store values >= x
15    // add values < x to the left list
16    void addToLeftList(int val) {
17        ListNode *newNode = new ListNode(val);
18        if(leftListHead == nullptr) {
19            leftListHead = leftListTail = newNode;
20        }
21        else {
22            leftListTail->next = newNode;
23            leftListTail = newNode;
24        }
25    }
26    // add values >= x to the right list
27    void addToRightList(int val) {
28        ListNode *newNode = new ListNode(val);
29        if(rightListHead == nullptr) {
30            rightListHead = rightListTail = newNode;
31        }
32        else {
33            rightListTail->next = newNode;
34            rightListTail = newNode;
35        }
36    }
37public:
38    ListNode* partition(ListNode* head, int x) {
39        if(head == nullptr) return nullptr;
40
41        // set all list pointers to null
42        leftListHead = nullptr, leftListTail = nullptr,
43        rightListHead = nullptr, rightListTail = nullptr;
44
45        ListNode *curr = head;
46        while(curr != nullptr) {
47            if(curr->val < x) addToLeftList(curr->val);
48            else addToRightList(curr->val);
49            curr = curr->next;
50        }
51        // if one of the two lists are empty
52        if(leftListHead == nullptr) return rightListHead;
53        if(rightListHead == nullptr) return leftListHead;
54
55        // connect left and right lists
56        leftListTail->next = rightListHead;
57        return leftListHead;
58    }
59};