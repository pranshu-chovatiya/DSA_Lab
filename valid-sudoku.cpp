class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;

        for(int i = 0; i < 9; i++) {
            vector<int> hs1(10, 0), hs2(10, 0);
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                if(hs1[board[i][j] - '0'] == 0) {
                    hs1[board[i][j] - '0'] = 1;
                }
                else {
                    return false;
                }
            }
            for(int j = 0; j < 9; j++) {
                if(board[j][i] == '.') continue;
                if(hs2[board[j][i] - '0'] == 0) {
                    hs2[board[j][i] - '0'] = 1;
                }
                else {
                    return false;
                }
            }
        }

        for(int i = 0; i < 9; i += 3) {
            for(int j = 0; j < 9; j += 3) {
                vector<int> hs(n + 1, 0);
                for(int x = 0; x < 3; x++) {
                    for(int y = 0; y < 3; y++) {
                        if(board[x + i][y + j] == '.') continue;

                        if(hs[board[x + i][y + j] - '0'] == 0) {
                            hs[board[x + i][y + j] - '0'] = 1;
                        }
                        else {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
