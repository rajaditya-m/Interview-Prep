class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int nosRows = matrix.size();
        int nosCols;
        if(nosRows>0)
            nosCols = matrix[0].size();
        std::vector<int> result;
        int tc=0,tr=0;
        while(tr<nosRows && tc<nosCols)
        {
            //Print top row 
                for(int i=tc;i<nosCols;i++)
                    result.push_back(matrix[tr][i]);
            //Print last col
                for(int i=tr+1;i<nosRows;i++)
                    result.push_back(matrix[i][nosCols-1]);
            //Print last row
            if(nosRows-1>tr)
                for(int i=nosCols-2;i>=tc;i--)
                    result.push_back(matrix[nosRows-1][i]);
            //Print first col
            if(nosCols-1>tc)
                for(int i=nosRows-2;i>=tr+1;i--)
                    result.push_back(matrix[i][tc]);
            //Adjust number of rows and cols 
            nosRows--;
            nosCols--;
            //adjust corner positions
            tr++; tc++;
        }
        return result;
    }
};