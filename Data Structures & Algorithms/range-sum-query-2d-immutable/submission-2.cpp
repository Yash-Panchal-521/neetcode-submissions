class NumMatrix {
   public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        prefix = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prefix[i + 1][j + 1] =
                    matrix[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];
            }
        }
    }

    int sumRegion(int r1, int c1, int r2, int c2) { 
        return prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1]; 
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */