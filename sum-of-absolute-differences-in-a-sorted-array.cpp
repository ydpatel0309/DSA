// You are given an integer array nums sorted in non-decreasing order.

// Build and return an integer array result with the same length as nums such that result[i] is equal to the summation of absolute differences between nums[i] and all the other elements in the array.

// In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).

 

// Example 1:

// Input: nums = [2,3,5]
// Output: [4,3,5]
// Explanation: Assuming the arrays are 0-indexed, then
// result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4,
// result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3,
// result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5.
// Example 2:

// Input: nums = [1,4,6,8,10]
// Output: [24,15,13,15,21]
 

// Constraints:

// 2 <= nums.length <= 105
// 1 <= nums[i] <= nums[i + 1] <= 104

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int>v;int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=0;
            for(int j=0;j<nums.size();j++)
            {
                sum=sum+abs(nums[i]-nums[j]);
            }
            v.push_back(sum);
        }
        return v;
    }
};

// optimal solution
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n,0);int sum=0;
         // Calculate cumulative sum from the left
       int leftSum = 0;
        for (int i = 0; i < n; ++i) {
            leftSum += nums[i];
            result[i] += (i + 1) * nums[i] - leftSum;
        }

        // Calculate cumulative sum from the right
        int rightSum = 0;
        for (int i = n - 1; i >= 0; --i) {
            rightSum += nums[i];
            result[i] += rightSum - (n - i) * nums[i];
        }

        return result;
    }
};