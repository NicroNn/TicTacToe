#include <iostream>
int *makeMove(int y, int x, int **board) {
    int* move = new int[2] {0, 0};
    if (board[y][x] == 0) {
        move[0] = x+1;
        move[1] = y+1;
    }
    return move;
}

int *Move1(int guy, int **board) {
    int* move = new int[2] {0, 0};
    for (int i = 0; i < 3; i++) {
        for (int h = 0; h < 2; h++) {
            for (int j = h + 1; j < 3; j++) {
                if (board[i][h] == guy and board[i][j] == guy and move[0] == 0) {
                    move = makeMove(i, 3-h-j, board);
                    if (move[0] != 0) {
                        return move;
                    }
                }
                if (board[h][i] == guy and board[j][i] == guy and move[0] == 0) {
                    move = makeMove(3-h-j, i, board);
                    if (move[0] != 0) {
                        return move;
                    }
                }
                if (h != 1 and move[0]==0) {
                    if (board[h][h] == guy and board[j][j] == guy and move[0] == 0) {
                        move = makeMove(3-h-j, 3-h-j, board);
                        if (move[0] != 0) {
                            return move;
                        }
                    }
                    if (board[h][2-h] == guy and board[j][2-j] == guy and move[0]== 0) {
                        move = makeMove(3-h-j, -1+h+j, board);
                        if (move[0] != 0) {
                            return move;
                        }
                    }
                }
            }
        }
    }
    return move;
}

int *Move2(int **board) {
    int* move = new int[2] {0, 0};
    for (int i=0; i<2; i++) {
        for (int h=0; h<2; h++) {
            move = makeMove(i, i+h, board);
            if (move[0] != 0) return move;
            else {
                move = makeMove(i+h, i, board);
                if (move[0] != 0) return move;
            }
        }
    }
    return move;
}

int *Move3(int **board) {
    int* move = new int[2] {0, 0};
    for (int y=0; y<3; y+=2) {
        for (int x=0; x<3; x+=2) {
            move = makeMove(y, x, board);
            if (move[0] != 0) return move;
        }
    }
    return move;
}

int *AI(int turns, int **board) {
    int* move = new int[2] {0, 0};
    if (turns <= 1) {
        move = makeMove(1, 1, board);
        if (move[0] == 0) move = makeMove(0, 0, board);
    } else if (turns <= 3 and board[1][1] == 1 and board[2][2] == 1) {
        move = makeMove(0, 2, board);
    } else {
        move = Move1(2, board);
        if (move[0] == 0) {
            move = Move1(1, board);
        }
        if (move[0] == 0) {
            move = Move2(board);
        }
        if (move[0] == 0) {
            move = Move3(board);
        }
    }
    return move;
}
