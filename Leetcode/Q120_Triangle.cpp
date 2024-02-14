#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Leetcode Q120: Triangle */
/* Given a triangle array, return the minimum path sum from top to bottom.
   For each step, you may move to an adjacent number of the row below.
   More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // Dynamic programming method
        // The shortest path to the current point is the shortest path to a certain predecessor 
        // plus the weight to this point

        int rows = triangle.size();
        vector<vector<int>> BPs;
        vector<int> row_i;
        BPs.push_back(row_i);
        BPs[0].push_back(triangle[0][0]);
        int shortestPath = triangle[0][0];

        for (int i=1; i<rows; i++) {
            BPs.push_back(row_i);
            for (int j=0; j<triangle[i].size(); j++) {
                // Check if jth element in ith row is a leftmost or rightmost element
                if (j == 0) {
                    BPs[i].push_back(BPs[i-1][0] + triangle[i][j]);
                }
                else if (j == triangle[i].size()-1) {
                    BPs[i].push_back(BPs[i-1][triangle[i-1].size()-1] + triangle[i][j]);
                }
                else {
                    BPs[i].push_back(min(BPs[i-1][j-1] + triangle[i][j], BPs[i-1][j] + triangle[i][j]));
                }
                //cout << "BPs[" << i << "][" << j << "]: " << BPs[i][j] << endl;

                // If it is in the last row, we update the current shortest path
                if (i == rows - 1) {
                    if (j == 0 || BPs[i][j] < shortestPath) {
                        shortestPath = BPs[i][j];
                    }
                }
                
            }
        }
        return shortestPath;
    }
};

int main(){
    Solution s;
    vector<vector<int>> triangle1;
    vector<int> row_i;
    //    2
    //   3 4
    //  6 5 7
    // 4 1 8 3
    triangle1.push_back(row_i);
    triangle1[0].push_back(2);
    triangle1.push_back(row_i);
    triangle1[1].push_back(3);
    triangle1[1].push_back(4);
    triangle1.push_back(row_i);
    triangle1[2].push_back(6);
    triangle1[2].push_back(5);
    triangle1[2].push_back(7);
    triangle1.push_back(row_i);
    triangle1[3].push_back(4);
    triangle1[3].push_back(1);
    triangle1[3].push_back(8);
    triangle1[3].push_back(3);

    int result1 = s.minimumTotal(triangle1);
    cout << result1 << endl;

    vector<vector<int>> triangle2;
    triangle2.push_back(row_i);
    triangle2[0].push_back(-10);

    int result2 = s.minimumTotal(triangle2);
    cout << result2 << endl;
}