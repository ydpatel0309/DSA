// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
 

// Constraints:

// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //keep product from start and another array from end multiply both
        int n=nums.size();
        vector<int>left(n);
        left[0]=1;
        vector<int>right(n);
        right[n-1]=1;
        int product =1;
        for(int i=1;i<n;i++)
        {
            product*=nums[i-1];
            left[i]=product;
        }
        // return left;

        product =1;
        for(int j=n-2;j>=0;j--)
        {
            product*=nums[j+1];
            right[j]=product;
        }
        // return right;

        
        for(int i=0;i<n;i++)
        {
            nums[i]=left[i]*right[i];
        }
        return nums;


    }
};