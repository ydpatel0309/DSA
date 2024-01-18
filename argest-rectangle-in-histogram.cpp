// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

// Example 1:


// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
// Example 2:


// Input: heights = [2,4]
// Output: 4
 

// Constraints:

// 1 <= heights.length <= 105
// 0 <= heights[i] <= 104

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // find next smaller ad prev smaller
        int n = heights.size();
        vector<int> next(n);
        vector<int> prev(n);
        stack<int> st;
        for (int i = 0; i < n; i++) // keeping prev small elements
        {

            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                prev[i] = 0;
            } else {
                prev[i] = st.top() + 1;
            }
            st.push(i);
        }
        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--) // findinf next smaller elements
        {

            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                next[i] = n - 1;
            } else {
                next[i] = st.top() - 1;
            }
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) // finding the  max area
        {
            ans = max(ans, (next[i] - prev[i] + 1) * heights[i]);
        }
        return ans;
    }
};