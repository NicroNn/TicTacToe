#include <iostream>

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

// Функция для вывода поля на экран
void printBoard()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << "---------" << std::endl;
    }
    std::cout << std::endl;
}

// Функция для проверки состояния поля (победа, ничья или продолжение игры)
int checkGameState()
{
    // Проверка всех возможных выигрышных комбинаций
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||   // По горизонтали
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' '))     // По вертикали
        {
            if (board[i][0] == 'X') return 1;   // Победа игрока (X)
            else return 2;                      // Победа компьютера (O)
        }
    }

    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||       // По диагонали
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '))         
    {
        if (board[1][1] == 'X') return 1;      // Победа игрока (X)
        else return 2;                         // Победа компьютера (O)
    }

    // Проверка на ничью
    bool isTie = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                isTie = false;
                break;
            }
        }
    }
    if (isTie) return 0;

    // Продолжение игры
    return -1;
}

// Функция для хода игрока
void playerMove()
{
    int row, col;
    std::cout << "Enter your move (row column): ";
    std::cin >> row >> col;

    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        std::cout << "Invalid move! Try again." << std::endl;
        playerMove();
        return;
    }
    board[row][col] = 'X';
}

// Функция для хода компьютера
void computerMove()
{}

// Основная функция для игры
int main()
{
    int gameState = -1;   // Состояние игры

    while (gameState == -1) {
        printBoard();
        playerMove();
        gameState = checkGameState();
        if (gameState != -1) break;
        computerMove();
        gameState = checkGameState();
    }

    printBoard();

    // Вывод результатов игры
    if (gameState == 0) std::cout << "It's a tie!" << std::endl;
    else if (gameState == 1) std::cout << "Congratulations! You won!" << std::endl;
    else std::cout << "Computer wins. Try again." << std::endl;

    return 0;
}
