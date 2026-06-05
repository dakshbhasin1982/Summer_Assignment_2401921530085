#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int m = mat.size();
    int n = mat[0].size();

    if (m * n != r * c) {
        return mat;
    }

    vector<vector<int>> result(r, vector<int>(c));

    for (int i = 0; i < m * n; i++) {
        result[i / c][i % c] = mat[i / n][i % n];
    }

    return result;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    int r, c;
    cin >> r >> c;

    vector<vector<int>> ans = matrixReshape(mat, r, c);

    for (auto& row : ans) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}