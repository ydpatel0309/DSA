// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Example 2:


// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
    int n=a.size();
    int m =a[0].size();
    vector<int>row(n,0);
    vector<int>col(m,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==0)
            {
                row[i]=1;
                col[j]=1;
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if((row[i] || col[j])==1)
            {
                a[i][j]=0;
                
            }
        }
    }       
    }
};

//optimal solution
class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();

        bool firstRow = false;
        bool firstCol = false;

        for(int i = 0; i < n; i++) {//first col if any zero is there 
            if(a[i][0] == 0) {
                firstCol = true;
                break;
            }
        }

        for(int j = 0; j < m; j++) {//first row id any zero is there
            if(a[0][j] == 0) {
                firstRow = true;
                break;
            }
        }

        for(int i = 1; i < n; i++) {//marking in row and col acc to other elements if zero than corresponence zero
            for(int j = 1; j < m; j++) {
                if(a[i][j] == 0) {
                    a[i][0] = 0;
                    a[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < n; i++) {//now if row have zero than entire row is zero
            if(a[i][0] == 0) {
                for(int j = 1; j < m; j++) {
                    a[i][j] = 0;
                }
            }
        }

        for(int j = 1; j < m; j++) {//now if col have zero than entire col is zero
            if(a[0][j] == 0) {
                for(int i = 1; i < n; i++) {
                    a[i][j] = 0;
                }
            }
        }

        if(firstRow) {//if first row is true than marke whole row zero
            for(int j = 0; j < m; j++) {
                a[0][j] = 0;
            }
        }

        if(firstCol) {//if first col is zero than mark while col zero
            for(int i = 0; i < n; i++) {
                a[i][0] = 0;
            }
        }
    }
};
