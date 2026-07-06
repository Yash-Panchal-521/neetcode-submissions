class NumMatrix {
public:
    vector<vector<int>> m;
    vector<vector<int>> prefix;

    NumMatrix(vector<vector<int>>& matrix) {
        for(auto row: matrix) {
            int cummulative = 0;
            vector<int> nr;
            vector<int> cr;
            for(auto num: row) {
                cummulative += num;
                nr.push_back(num);
                cr.push_back(cummulative);
            }
            m.push_back(nr);
            prefix.push_back(cr);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++) {
            sum += prefix[i][col2];
            if(col1 != 0) {
                sum -= prefix[i][col1-1];
            }
        }
        return sum;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */