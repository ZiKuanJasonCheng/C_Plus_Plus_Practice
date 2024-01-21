# include <iostream>
# include <vector>
using namespace std;

/* Leetcode Q14: Longest Common Prefix */
/* Write a function to find the longest common prefix string amongst an array of strings.
   If there is no common prefix, return an empty string "".
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string LCP = "";
        int j = 0;
        int N = strs.size();
        if (N == 1) {
            return strs[0];
        }
        int count = 1;
        // We compare all jth elements one another, and then j+1 th elements, and so on
        while (1) {
            int i = 0;
            while (i < N-1) {
                if (j >= strs[i].size() || j >= strs[i+1].size()) {
                    return LCP;
                }
                if (strs[i][j] == strs[i+1][j]){
                    count++;
                    i++;
                }
                else {
                    return LCP;
                }

                if (count == N) {
                    LCP += strs[i][j];
                    count = 1;
                }
            }
            j++;
        }
    }
};

int main() {
    vector<string> case1{"flower", "flow", "flight"};
    vector<string> case2{"dog", "racecar", "car"};
    vector<string> case3{""};
    vector<string> case4{"word"};

    Solution *solution;
    string result1 = solution -> longestCommonPrefix(case1);
    cout << result1 << endl;
    string result2 = solution -> longestCommonPrefix(case2);
    cout << result2 << endl;
    string result3 = solution -> longestCommonPrefix(case3);
    cout << result3 << endl;
    string result4 = solution -> longestCommonPrefix(case4);
    cout << result4 << endl;
}