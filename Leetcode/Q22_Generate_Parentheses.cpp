#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Leetcode Q22: Generate Parentheses */
/* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
   Example: Input: n = 3
            Output: ["((()))","(()())","(())()","()(())","()()()"]
   1 <= n <= 8
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // We can use DP method to avoid repeated computations.
        // We will use a 9x8 matrix, where y-axis means the number of left parentheses "(" yet to be used, 
        // and x-axis means the number of right parentheses ")" yet to be used.
        // Each grid in the matrix stores all combinations of remaining left and right parentheses,
        // For example, the grid in matrix (1, 2) stores all combinations of 1 left parenthesis and 2 right parentheses: ()) and )().
        // The grid (2, 2) stores all combinations of 2 "("s and 2 ")"s, which are composed of "(" plus combinations of 1 "(" and 2 ")"s, 
        // which relies on grid (1, 2). This is the core concept of DP. Counting every subsequent grid will rely on previous grids which store 
        // subsets of combinations.
        // The number of remaining "("s <= the number of remaining ")"s
        // and "("s >= 0
        //     ")"s > 0    (I's impossible that no ")" remains but some "("s still exist)
        // The following is our matrix. We won't use X areas.
        /*   1  2  3  4  5  6  7  8
          0    
          1  
          2  X  
          3  X  X  
          4  X  X  X  
          5  X  X  X  X
          6  X  X  X  X  X
          7  X  X  X  X  X  X
          8  X  X  X  X  X  X  X   | 
        */
        vector<string> mat[9][8];
        mat[0][0].push_back(")");
        for (int i=1; i<n+1; i++) {
            for (int j=0; j<i+1; j++) {
                if (j == 0) {
                    // If there are only ")"s left
                    if (i >= 2) {
                        mat[j][i-1].push_back(mat[j][i-2][0]+")");
                    }
                    else {  // i == 1
                        // This is an initial grid: mat[0][0]
                        continue;
                    }
                }
                else {
                    // The current grid relies on previous grids
                    // "(" + combinations of j-1 "("s and i ")"s
                    for (auto item: mat[j-1][i-1]) {
                        mat[j][i-1].push_back("("+item);
                    }
                    // ")" + combinations of j "("s and i-1 ")"s
                    // This only happens when current "("s < ")"s and there are more than 2 ")"s
                    if (i >= 2 && j >= 1 && j < i) {
                        for (auto item: mat[j][i-2]) {
                            mat[j][i-1].push_back(")"+item);
                        }       
                    }
                }
            }
        }
        return mat[n][n-1];
    }
};

int main(){
    Solution s;
    vector<string> result = s.generateParenthesis(4);
    for (auto item: result) {
        cout << item << "  " << endl;
    }
}