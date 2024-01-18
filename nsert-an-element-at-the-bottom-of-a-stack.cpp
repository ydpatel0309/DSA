// You are given a stack St of N integers and an element X. You have to insert X at the bottom of the given stack.

 

// Example 1:

// Input:
// N = 5
// X = 2
// St = {4,3,2,1,8}
// Output:
// {2,4,3,2,1,8}
// Explanation:
// After insertion of 2, the final stack will be {2,4,3,2,1,8}.
 

// Example 2:

// Input:
// N = 3
// X = 4
// St = {5,3,1}
// Output:
// {4,5,3,1}
// Explanation:
// After insertion of 4, the final stack will be {4,5,3,1}.
 

// Your Task:

// You don't need to read input or print anything. Your task is to complete the function insertAtBottom() which takes a stack St and an integer X  as inputs and returns the modified stack after insertion.

 

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)
class Solution{
public:
    stack<int> insertAtBottom(stack<int> st,int X){
        stack<int>ans;
        while(!st.empty())
        {
            int n=st.top();
            ans.push(n);
            st.pop();
        }
        
        st.push(X);
        while(!ans.empty())
        {
            int n=ans.top();
            st.push(n);
            ans.pop();
        }
        
        return st;
    }
};