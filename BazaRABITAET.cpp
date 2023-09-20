#include <iostream>
int pole[3][3];

void draw() {
    std::cout << "Draw";
}
void lose() {
    std::cout << "Defeated";
}
void win() {
    std::cout << "Congrats";
}
void otrisovka() {
    for (int i1 = 0; i1 < 3; i1++) {
        std::cout << pole[i1][0] << " " << pole[i1][1] << " " << pole[i1][2] << "\n";
    }
}
int IIturn(int turns) { return 0; }
int WinCondition(int x) {
    for (int i = 0; i < 3; i++) {
        if ((pole[0][i] == x) and (pole[1][i] == x) and (pole[2][i] == x)) {
            return 1;
        }
        if ((pole[i][0] == x) and (pole[i][1] == x) and (pole[i][2] == x)) {
            return 1;
        }
    }
    if ((pole[0][0] == x) and (pole[1][1] == x) and (pole[2][2] == x)) {
        return 1;
    }
    if ((pole[0][2] == x) and (pole[1][1] == x) and (pole[2][0] == x)) {
        return 1;
    }
    return 0;
}
void game(int game_status) {
    int turns;
    turns = 0;

    while (game_status == 1) {
        int x, y;
        std::cin >> x >> y;

        while ((pole[y - 1][x - 1] != 0) or (x > 3) or (y > 3)) {
            std::cout << "Error, try again";
            std::cin >> x >> y;
        }

        pole[y - 1][x - 1] = 1;

        otrisovka();
        turns++;
        if (turns > 4) {
            if (WinCondition(1) == 1) {
                win();
                game_status = 0;
            }
        }
        if (game_status == 1) {
            IIturn(turns);
            otrisovka();
            turns++;
            if (turns > 5) {
                if (WinCondition(2) == 1) {
                    lose();
                    game_status = 0;
                }
            }
        }
        if (game_status == 1) {
            if (turns == 9) {
                draw();
                game_status = 0;
            }
        }
    }
}


int main()
{   
    for (int i = 0; i < 3; i++) {
        pole[i][0] = 0;
        pole[i][1] = 0;
        pole[i][2] = 0;
    }
    game(1);
}