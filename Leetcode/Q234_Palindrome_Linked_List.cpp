# include <iostream>
using namespace std;

/* Leetcode Q234: Palindrome Linked List */
/* Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
*/

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
    public:
        static bool isPalindrome(ListNode* head) {
            ListNode *node = head;
            // Build up a reverse singly-linked list
            ListNode *r_node = NULL;
            ListNode *r_head = NULL;
            int i = 0;
            while (node->next != NULL) {
                // Let's do the task of reverse singly-linked list
                r_head = new ListNode(node->next->val);
                if (r_node == NULL) {
                    r_node = r_head;
                    r_node->next = new ListNode(node->val);
                }
                else {
                    r_head->next = r_node;
                    r_node = r_head;
                }

                // Let's move on to the next node
                node = node->next;
                i++;
            }
            
			if (i == 0) {
                return false;
            }
            
            // Let's compare two linked lists!
            node = head;
            r_node = r_head;
            for (int j=0; j<=(i+1)/2; j++) {
                if (node->val != r_node->val) {
                    return false;
                }
                else {
                    node = node->next;
                    r_node = r_node->next;
                }
            }
            return true;
        }
};

int main() {
    ListNode *ln1 = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
    ListNode *ln2 = new ListNode(1, new ListNode(2));
    ListNode *ln3 = new ListNode(2, new ListNode(3, new ListNode(5, new ListNode(3, new ListNode(2)))));

    bool result1 = Solution::isPalindrome(ln1);
    cout << result1 << endl;
    bool result2 = Solution::isPalindrome(ln2);
    cout << result2 << endl;
    bool result3 = Solution::isPalindrome(ln3);
    cout << result3 << endl;
}