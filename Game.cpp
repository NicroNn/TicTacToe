#include <iostream>
#include "AI.hpp"
#include "Renderer.hpp"
#include "Functions.hpp"
void draw() {
    std::cout << "Draw\n";
}

void win(int guy) {
    if (guy == 0) std::cout << "X Wins!\n";
    else std::cout << "O Wins!\n";
}

int checkWin(int guy, int **board) {
    for (int i = 0; i < 3; i++) {
        if ((board[0][i] == guy) and (board[1][i] == guy) and (board[2][i] == guy)) {
            return 1;
        }
        if ((board[i][0] == guy) and (board[i][1] == guy) and (board[i][2] == guy)) {
            return 1;
        }
    }
    if ((board[0][0] == guy) and (board[1][1] == guy) and (board[2][2] == guy)) {
        return 1;
    }
    if ((board[0][2] == guy) and (board[1][1] == guy) and (board[2][0] == guy)) {
        return 1;
    }
    return 0;
}

int *playerMove(int **board) {
    int *move = new int[2];
    std::cout << "Enter Cords {X, Y}: ";
    std::cin >> move[0] >> move[1];
    while (board[move[1] - 1][move[0] - 1] != 0) {
        std::cout << "This cell is already occupied!\n";
        std::cout << "Enter Cords {X, Y}: ";
        std::cin >> move[0] >> move[1];
    }
    while (move[0] < 0 or move[1] < 0 or move[0] > 3 or move[1] > 3) {
        std::cout << "Please enter cords in range 1 - 3\n";
        std::cout << "Enter Cords {X, Y}: ";
        std::cin >> move[0] >> move[1];
    }
    return move;
}

int game(int gameType, int boardOpts) {
    int **board = new int*[3];
    for (int i = 0; i < 3; i++) {
        board[i] = new int[3];
    }
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            board[y][x] = 0;
        }
    }
    int turns=0, guy;
    cleanCmd();
    std::cout << "Choose Side\n";
    std::cout << "1)X 2)O\n";
    std::cout << "X move first\n";
    std::cin >> guy;
    while (guy < 0 or guy > 2) {
        std::cout << "Please enter num in range 1 - 2\n";
        std::cout << "Choose Side\n";
        std::cin >> guy;
    }
    guy--;
    while (turns < 9) {
        int *move = new int[2];
        if (guy == 0 or gameType==1) {
            move = playerMove(board);
        } else {
            move = AI(turns, board);
        }
        board[move[1] - 1][move[0] - 1] = 1;
        cleanCmd();
        boardRenderer(board, boardOpts);
        turns++;
        std::cout << "\n";
        if (turns == 9){
            draw();
            return 0;
        }
        if (turns > 4) {
            if (checkWin(1, board) == 1) {
                win(0);
                return 0;
            }
        }
        if (gameType == 0){
            if (guy == 0){
                move = AI(turns, board);
            } else {
                move = playerMove(board);
            }
        } else {
            move = playerMove(board);
        }
        board[move[1] - 1][move[0] - 1] = 2;
        boardRenderer(board, boardOpts);
        std::cout << "\n";
        turns++;
        if (turns > 5) {
            if (checkWin(2, board) == 1) {
                win(1);
                return 0;
            }
        }
    }
    return 0;
}
