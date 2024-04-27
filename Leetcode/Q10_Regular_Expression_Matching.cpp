#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Leetcode Q10: Regular Expression Matching */
/* Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
   '.' Matches any single character.​​​​
   '*' Matches zero or more of the preceding element.
   The matching should cover the entire input string (not partial).
*/

/* 
Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)". 
*/

/* 
    1 <= s.length <= 20
    1 <= p.length <= 20
    s contains only lowercase English letters.
    p contains only lowercase English letters, '.', and '*'.
*/

// Referenced solution from: https://leetcode.com/problems/regular-expression-matching/solutions/3401751/detailed-explaination-with-pictures-in-c-java-python-dp-bottom-up-tabulation/

class Solution {
public:
    bool isMatch(string s, string p) {        
        int N = s.length(), M = p.length();
        bool mat[N+1][M+1];
        memset(mat, false, sizeof(mat));
        // Dynamic Programming Bottom-up method
        // mat[i][j] stores whether s[0 to i-1] matches p[0 to j-1]
        // For example, assume p="mis*i.*p*i" and s="mississippi". The matrix will be like:
        /*  y-axis represents s, while x-axis represents p

                  m  i  s  *  i  .  *  p  *  i
            ├  -  -  -  -  -  -  -  -  -  -  -
            |  1  0  0  0  0  0  0  0  0  0  0
         m  |  0  1  0  ...
         i  |  0  0  1  ...
         s  |  ...
         s  |
         i  |
         s  |
         s  |
         i  |
         p  |
         p  |
         i  |
        */

        // Set mat[0][0] to be true for initial condition
        mat[0][0] = true;
        
        for (int i=0; i<N+1; i++) {
            // For each character in s, iterate through all p
            for (int j=1; j<M+1; j++) {
                if (p[j-1] == '*') {
                    // mat[i][j-2]: Assume s[0 to i-1] matches p[0 to j-1] which is aba* or ab.*, then it must also match p[0 to j-3]: ab
                    // s[i-1] == p[j-2]: If current character of s[0 to i-1] matches previous character of p[0 to j-1]
                    // p[j-2] == '.': If previous character of p[0 to j-1] is '.'
                    // mat[i-1][j]: Make sure the previous character of s[0 to i-1] also matches p[0 to j-1]
                    mat[i][j] = mat[i][j-2] || (i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.') && mat[i-1][j]);
                }
                else {
                    // mat[i-1][j-1]: Make sure the previous substring of s match the previous substring of p, or otherwise the current pattern must not match
                    // s[i-1] == p[j-1]: If current character of s[0 to i-1] matches current character of p[0 to j-1]
                    // p[j-1] == '.': If current character of p[0 to j-1] is '.'
                    mat[i][j] = i > 0 && mat[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }

        // Both time complexity and space complexity are O(N*M)
        // We return the upper bottom element of the matrix as the final result
        return mat[N][M];
    }
};


int main(){
    Solution s;
    string str = "aabcbcbcaccbcaabc";  //"bab", "ba", "b", "a", "ab", "abcdede", "ab", "a", "aab", "ac", "mississipi", "aa", "aaa", "baabcdabcbakdef", "baabcdabc"
    string p = ".*a*aa*.*b*.c*.*a*";  //"..*", ".*.", "b.*c", "..*", ".*b*", "ab.*de", ".*c", "ab*", "c*a*b", ".*ab*c", "mis*is*ip*.", "ab*a*c*a", "a*a", "b.*abc.*ba.*def"
    bool result = s.isMatch(str, p);
    cout << "result: " << result << endl;
}