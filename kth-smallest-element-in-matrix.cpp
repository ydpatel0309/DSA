#include <iostream>
#include <vector>

using namespace std;

int countLessEqual(const vector<vector<int>>& matrix, int target) {
    int count = 0;
    int n = matrix.size();
    int i = n - 1, j = 0;

    while (i >= 0 && j < n) {
        if (matrix[i][j] <= target) {
            count += (i + 1);
            j++;
        } else {
            i--;
        }
    }

    return count;
}

int kthSmallest(const vector<vector<int>>& matrix, int k) {
    int n = matrix.size();

    int low = matrix[0][0];
    int high = matrix[n - 1][n - 1];

    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = countLessEqual(matrix, mid);

        if (count < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int k;
    cin >> k;

    int result = kthSmallest(matrix, k);
    cout << result << endl;

    return 0;
}
