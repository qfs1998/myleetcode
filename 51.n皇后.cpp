/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n=n;
        sols.clear();
        col=vector<bool>(n,true);
        diag_1=vector<bool>(2*n-1,true);
        diag_2=vector<bool>(2*n-1,true);
        board=vector<string>(n,string(n,'.'));
        dfs(0);
        return sols;
    }
private:
    int n;
    vector<string>board;
    //default is true means you can put Q
    vector<bool>col;
    vector<bool>diag_1;
    vector<bool>diag_2;
    vector <vector<string>> sols;

    bool available(int x,int y)
    {
        return col[y]&&diag_1[x-y+n-1]&&diag_2[x+y];
    }

    void updateBoard(int x,int y,bool can_be_put)
    {
        col[y]=can_be_put;
        diag_1[x-y+n-1]=can_be_put;
        diag_2[x+y]=can_be_put;
        board[x][y]=!can_be_put?'Q':'.';
        return;
    }


    //put Q in every row
    void dfs(int x)
    {
        if(x==n)
            sols.push_back(board);
        
        //try every columns
        for(int y=0;y<n;++y)
        {
            //if can not put in here ,try other columns
            if(!available(x,y))
                continue;
            updateBoard(x,y,false);
            dfs(x+1);
            updateBoard(x,y,true);
        }
        return;
    }
};

