class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> row(matrix.size());
        vector<bool> col(matrix.size());

        int n = static_cast<int>(matrix.size());
        int m = static_cast<int>(matrix[0].size());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (row[i] == true || col[j] == true) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};