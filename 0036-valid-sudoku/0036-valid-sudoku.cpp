class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rowc[9][9]={false};
        bool colc[9][9]={false};
        bool gridc[9][9]={false};

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    int numc=board[i][j]-'1';
                    int r=(i/3);
                    int c=(j/3);
                    int expgrid=r*3+c;

                    if(rowc[i][numc]||colc[j][numc]||gridc[expgrid][numc])
                    {
                        return false;
                    }

                    rowc[i][numc]=colc[j][numc]=gridc[expgrid][numc]=true;

                }
            }
        }
        return true;

        
    }
};