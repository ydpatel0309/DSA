// custom order previously.

// Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

// Return any permutation of s that satisfies this property.

 

// Example 1:

// Input: order = "cba", s = "abcd"
// Output: "cbad"
// Explanation: 
// "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
// Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
// Example 2:

// Input: order = "cbafg", s = "abcd"
// Output: "cbad"
 

// Constraints:

// 1 <= order.length <= 26
// 1 <= s.length <= 200
// order and s consist of lowercase English letters.
// All the characters of order are unique.

class Solution {
public:
    map<char, int> rank;

    bool comp(char& a, char& b) {
        if (rank.count(a) && rank.count(b)) {
            return rank[a] < rank[b];
        }
        return false;
        
    }

    string customSortString(string order, string s) {
        int cur_rank = 0;
        for (int i = 0; i < order.size(); i++) {
            rank[order[i]] += cur_rank;
            cur_rank++;
        }
        // sort(s.begin(), s.end(),comp);
        sort(s.begin(), s.end(), [this](char a, char b) { return comp(a, b); });
        return s;
    }

};