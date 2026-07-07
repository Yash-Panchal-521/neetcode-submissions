class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        vector<set<char>> check_row(rows);
        vector<set<char>> check_cols(cols);
        map<pair<int, int>, set<char>> check_box;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                char ch = board[i][j];
                if(ch == '.') {
                    continue;
                }

                if (check_row[i].contains(ch) || check_cols[j].contains(ch) ||
                    check_box[make_pair(i/3, j/3)].contains(ch)) {
                    return false;
                } 
                check_row[i].insert(ch);
                check_cols[j].insert(ch);
                check_box[make_pair(i/3,j/3)].insert(ch);
            }
        }

        return true;
    }
};
