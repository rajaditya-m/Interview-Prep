class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        std::vector<int> mapper(9,0);
        //Validate row
        for(int r=0;r<9;r++)
        {
            mapper.assign(9,0);
            for(int c=0;c<9;c++)
            {
                if(board[r][c]=='.')
                    continue;
                if(!mapper[board[r][c]-'0'-1])
                    mapper[board[r][c]-'0'-1]=1;
                else
                    return false;
            }
        }
        //validate columns
        for(int c=0;c<9;c++)
        {
            mapper.assign(9,0);
            for(int r=0;r<9;r++)
            {
                if(board[r][c]=='.')
                    continue;
                if(!mapper[board[r][c]-'0'-1])
                    mapper[board[r][c]-'0'-1]=1;
                else
                    return false;
            }
        }
        //validate subboxes
        for(int ior=0;ior<3;ior++)
        {
            for(int oc=0;oc<3;oc++)
            {
                mapper.assign(9,0);
                int rs = 3*ior; int cs = 3*oc;
                for(int r=0;r<3;r++)
                {
                    for(int c=0;c<3;c++)
                    {
                        if(board[rs+r][cs+c]=='.')
                            continue;
                        if(!mapper[board[rs+r][cs+c]-'0'-1])
                            mapper[board[rs+r][cs+c]-'0'-1]=1;
                        else
                            return false;
                    }
                }
            }
        }
        return true;
    }
};