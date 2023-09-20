﻿#include <iostream>
int pole[3][3];
int check(int guy) {
    int success = 0;
    for (int i = 0; i < 3; i++) {
        for (int h = 0; h < 2; h++) {
            for (int j = h + 1; j < 3; j++) {
                if (pole[i][h] == guy and pole[i][j] == guy) {
                    if (h == 0 and j == 1) {
                        if (pole[i][2] == 0) {
                            pole[i][2] = 2;
                            success = 1;
                            break;
                            break;
                            break;
                        }
                        else if (h == 0 and j == 2) {
                            if (pole[i][1] == 0) {
                                pole[i][1] = 2;
                                success = 1;
                                break;
                                break;
                                break;
                            }
                        }
                        else {
                            if (pole[i][0] == 0) {
                                pole[i][0] = 2;
                                success = 1;
                                break;
                                break;
                                break;
                            }
                        }
                    }
                    else if (pole[h][i] == guy and pole[j][i] == guy) {
                        if (h == 0 and j == 1) {
                            if (pole[2][i] == 0) {
                                pole[2][i] = 2;
                                success = 1;
                                break;
                                break;
                                break;
                            }
                        }
                        else if (h == 0 and j == 2) {
                            if (pole[1][i] == 0) {
                                pole[1][i] = 2;
                                success = 1;
                                break;
                                break;
                                break;
                            }
                        }
                        else if (h == 1 and j == 2) {
                            if (pole[0][i] == 0) {
                                pole[0][i] = 2;
                                success = 1;
                                break;
                                break;
                                break;
                            }
                        }
                        else if (i != 1) {
                            if (pole[i][i] == guy and pole[abs(i - j)][abs(i - j)] == guy) {
                                if (h == 0 and j == 1) {
                                    if (pole[2][2] == 0) {
                                        pole[2][2] = 2;
                                        success = 1;
                                        break;
                                        break;
                                        break;
                                    }
                                }
                                else if (h == 0 and j == 2) {
                                    if (pole[1][1] == 0) {
                                        pole[1][1] = 2;
                                        success = 1;
                                        break;
                                        break;
                                        break;
                                    }
                                }
                                else {
                                    if (pole[0][0] == 0) {
                                        pole[0][0] = 2;
                                        success = 1;
                                        break;
                                        break;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return success;
}

void IIturn(int turns) {
    int status = 0;
    if (turns == 1) {
        if (pole[1][1] == 0) {
            pole[1][1] = 2;
        }
        else {
            pole[0][0] = 2;
        }
    }
    else {
        status = check(1);
        if (status == 0) {
            status = check(2);
        }
        if (status == 0) {
            if (pole[0][1] == 0) {
                pole[0][1] = 2;
            }
            else if (pole[1][0] == 0) {
                pole[1][0] = 2;
            }
            else if (pole[1][2] == 0) {
                pole[1][2] = 2;
            }
            else if (pole[2][1] == 0) {
                pole[2][1] = 2;
            }
        }
    }
    turns++;
}

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
        std::cout << "\n";
        if (turns > 4) {
            if (WinCondition(1) == 1) {
                win();
                game_status = 0;
            }
        }
        if (game_status == 1) {
            IIturn(turns);
            otrisovka();
            std::cout << "\n";
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