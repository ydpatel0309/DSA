// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.

 

// Example 1:

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:

// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

// Constraints:

// 1 <= s.length <= 1000
// s consists of lowercase English letters.

class Solution {
public:

    bool isPalindrom(string ss)
    {
        int n=ss.size();
        for(int i=0;i<n/2;i++)
        {
            if(ss[i]!=ss[n-i-1])
            {
                return false;
            }
        }
        return true;
    }

    int countSubstrings(string s) {
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                string substring=s.substr(i,j-i+1);
                if(isPalindrom(substring))
                {
                    // cout<<substring<<" ";
                    count++;
                }
            }
        }   
        return count;
    }
};