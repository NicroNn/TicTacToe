#include <iostream>
#include "Functions.hpp"
#include "Renderer.hpp"
int options(int boardOpts) {
    cleanCmd();
    int **board = new int*[3];
    for (int i = 0; i < 3; i++) {
        board[i] = new int[3];
    }
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            board[y][x] = 0;
        }
    }
    for (int i = 0; i<3; i++){
        std::cout << i+1 << ")";
        if (i == boardOpts){
            std::cout << "❎";
        }
        std::cout << "\n";
        boardRenderer(board, i);
        std::cout << "\n";
    }
    std::cout << "Enter Num of board: ";
    std::cin >> boardOpts;
    boardOpts--;
    while (boardOpts < 0 or boardOpts > 3) {
        std::cout << "Please enter num in range 1 - 3\n";
        std::cout << "Enter Num of board: ";
        std::cin >> boardOpts;
        boardOpts--;
    }
    return boardOpts;
}
