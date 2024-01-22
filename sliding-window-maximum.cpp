// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

 

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 1 <= k <= nums.length


//brute force approch
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<=n-k;i++)
        {
            int maxi=INT_MIN;
            for(int j=i;j<i+k;j++)
            {
                
                if(nums[j]>maxi)
                {
                    maxi=max(maxi,nums[j]);
                }
                
            }
            ans.push_back(maxi);
        }
        return ans;
        
    }

};

//optimal
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>>heap;
        int n=nums.size();

        for(int i=0;i<k;i++)//push k elements in queue
        {
            heap.push({nums[i],i});
        }

        ans.push_back(heap.top().first);
        
        for(int i=k;i<n;i++){
            heap.push({nums[i],i});

            while(heap.top().second<=i-k)
            {
                heap.pop();

            }
            ans.push_back(heap.top().first);
        }
        return ans;
    }
};