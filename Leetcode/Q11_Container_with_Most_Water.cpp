# include <iostream>
# include <vector>
using namespace std;

/* Leetcode Q11: Container With Most Water */
/* You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
   Find two lines that together with the x-axis form a container, such that the container contains the most water.
   Return the maximum amount of water a container can store.
   Notice that you may not slant the container.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        int start=0, end=N-1;

        // Initialize current maximum amount of water
        int maxAmt = (height[0] <= height[N-1])? height[0]*(N-1): height[N-1]*(N-1);
        // Temp height
        int tmp_h = 0;

        // Let i to be a temp endpoint (could be right endpoint or left endpoint)
        for (int i=1; i<N; i++) {
            // Let j to be a temp right endpoint
            int j = N-1;

            // We assume i is an endpoint of the container. 
            // We then calculate upper bound of amount from i to j with height[i], 
            // and compare if the upper bound of amount is still less than maxAmt,
            // then i is impossible to be an endpoint
            while (i != j && height[i]*(j-i) > maxAmt) {
                tmp_h = (height[i] <= height[j])? height[i]: height[j];
                // We then calculate actual amount from i to j with tmp_h, which is the minimum of height[i] and height[j],
                // and compare if the actual amount is still larger than maxAmt, we should update maxAmt
                // and new endpoints.
                if (tmp_h*(j-i) > maxAmt) {
                    start = i;
                    end = j;
                    maxAmt = tmp_h*(j-i);
                    break;
                }
                else {
                    // We left-shift right endpoint and continue from while loop
                    j--;
                }
            }

            // Let k to be a temp left endpoint
            int k = 0;
            // We assume i is an endpoint of the container.
            // We then calculate upper bound of amount from k to i with height[i], 
            // and compare if the upper bound of amount is still less than maxAmt,
            // then i is impossible to be an endpoint
            while (i != k && height[i]*(i-k) > maxAmt) {
                tmp_h = (height[i] <= height[k])? height[i]: height[k];
                // We then calculate actual amount from k to i with tmp_h, which is the minimum of height[k] and height[i],
                // and compare if the actual amount is still larger than maxAmt, we should update maxAmt
                // and new endpoints.
                if (tmp_h*(i-k) > maxAmt) {
                    start = k;
                    end = i;
                    maxAmt = tmp_h*(i-k);
                    break;
                }
                else {
                    // We right-shift left endpoint and continue from while loop
                    k++;
                }
            }
        }
        return maxAmt;
    }
};


int main() {
    vector<int> heights1{1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> heights2{1, 1};
    vector<int> heights3{2, 3, 10, 5, 7, 8, 9};

    Solution *solution;
    int result1 = solution -> maxArea(heights1);
    cout << result1 << endl;
    int result2 = solution -> maxArea(heights2);
    cout << result2 << endl;
    int result3 = solution -> maxArea(heights3);
    cout << result3 << endl;
}