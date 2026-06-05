#include <iostream>
#include <vector>
using namespace std;

int diagonalSum(vector<vector<int>>& mat) {
    int n = mat.size();
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += mat[i][i];           // Main diagonal
        sum += mat[i][n - 1 - i];   // Secondary diagonal
    }

    // Remove double-counted center element
    if (n % 2 == 1) {
        sum -= mat[n / 2][n / 2];
    }

    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    cout << diagonalSum(mat) << endl;

    return 0;
}