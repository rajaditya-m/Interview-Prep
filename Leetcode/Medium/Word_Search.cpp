class Solution {
public:
bool existsAug(std::vector<std::vector<char> > &board,std::string word,int lastRow, int lastCol)
{
	int row = board.size();
	int cols = board[0].size();
	int len = word.length();
	if(len==0)
		return true;
	if(lastRow==-1 && lastCol==-1)
	{
		for(int r=0;r<row;r++)
		{
			for(int c=0;c<cols;c++)
			{
				if(board[r][c]==word[0])
				{
					char lv = board[r][c];
					board[r][c] = '#';
					std::string newWord = word.substr(1);
					bool res = existsAug(board,newWord,r,c);
					if(res)
						return true;
					else
						board[r][c] = lv;
				}
			}
		}
	}
	else
	{
		//Search in 4 possible positions
		int r = lastRow+1;
		int c = lastCol;
		if(r<row && r>=0 && c<cols && c>=0 && board[r][c]==word[0])
		{
			char lv = board[r][c];
			board[r][c] = '#';
			std::string newWord = word.substr(1);
			bool res = existsAug(board,newWord,r,c);
			if(res)
				return true;
			else
				board[r][c] = lv;
		}

		r = lastRow-1;
		c = lastCol;
		if(r<row && r>=0 && c<cols && c>=0 && board[r][c]==word[0])
		{
			char lv = board[r][c];
			board[r][c] = '#';
			std::string newWord = word.substr(1);
			bool res = existsAug(board,newWord,r,c);
			if(res)
				return true;
			else
				board[r][c] = lv;
		}

		r = lastRow;
		c = lastCol+1;
		if(r<row && r>=0 && c<cols && c>=0 && board[r][c]==word[0])
		{
			char lv = board[r][c];
			board[r][c] = '#';
			std::string newWord = word.substr(1);
			bool res = existsAug(board,newWord,r,c);
			if(res)
				return true;
			else
				board[r][c] = lv;
		}

		r = lastRow;
		c = lastCol-1;
		if(r<row && r>=0 && c<cols && c>=0 && board[r][c]==word[0])
		{
			char lv = board[r][c];
			board[r][c] = '#';
			std::string newWord = word.substr(1);
			bool res = existsAug(board,newWord,r,c);
			if(res)
				return true;
			else
				board[r][c] = lv;
		}
	}
	return false;
}

bool exist(std::vector<std::vector<char> > &board, std::string word) 
{
	return existsAug(board,word,-1,-1);        
}
};