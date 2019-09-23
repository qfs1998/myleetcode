/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */
class Solution {
public:
    int totalNQueens(int n) {
        this->n=n;
        col=vector<bool>(n,true);
        diag_1=vector<bool>(2*n-1,true);
        diag_2=vector<bool>(2*n-1,true);

        dfs(0);
        return total_count;
    }
    int total_count;

private:
    //vector<string>board;
    int n;
    vector<bool>col;
    vector<bool>diag_1;
    vector<bool>diag_2;
    bool available(int x,int y)
    {
        return col[y]&&diag_1[x-y+n-1]&&diag_2[x+y];
    }

    void updateBoard(int x,int y,bool can_be_put)
    {
        col[y]=can_be_put;
        diag_1[x-y+n-1]=can_be_put;
        diag_2[x+y]=can_be_put;
        return;
    }

    //put Q in every row
    void dfs(int x)
    {
        if(x==n)
            ++total_count;
        
        for(int y=0;y<n;++y)
        {
            if(!available(x,y))
                continue;
            //put Q and some places can be put Q 
            //because (x,y) has been put
            updateBoard(x,y,false);
            //next row
            dfs(x+1);
            //reset the status
            updateBoard(x,y,true);
        }
        return;
    }
};

