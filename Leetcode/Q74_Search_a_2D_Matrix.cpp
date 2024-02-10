# include <iostream>
# include <vector>
# include <math.h>
using namespace std;

/* Leetcode Q74: Search a 2D Matrix */
/* You are given an m x n integer matrix matrix with the following two properties:
    * Each row is sorted in non-decreasing order.
    * The first integer of each row is greater than the last integer of the previous row.
    Given an integer target, return true if target is in matrix or false otherwise.
    You must write a solution in O(log(m * n)) time complexity.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // First check if target is less than the first element or larger than the last element of the matrix
        // If so, then it's impossible that the target exists in the matrix
        if (target < matrix[0][0] || target > matrix[rows-1][cols-1]) {
            return false;
        }

        int tar_row = binarySearchRow(matrix, cols, 0, rows-1, target);
        return tar_row == -1? false: binarySearchCol(matrix[tar_row], 0, cols-1, target);
    }

    int binarySearchRow(vector<vector<int>>& matrix, int cols, int begin, int end, int target) {
        if (begin == end) {
            // Check if target is larger than the last element of (end-1)th row but less than the first element of (end)th row, or
            // if target is larger than the last element of (end)th row but less than the first element of (end+1)th row
            // If so, then target does not exist in the matrix
            return (target < matrix[end][0] || target > matrix[end][cols-1])? -1: end;
        }

        int mid = floor((begin + end) / 2);
        if (target >= matrix[mid][0]) {
            if (target <= matrix[mid][cols-1]) {
                return mid;
            }
            else {
                mid++;
                return binarySearchRow(matrix, cols, mid, end, target);
            }
        }
        else {
            if (mid == begin) {
                // For begin == end-1 -> mid == begin
                // We have checked that target is larger than the last element of (begin-1)th row
                // If target is less than (begin) the first element, then it does not exist in the matrix
                return -1;
            }
            mid--;
            return binarySearchRow(matrix, cols, begin, mid, target);
        }
    }

    bool binarySearchCol(vector<int>& vec, int begin, int end, int target) {
        if ((end - begin) <= 1) {
            return (target != vec[begin] && target != vec[end])? false: true;
        }

        int mid = floor((begin + end) / 2);

        if (target == vec[mid]) {
            return true;
        }
        else if (target < vec[mid]) {
            //mid--;
            return binarySearchCol(vec, begin, mid, target);
        }
        else {
            //mid++;
            return binarySearchCol(vec, mid, end, target);
        }
    }
};


int main() {
    vector<vector<int>> matrix1{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    vector<vector<int>> matrix2{{1, 2, 4, 4}, {22, 23, 23, 24}, {25, 27, 35, 40}};
    vector<vector<int>> matrix3{{1}, {3}, {4}};

    Solution *solution;
    bool result1 = solution -> searchMatrix(matrix1, 3);
    cout << result1 << endl;
    bool result2 = solution -> searchMatrix(matrix2, 8);
    cout << result2 << endl;
    bool result3 = solution -> searchMatrix(matrix3, 2);
    cout << result3 << endl;
}