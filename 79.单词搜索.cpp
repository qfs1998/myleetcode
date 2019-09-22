// /*
//  * @lc app=leetcode.cn id=79 lang=cpp
//  *
//  * [79] 单词搜索
//  */
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty() || board[0].empty() || !word.size())
        {
            return false;
        }
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                vector<vector<bool>> visited(m, vector<bool>(n, false));

                if (dfs(
                        board,
                        i,
                        j,
                        word,
                        visited,
                        0))
                    return true;
            }
        return false;
    }

private:
    bool dfs(const vector<vector<char>> &board,
             int row,
             int col,
             const string &word,
             vector<vector<bool>> &visited,
             int index)
    {
        if (index == word.size())
            return true;
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || visited[row][col] == true || board[row][col] != word[index])
            return false;
        // //has visited
        // if (visited[row][col] == true)
        //     return false;
        // //never visited
        // if (board[row][col] != word[index])
        //     return false;

        visited[row][col] = true;
        //++index;
        bool res= (dfs(board, row - 1, col, word, visited, index + 1) || dfs(board, row, col + 1, word, visited, index + 1) || dfs(board, row + 1, col, word, visited, index + 1) || dfs(board, row, col - 1, word, visited, index + 1));


        //reset the status
        visited[row][col] = false;
        return res;
    }
};
// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         if(board.empty() || board[0].empty())
//         {
//             return false;
//         }
//         int m = board.size(), n = board[0].size();
//        vector<vector<bool> > visited(m,vector<bool>(n, false));
//         for(int i = 0;  i < m; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
//                 if(backtrace(board, word, 0, i, j, visited))
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
//     bool backtrace(vector<vector<char> > &board, string &word, int index, int i, int j, vector<vector<bool> > &visited)
//     {
//         if(index == word.size())
//         {
//             return true;
//         }
//         if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index] || visited[i][j])
//         {
//             return false;
//         }
//         visited[i][j] = true;
//         bool res = (backtrace(board, word, index + 1, i + 1, j, visited)
//                    || backtrace(board, word, index + 1, i - 1, j, visited)
//                    || backtrace(board, word, index + 1, i, j - 1, visited)
//                    || backtrace(board, word, index + 1, i, j + 1, visited)
//                     );
//         visited[i][j] = false;
//         return res;
//     }
// };