# include <iostream>
# include <vector>
# include <cmath>
using namespace std;

/* Leetcode Q33: Search in Rotated Sorted Array */
/* There is an integer array nums sorted in ascending order (with distinct values).
   Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) 
   such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
   For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
   Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
   You must write an algorithm with O(log n) runtime complexity.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int N = nums.size();
        int result = BST(nums, target, 0, N-1);
        cout << "result: " << result << endl;
        return result;
    }

    int BST(vector<int>& vec, int target, int start, int end) {
        cout << "BST(): start: " << start << ", end: " << end << endl;
        if (target == vec[start]) {
            return start;
        }
        else if (target == vec[end]) {
            return end;
        }
        else if (end - start <= 1) {
            return -1;
        }
        else if (target == vec[floor((start+end)/2)]) {
            return floor((start+end)/2);
        }
        else {
            if (vec[start] > vec[end]) {  // ex: 4, ..., 2
                if (target < vec[start]) {
                    if (target > vec[end]) {
                        return -1;
                    }
                    else {  // target < vec[end]  ex: target=1
                        if (target < vec[floor((start+end)/2)]) {
                            if (vec[floor((start+end)/2)] > vec[end]) {  // If value of middle point is larger than the rightmost value  ex: 4, ..., 7, ..., 2
                                // Search the right-half part of the sequence
                                return BST(vec, target, floor((start+end)/2)+1, end-1);
                            }
                            else {  // If value of middle point is larger than the rightmost value  ex: 4, ..., 1, ..., 2
                                // Search the left-half part of the sequence
                                return BST(vec, target, start+1, floor((start+end)/2)-1);
                            }
                        }
                        else {  // target > vec[floor((start+end)/2)]  ex: target=1 and sequence is 4, ..., 0, 1, ..., 2
                            // Search the right-half part of the sequence
                            return BST(vec, target, floor((start+end)/2)+1, end-1);
                        }
                    }
                }
                else {  // target > vec[start]  ex: target=6
                    if (target < vec[floor((start+end)/2)]) {
                        // Search the left-half part of the sequence
                        return BST(vec, target, start+1, floor((start+end)/2-1));
                    }
                    else {  // target > vec[floor((start+end)/2)]
                        if (vec[floor((start+end)/2)] > vec[end]) {  // If value of middle point is larger than the rightmost value  ex: 4, ..., 7, ..., 2
                            // Search the right-half part of the sequence
                            return BST(vec, target, floor((start+end)/2)+1, end-1);
                        }
                        else {  // If value of middle point is larger than the rightmost value  ex: 4, ..., 1, ..., 2
                            // Search the left-half part of the sequence
                            return BST(vec, target, start+1, floor((start+end)/2)-1);
                        }
                    }
                }
            }
            else {  // vec[start] < vec[end]  // ex: 4, ..., 15  The sequence is not rotated
                if (target > vec[start]) {
                    if (target > vec[end]) {
                        return -1;
                    }
                    else {
                        if (target < vec[floor((start+end)/2)]) {
                            // Search the left-half part of the sequence
                            return BST(vec, target, start+1, floor((start+end)/2)-1);
                        }
                        else {  // target > vec[floor((start+end)/2)]
                            // Search the right-half part of the sequence
                            return BST(vec, target, floor((start+end)/2)+1, end-1);
                        }
                    }
                }
                else {  // target < vec[start]
                    return -1;
                }
            }
        }
    }
};

int main() {
    vector<int> case1{4, 5, 6, 7, 0, 1, 2};
    vector<int> case2{7, 8, 2, 3, 5};
    vector<int> case3{1};
    vector<int> case4{3, 5, 9, 11, 14, 15, 17, 19};

    Solution *solution;
    solution -> search(case1, 0);
    solution -> search(case2, 3);
    solution -> search(case3, 2);
    solution -> search(case4, 9);
}