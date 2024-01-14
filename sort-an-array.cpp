
// Code
// 912. Sort an Array
// Solved
// Medium
// Topics
// Companies
// Given an array of integers nums, sort the array in ascending order and return it.

// You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

// Example 1:

// Input: nums = [5,2,3,1]
// Output: [1,2,3,5]
// Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
// Example 2:

// Input: nums = [5,1,1,2,0,0]
// Output: [0,0,1,1,2,5]
// Explanation: Note that the values of nums are not necessairly unique.
 

// Constraints:

// 1 <= nums.length <= 5 * 104
// -5 * 104 <= nums[i] <= 5 * 104

class Solution {
public:
    void mrg(vector<int>&nums,int start,int mid,int end)
    {
        int i,j,k;
        int n1=mid-start+1;//size of the first array
        int n2=end-mid;//size of the second array

        vector<int>left(n1);
        vector<int>right(n2);

        for(i=0;i<n1;i++)
        {
            left[i]=nums[start+i];

        }
        for(j=0;j<n2;j++)
        {
            right[j]=nums[mid+1+j];

        }
        i=0,j=0,k=start;

        while(i<n1 && j<n2)
        {
            if(left[i]<right[j])
            {
                nums[k]=left[i];
                i++;
            }
            else
            {
                nums[k]=right[j];
                j++;
            }
            k++;
        }
        while(i<n1)
        {
            nums[k]=left[i];
            i++;
            k++;
        }
        while(j<n2)
        {
            nums[k]=right[j];
            j++;
            k++;
        }

    }
    void mergeSort(vector<int>& nums,int start,int end)
    {
       if(start>=end) return;
       int mid=(start+end)/2;
            mergeSort(nums,start,mid);
            mergeSort(nums,mid+1,end);
            mrg(nums,start,mid,end);

    }
    vector<int> sortArray(vector<int>& nums) {
        int start=0,end=nums.size()-1;
        mergeSort(nums,start,end);
        return nums;
    }
};