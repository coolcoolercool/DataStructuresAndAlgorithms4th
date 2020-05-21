/** 
 * author: zzw5005
 * date: 2020/1/5 15:03
*/


/**
 * 八皇后问题解决
 * 如果皇后置于一个方块中，这一方块，以及方块的所在整个行，列，斜线都是皇后的领域，两个皇后的领域不能有交集
 */
#include <iostream>

class ChessBoard{
public:
    ChessBoard();   //- 默认情况是 8 * 8的棋盘
    ChessBoard(int);   //- 可以指定 n * n的棋盘

    void findSolutions();

private:
    const bool available;   //- 是否可以放置Queue
    const int squares, norm;   //- 方格  规格   norm是为了row - col越界，加的一个数
    bool *column, *leftDiagonal, *rightDiagonal;  //- 左对角线，右对角线

    int *positionInRow, howMany;
    void putQueue(int);

    void printBoard(std::ostream&);
    void initializeBoard();
};

ChessBoard::ChessBoard() : available(true), squares(8), norm(squares - 1){
    initializeBoard();
};


ChessBoard::ChessBoard(int n) : available(true), squares(n), norm(squares - 1){
    initializeBoard();
}

/**
 * 初始化棋盘
 */
void ChessBoard::initializeBoard(){
    register int i;
    column = new bool[squares];
    positionInRow = new int[squares];
    leftDiagonal = new bool[squares * 2 - 1];   //- 左对角线
    rightDiagonal = new bool[squares * 2 - 1];  //- 右对角线

    for(i = 0; i < squares; i++){
        positionInRow[i] = -1;
    }

    for(i = 0; i < squares; i++){
        column[i] = available;
    }

    for(i = 0; i < squares * 2 - 1; i++){
        leftDiagonal[i] = rightDiagonal[i] = available;
    }

    howMany = 0;
}

void ChessBoard::putQueue(int row){
    for(int col = 0; col < squares; col++){
        if(column[col] == available && leftDiagonal[row + col] == available &&
             rightDiagonal[row - col + norm] == available){
            positionInRow[row] = col;
            column[col] = !available;
            leftDiagonal[row + col] = !available;

            rightDiagonal[row - col + norm] = !available;

            if(row < squares - 1){
                putQueue(row + 1);
            }else{
                //-printBoard(std::cout);
            }

            //- 为了回溯，重置之前的路径
            column[col] = available;
            leftDiagonal[row + col] = available;
            rightDiagonal[row - col + norm] = available;
        }
    }
}

void ChessBoard::findSolutions(){
    putQueue(0);
    std::cout << howMany << " Solutions found.\n";
}














