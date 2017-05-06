class Solution {
public:
    void gameOfLife(std::vector<std::vector<int>>& board) {
	int nRows = board.size();
	int nCols = board[0].size();
	//Preprocess 
	// O N 
	// 0 x 0
	// 0 0 1
	// 0 1 2
	// 1 x 3
	// 1 0 4
	// 1 1 5 
	for(int r=0;r<nRows;r++){
		for(int c=0;c<nCols;c++){
			if(board[r][c]==1)
				board[r][c]=3;
		}
	}
	for(int r=0;r<nRows;r++){
		for(int c=0;c<nCols;c++){
			int neighbours = 0;

			if(r-1>=0 && c-1>=0 && (board[r-1][c-1]==3||board[r-1][c-1]==4||board[r-1][c-1]==5)) neighbours++;
			if(r-1>=0 && (board[r-1][c]==3||board[r-1][c]==4||board[r-1][c]==5)) neighbours++;
			if(r-1>=0 && c+1<nCols && (board[r-1][c+1]==3||board[r-1][c+1]==4||board[r-1][c+1]==5)) neighbours++;
			if(c-1>=0 && (board[r][c-1]==3||board[r][c-1]==4||board[r][c-1]==5)) neighbours++;
			if(c+1<nCols && (board[r][c+1]==3||board[r][c+1]==4||board[r][c+1]==5)) neighbours++;
			if(r+1<nRows && c-1>=0 && (board[r+1][c-1]==3||board[r+1][c-1]==4||board[r+1][c-1]==5)) neighbours++;
			if(r+1<nRows && (board[r+1][c]==3||board[r+1][c]==4||board[r+1][c]==5)) neighbours++;
			if(r+1<nRows && c+1<nCols && (board[r+1][c+1]==3||board[r+1][c+1]==4||board[r+1][c+1]==5)) neighbours++;

			if(board[r][c]==0 && neighbours==3){
				board[r][c]=2;
			}
			else if(board[r][c]==3 && neighbours<2){
				board[r][c]=4;
			} 
			else if(board[r][c]==3 && (neighbours==2 || neighbours==3)){
				board[r][c]=5;
			}
			else if(board[r][c]==3 && neighbours>3){
				board[r][c]=4;
			}
			else {
				board[r][c]=1;
			}
		}
	}
	for(int r=0;r<nRows;r++){
		for(int c=0;c<nCols;c++){
			if(board[r][c]==1)
				board[r][c]=0;
			else if(board[r][c]==2)
				board[r][c]=1;
			else if(board[r][c]==4)
				board[r][c]=0;
			else if(board[r][c]==5)
				board[r][c]=1;
		}
	}
}
};