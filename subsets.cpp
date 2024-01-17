// Given an integer array nums of unique elements, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.
class Solution {
public:
void calc_subsets(vector<int>& nums,vector<vector<int>>& ans,vector<int>& subset,int index)
{
    ans.push_back(subset);

    for(int i=index;i<nums.size();i++)
    {
        subset.push_back(nums[i]);
        calc_subsets(nums,ans,subset,i+1);
        subset.pop_back();
    }
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subset;
        vector<vector<int>>ans;
        calc_subsets(nums,ans,subset,0);
        return ans;
    }
};