#include <iostream>

int pole[3][3];

int draw() {}
int lose() {}
int win() {}
int IIturn(int turns) {}
bool WinCondition(x) {
    for (int ix = 0; ix < 3; ix++) {
        if ((pole[0][ix] == x) and (pole[1][ix] == x) and (pole[2][ix] == x)) {
            return True;
        }
    }
    for (int iy = 0; iy < 3; iy++) {
        if ((pole[iy][0] == x) and (pole[iy][1] == x) and (pole[iy][2] == x)) {
            return True;
        }
    }
    if ((pole[0][0] == x) and (pole[1][1] == x) and (pole[2][2] == x)) {
        return True;
    }
    if ((pole[0][2] == x) and (pole[1][1] == x) and (pole[2][0] == x)) {
        return True;
    }
    return False;
}
void game(int game_status) {
    int turns;
    turns = 0;

    while (game_status == 1) {
        int x, y,turns = 0;
        std::cin >> x >> y;

        while (pole[y - 1][x - 1] != 0) {
            std::cout << "Zanyatoe mesto, Vvedite snova";
            std::cin >> x >> y;
        }

        pole[y - 1][x - 1] = 1;
        turns++;
        if (turns > 4) {
            if WinCondition(1) {
                win();
                game_status = 0;
            }
        }
        if (game_status == 1) {
            IIturn(turns);
            turns++;
            if (turns > 5) {
                if WinCondition(2) {
                    lose();
                    game_status = 0;
                }
            }
            if (turns == 9) {
                draw();
                game_status = 0;
            }
        }
        }
    }

int main()
    {
    std::fill(pole[0][0], pole[2][2], 0);
    int game_status = 1;
    game(1);
}   