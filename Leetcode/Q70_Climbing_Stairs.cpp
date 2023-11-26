# include <iostream>
# include <vector>
using namespace std;

/* Leetcode Q70: Climbing Stairs */
/* You are climbing a staircase. It takes n steps to reach the top. Each time you can either climb 1 or 2 steps. 
   In how many distinct ways can you climb to the top? */

class Solution {
public:
    int climbStairs(int n) {
        /* Assume F(n) = y_n means there are y_n ways to climb n stairs. It will be: F(n) = F(n-1) + F(n-2), with F(1) = 1, F(2) = 2, F(3) = 3, ...,
           which is actually a Fibonacci sequence. We let n start from 0 and let F(0) = 1 for the purpose of initialization of the algorithm.
           The sequence in this case is: 1, 1, 2, 3, 5, 8, ...
           Because running F(n) = F(n-1) + F(n-2) requires time complexity of O(n^2), implementing it directly will cause execution timeout.
           Therefore, we should implement the algorithm that runs in O(n).
            */
        
        // The following method requires O(n^2) execution time, which will cause execution timeout.
        /*
        if (n == 1  || n == 0) {
            return 1;
        }
        else {
            return climbStairs(n-1) + climbStairs(n-2);
        }
        */

        // The following method requires only O(n) execution time
        vector<int> fibonacci;
        int sum = 0;
        for (int i=0; i < n+1; i++) {
            if (i==0 || i==1) {
                fibonacci.push_back(1);
            }
            else{
                fibonacci.push_back(fibonacci[i-1] + fibonacci[i-2]);
            }
        }
        return fibonacci[n];
    }
};

int main() {
    Solution *solution;
    int result;
    result = solution -> climbStairs(4);
    cout << result << endl;
    result = solution -> climbStairs(6);
    cout << result << endl;
    result = solution -> climbStairs(30);
    cout << result << endl;
    result = solution -> climbStairs(37);
    cout << result << endl;
    result = solution -> climbStairs(45);
    cout << result << endl;
    result = solution -> climbStairs(22);
    cout << result << endl;
}

        