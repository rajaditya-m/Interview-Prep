void setZeroes(std::vector<std::vector<int> > &matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    int storageRow = -1;
    int storageCol = -1;
    bool foundFirst = false;
    for(int r=0;r<m;r++){
        for(int c=0;c<n;c++){
            if(matrix[r][c]==0) {
                storageCol = c;
                storageRow = r;
                foundFirst = true;
                break;
            }
        }
        if(foundFirst)
            break;
    }
    if(storageCol==-1 && storageRow==-1)
        return;
    if(storageRow+1<m) {
        for (int r = storageRow +1; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (c == storageCol)
                    continue;
                if(matrix[r][c]==0){
                    matrix[r][storageCol]=0;
                    matrix[storageRow][c]=0;
                }
            }
        }
    }
    for(int r=0;r<m;r++){
        if(r==storageRow)
            continue;
        if(matrix[r][storageCol]==0){
            for(int c=0;c<n;c++){
                matrix[r][c]=0;
            }
        }
    }

    for(int c=0;c<n;c++){
        if(c==storageCol)
            continue;
        if(matrix[storageRow][c]==0){
            for(int r=0;r<m;r++){
                matrix[r][c]=0;
            }
        }
    }
    for(int r=0;r<m;r++){
        matrix[r][storageCol]=0;
    }
    for(int c=0;c<n;c++){
        matrix[storageRow][c]=0;
    }

    return;

}