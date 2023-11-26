// You are given a 0-indexed m x n integer matrix mat and an integer k. You have to cyclically right shift odd indexed rows k times and cyclically left shift even indexed rows k times.

// Return true if the initial and final matrix are exactly the same and false otherwise.

 

// Example 1:

// Input: mat = [[1,2,1,2],[5,5,5,5],[6,3,6,3]], k = 2
// Output: true
// Explanation:


// Initially, the matrix looks like the first figure. 
// Second figure represents the state of the matrix after one right and left cyclic shifts to even and odd indexed rows.
// Third figure is the final state of the matrix after two cyclic shifts which is similar to the initial matrix.
// Therefore, return true.
// Example 2:

// Input: mat = [[2,2],[2,2]], k = 3
// Output: true
// Explanation: As all the values are equal in the matrix, even after performing cyclic shifts the matrix will remain the same. Therefeore, we return true.
// Example 3:

// Input: mat = [[1,2]], k = 1
// Output: false
// Explanation: After one cyclic shift, mat = [[2,1]] which is not equal to the initial matrix. Therefore we return false.
 

// Constraints:

// 1 <= mat.length <= 25
// 1 <= mat[i].length <= 25
// 1 <= mat[i][j] <= 25
// 1 <= k <= 50

class Solution {
public:
    void rShift(vector<int>&arr,int k){
        while(k--){
            int temp = arr.back();
            for(int i=arr.size()-1;i>0;i--){
                arr[i] = arr[i-1];
            }
            arr[0] = temp;
        }
    }
    void lShift(vector<int>&arr,int k){
        while(k--){
            int temp = arr[0];
            for(int i=0;i<arr.size()-1;i++){
                arr[i] = arr[i+1];
            }
            arr.back() = temp;
        }
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>recheck = mat;
        for(int i=0;i<n;i++){
            if(i%2!=0){
                lShift(mat[i],k);
            }
            else{
                rShift(mat[i],k);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(recheck[i][j]!=mat[i][j])return false;
            }
        }
        return true;
        
    }
};