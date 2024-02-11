#include <iostream>
#include <string>
using namespace std;

/* Leetcode Q21: Merge Two Sorted Lists */
/* You are given the heads of two sorted linked lists "list1" and "list2".
   Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
   Return the head of the merged linked list.
*/

struct ListNode {
      int val;
      ListNode *next;
      ListNode(): val(0), next(NULL) {}
      ListNode(int x): val(x), next(NULL) {}
      ListNode(int x, ListNode *next): val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        struct ListNode *myList = NULL;
        struct ListNode *start = NULL;
        while (list1 || list2) {
            int val_i;
            if (list1 && list2) {  // Both list1 and list2 are not null
                //cout << "list1->val:" << list1->val << "; list2->val:" << list2->val << endl;
                if (list2->val <= list1->val) {
                    val_i = list2->val;
                    list2 = list2->next;
                }
                else {
                    val_i = list1->val;
                    list1 = list1->next;
                }
            }
            else if (list1) {  // Only list1 is not null
                val_i = list1->val;
                list1 = list1->next;
            }
            else {  // Only list2 is not null
                val_i = list2->val;
                list2 = list2->next;
            }
            
            //cout << "val_i:" << val_i << endl;
            if (!myList) {
                myList = new ListNode(val_i);
                start = myList;
            }
            else {
                myList->next = new ListNode(val_i);
                myList = myList->next;
            }
        }
        //cout << "Before return, start: " << start << "; start->val:" << start->val << "; start->next:" << start->next << endl;
        return start;
    }
};

void printNodeVal(ListNode* result) {
    while (result) {
        cout << "result->val:" << result->val << endl;
        result = result->next;
    }
    cout << "----------" << endl;
}

int main(){
    // Case 1
    // Create list1: [1, 2, 4]
    ListNode *list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    // Create list2: [1, 3, 4]
    ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    Solution s;
    ListNode *result1 = s.mergeTwoLists(list1, list2);
    printNodeVal(result1);

    // Case 2
    // Create list3: []
    ListNode *list3 = NULL;
    // Create list4: [0]
    ListNode *list4 = new ListNode(0);

    ListNode *result2 = s.mergeTwoLists(list3, list4);
    printNodeVal(result2);

    // Case 3
    // Create list5: []
    ListNode *list5 = NULL;
    // Create list6: []
    ListNode *list6 = NULL;

    ListNode *result3 = s.mergeTwoLists(list5, list6);
    printNodeVal(result3);
}