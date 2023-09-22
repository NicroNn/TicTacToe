#include <iostream>
#include "Game.hpp"
#include "Functions.hpp"
#include "Selectable.hpp"
#if (_WIN32 || _WIN64)
    #include <Windows.h>
#endif

int menu(int boardOpts) {
    int com;
    char tmp;
    cleanCmd();
    std::cout << "Single Player (1)\n";
    std::cout << "Two Players (2)\n";
    std::cout << "Options (3)\n";
    std::cout << "Exit (4)\n";
    std::cin >> com;
    if (com==1) {
        game(0, boardOpts);
        std::cout << "Enter any character";
        std::cin >> tmp;
    } else if (com==2) {
        game(1, boardOpts);
        std::cout << "Enter any character";
        std::cin >> tmp;
    } else if (com==3) {
        boardOpts = options(boardOpts);
    } else if (com==4) {
        return -1;
    }
    return boardOpts;
}

int main() {
    #if (_WIN32 || _WIN64)
        SetConsoleOutputCP(CP_UTF8);
    #endif
    int boardOpts = 0;
    while (boardOpts != -1){
        boardOpts = menu(boardOpts);
    }
    return 0;
}
