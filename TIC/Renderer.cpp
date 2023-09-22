#include <iostream>
std::string options[4][3] = {
    {"╭───┬───┬───╮", "┏━━━┳━━━┳━━━┓", "╔═══╦═══╦═══╗"},
    {"├───┼───┼───┤", "┣━━━╋━━━╋━━━┫", "╠═══╬═══╬═══╣"},
    {"╰───┴───┴───╯", "┗━━━┻━━━┻━━━┛", "╚═══╩═══╩═══╝"},
    {"│", "┃", "║"}
};

//X O
//╭ ╮ ╰ ╯ ├ ┤ ┬ ┴ ┼ │ ─
//┏ ┓ ┗ ┛ ┣ ┫ ┳ ┻ ╋ ┃ ━
//╔ ╗ ╚ ╝ ╠ ╣ ╩ ╩ ╬ ║ ═
//
//╭───┬───┬───╮   ┏━━━┳━━━┳━━━┓   ╔═══╦═══╦═══╗
//│   │   │   │   ┃   ┃   ┃   ┃   ║   ║   ║   ║
//├───┼───┼───┤   ┣━━━╋━━━╋━━━┫   ╠═══╬═══╬═══╣
//│   │   │   │   ┃   ┃   ┃   ┃   ║   ║   ║   ║
//├───┼───┼───┤   ┣━━━╋━━━╋━━━┫   ╠═══╬═══╬═══╣
//│   │   │   │   ┃   ┃   ┃   ┃   ║   ║   ║   ║
//╰───┴───┴───╯   ┗━━━┻━━━┻━━━┛   ╚═══╩═══╩═══╝

void boardRenderer(int **board, int boardOpts) {
    std::cout << options[0][boardOpts] << "\n";
    for (int y=0; y<3; y++) {
        std::cout << options[3][boardOpts];
        for(int x=0; x<3; x++){
            if (board[y][x]==0) std::cout << "   " << options[3][boardOpts];
            else if (board[y][x]==1) std::cout<< " X " << options[3][boardOpts];
            else std::cout << " O " << options[3][boardOpts];
        }
        std::cout << "\n";
        if (y<2) std::cout << options[1][boardOpts] << "\n";
    }
    std::cout << options[2][boardOpts];
}
