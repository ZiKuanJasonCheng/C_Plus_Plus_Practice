# include <iostream>
using namespace std;

/* Leetcode 501: Find Mode in Binary Search Tree */
/* Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.
   If the tree has more than one mode, return them in any order.
   Assume a BST is defined as follows:
   The left subtree of a node contains only nodes with keys less than or equal to the node's key.
   The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
   Both the left and right subtrees must also be binary search trees.
*/

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        vector<int> findMode(TreeNode* root) {
        /* Reference: https://leetcode.com/problems/find-mode-in-binary-search-tree/solutions/4232856/99-87-video-walkthrough-optimal-o-1-space-solution/
           We traverse each node's left child, reset the tree/subtree's root, and move the child's right subtree to be the root's new right subtree.
           The iteration continues until the node's left subtree is empty, so now we are sure that current node is the smallest. We can traverse the rest of the 
           nodes from the right subtree to get the mode(s).
        */
        vector<int> v_final;
        
        int count_mode = 0;
        int cur_val = 0;
        int cur_count = 0;
        TreeNode *cur_node = root;
        
        while (cur_node) {
            if (cur_node->left != nullptr) {
                TreeNode *traverse = cur_node->left;
                while (traverse->right) {
                    traverse = traverse->right;
                }
                traverse->right = cur_node;

                // Set cur_node to be its left child
                TreeNode *tmp = cur_node->left;
                cur_node->left = NULL;
                cur_node = tmp;
            }
            else {
                if (cur_node->val != cur_val) {
                    cur_val = cur_node->val;
                    cur_count = 1;
                }
                else {
                    cur_count++;
                    
                }

                if (cur_count > count_mode) {
                    // Remove all elements in vector, and push cur_val into it
                    v_final.clear();
                    v_final.push_back(cur_val);
                    count_mode = cur_count;
                }
                else if (cur_count == count_mode) {
                    v_final.push_back(cur_val);
                }

                cur_node = cur_node->right;
            }
        }
        return v_final;
    }
};

int main() {
    TreeNode *tn1 = new TreeNode(1, new TreeNode(nullptr, new TreeNode(2, new TreeNode(2, nullptr))));
    TreeNode *tn2 = new TreeNode(0);

    Solution *solution;
    vector<int> result1 = solution -> findMode(ln1);
    cout << result1 << endl;
    vector<int> result2 = solution -> findMode(ln2);
    cout << result2 << endl;
}