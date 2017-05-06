class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> rowVector;
        rowVector.push_back(0);
        rowVector.push_back(1);
        rowVector.push_back(0);
        for(int i=0;i<rowIndex;i++)
        {
            std::vector<int>::iterator it;
			std::vector<int> currentRow ;
			currentRow.push_back(0);
            for(it = rowVector.begin()+1;it !=rowVector.end();++it)
            {
                currentRow.push_back((*it)+(*(it-1)));
            }
			currentRow.push_back(0);
			rowVector = currentRow;
        }
		rowVector.erase(rowVector.begin());
		rowVector.erase(rowVector.end()-1);
		return rowVector;
    }
};