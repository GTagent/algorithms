        memset(hr, 0, sizeof(hr));
        memset(hc, 0, sizeof(hc));
        memset(hd, 0, sizeof(hd));
        
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(board[i][j] != '.'){
                    char c = board[i][j];
                    hr[i][c] = 1;
                    hc[j][c] = 1;
                    hd[i/3][j/3][c] = 1;
                }
            }
        }