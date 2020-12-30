class Solution {
public:
    vector<vector<string>> ans;
    vector<string> chess;
    bool isSafe(int n, int row, int col)
    {
        //checking the row ie it contain the q or not
        for(int i=0; i<n; i++)
        {
            if(i==row) continue;
            if(chess[i][col]=='Q') return false;
        }
        //checking the column that it contain the q or not 
        for(int j=0; j<n; j++)
        {
            if(j==col) continue;
            if(chess[row][j]=='Q') return false;
        }
        //checking the upper left hand side of the board
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
        {
            if(chess[i][j]=='Q') return false;
        }
        //checking the upper rught hand side of the board
        for(int i=row+1, j=col+1; i<n && j<n; i++, j++)
        {
            if(chess[i][j]=='Q') return false;
        }
        //checking the bottom left side of the board
        for(int i=row+1, j=col-1; i<n && j>=0; i++, j--)
        {
            if(chess[i][j]=='Q') return false;
        }
        //checking the bttom right side of the board
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++)
        {
            if(chess[i][j]=='Q') return false;
        }
        return true;
    }
    bool solve(int n, int col)
    {
        if(col==n) return true;
        for(int i=0; i<n; i++)
        {
            if(isSafe(n, i, col))
            {
                chess[i][col] = 'Q';
                if(solve(n, col+1)==true)
                {
                    ans.push_back(chess);
                }
                chess[i][col] = '.';
            }
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        chess.clear();
        ans.clear();
        string t = "";
        for(int i=0; i<n; i++) t+=".";
        for(int i=0; i<n; i++) chess.push_back(t);
        if(solve(n, 0)) return ans;
        return ans;
    }
};