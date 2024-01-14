/**
https://www.codewars.com/kata/5a4d0beffd56cb02cf000108

*/

void compute_number_mines(char **board, const int rows, const int cols)
{
    constexpr char bomb = 'o'; 
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j ++){
            if (board[i][j] == 'R'){
                char count = 0; // max 8 bombs around               
                if (i > 0 && j > 0) count += (board[i-1][j-1]==bomb)?1:0;
                if (i > 0) count += (board[i-1][j]==bomb)?1:0;
                if (i > 0 && j < cols - 1) count += (board[i-1][j+1]==bomb)?1:0;
                if (j > 0 ) count += (board[i][j-1]==bomb)?1:0;
                if (j < cols - 1 ) count += (board[i][j+1]==bomb)?1:0;
                if ( i < rows-1 && j > 0 ) count += (board[i+1][j-1]==bomb)?1:0;
                if ( i < rows-1 ) count += (board[i+1][j]==bomb)?1:0;
                if ( i < rows-1 && j < cols - 1) count += (board[i+1][j+1]==bomb)?1:0;
                board[i][j] = count + '0'; 
            }
        }
    }
}
